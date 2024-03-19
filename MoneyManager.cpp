#include "MoneyManager.h"

void MoneyManager::addNewIncome(){

    Money money = getNewIncomeData();

    incomes.push_back(money);
    fileWithMoney.addIncomeToFile(money);

    cout << endl << "Dodano wplate pomyslnie" << endl << endl;
    system ("pause");
}

Money MoneyManager::getNewIncomeData(){
    double valueOfIncome = 0;
    char choice;
    string details;

    money.setId(getNewTransactionId());

    cout << "Podaj wyskosc wplaty : ";
    cin >> valueOfIncome;

    if (valueOfIncome < 0){
        cout << "Podana wartosc powinna byc wieksza od 0." << endl;
        do{
           cout << "Podaj wysokosc wplaty : ";
           cin >> valueOfIncome;
        }while(valueOfIncome <= 0);
        valueOfIncome = HelpingMethodes::correctTheNumber(valueOfIncome);
        money.setAmount(valueOfIncome);
    }else{
        valueOfIncome = HelpingMethodes::correctTheNumber(valueOfIncome);
        money.setAmount(valueOfIncome);
    }

    choice = HelpingMethodes::selectAnOptionFromTheMoneyMenu();

    switch(choice){
    case '1':
        money.setDate(getTodaysDate());
        break;
    case '2':
        money.setDate(getDateFromUser());
        break;
    default:
        cout << "Please choose option 1 or 2 and set the date for income." << endl;
        system("pause");
        break;
    }

    cout << "Dodatkowe informacje o transakcji : ";
    details = HelpingMethodes::getDataLine();
    if(money.getDetails().length() == 0){
        details = money.getDetails() +" "+ details;
    }

    money.setDetails(details);

//    cout << "ID : " << money.getId() << endl;
//    cout << "Amount : " << money.getAmount() << endl;
//    cout << "Date : " << money.getDate() << endl;
//    cout << "Details : " << money.getDetails() << endl;
//    system("pause");

    return money;
}

int MoneyManager::getNewTransactionId() {
    if (incomes.empty() == true && expenses.empty() == true){
        return 1;
    }else if (incomes.empty() == true && expenses.empty() == false){
        return expenses.back().getId() + 1;
    }else if (incomes.empty() == false && expenses.empty() == true){
        return incomes.back().getId() + 1;
    }else{
        cout << "Cos poszlo nie tak, nie nadano poprawnego Id" << endl;
        system("pause");
        return 0;
    }
}

string MoneyManager::getTodaysDate(){
    string partOfDate = "";
    int partOfDatePosition = 0;
    string dayOftheWeek = "", month = "", dayOfTheMonth = "", timeOfTheDay = "", year = "";

    time_t now = time (0);

    char* date_time = ctime (&now);

    string date = date_time;


    string FinalDateOutput = "";
    date.erase(date.end()-1);
    date += " ";

    for( int charPos = 0; charPos <= (int) date.length(); charPos++){
        if(date[charPos] != ' '){
            partOfDate += date[charPos];
        }else{
            partOfDatePosition++;
            switch (partOfDatePosition){
            case 1:
                dayOftheWeek = partOfDate;
                break;
            case 2:
                month = partOfDate;
                break;
            case 3:
                dayOfTheMonth = partOfDate;
                break;
            case 4:
                timeOfTheDay = partOfDate;
                break;
            case 5:
                year = partOfDate;
                break;
            }
            partOfDate = "";
        }
    }

    string details = dayOftheWeek +" "+ timeOfTheDay +" ";
    money.setDetails(details);

    cout << money.getDetails() << endl;

    month = changeFormOfMonth(month);

    FinalDateOutput = year +"/"+ month +"/"+ dayOfTheMonth;

    return FinalDateOutput;
}

string MoneyManager::changeFormOfMonth(string monthWord){

    vector <string> months = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    for(int i = 0; i < (int) months.size(); i++){
        if (monthWord == months[i]){
            return to_string(i+1);
        }
    }
    return monthWord;
}

string MoneyManager::getDateFromUser(){

    string year = "", month = "", day = "";

    cout << "Wpisz date przychodu lub wplaty." << endl;
    do{
        cout << "Podaj rok w formacie yyyy : ";
        cin >> year;
        cout << "Podaj miesiac w formacie mm : ";
        cin >> month;
        cout << "Podaj dzien w formacie dd : ";
        cin >> day;
        if(year.length() != 4 || month.length() != 2 || day.length() != 2){
            cout << "Podano date w zlym formacie." << endl;
            cout << "Prosze wprwadzic date jescze raz w formacie yyyy/mm/dd." << endl;
            system("pause");
        }else{
            continue;
        }
    }while (year.length() != 4 || month.length() != 2 || day.length() != 2);

    if (checkIfDateIsCorrect(year,month,day) == true){
        return year +"/"+ month +"/"+ day;
    }
    cout << "Podano zla date, nie istniejaca w kalendarzu." << endl;
    system("pause");
    return getDateFromUser();
}

bool MoneyManager::checkIfDateIsCorrect(string year, string month, string day){
    int yearNum = HelpingMethodes::convertStringToInt(year);
    int monthNum = HelpingMethodes::convertStringToInt(month);
    int dayNum = HelpingMethodes::convertStringToInt(day);
    if((monthNum==2) && ((yearNum%400==0) || ((yearNum%100!=0)&&(yearNum%4==0))) && dayNum<30){
        return true;
    }else if(monthNum==2 && dayNum<29){
        return true;
    }else if((monthNum==1 || monthNum==3 || monthNum==5 || monthNum==7 || monthNum==8 || monthNum==10 || monthNum==12) && dayNum<32){
        return true;
    }else if((monthNum==4 || monthNum==6 || monthNum==9 || monthNum==11) && dayNum<31){
        return true;
    }else{
        return false;
    }
}

void MoneyManager::clearVectorsWithMoney(){
    incomes.clear();
    expenses.clear();
    budget = 0;
}
