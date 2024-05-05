#include "MoneyManager.h"

void MoneyManager::addNewTransaction(){
    char choice = HelpingMethodes::selectAnOptionFromTheTransactionMenu();

    Money money = getNewTransactionData(choice);

    switch(choice){
    case '1':
        incomes.push_back(money);
        fileWithMoney.addIncomeToFile(money);
        break;
    case '2':
        expenses.push_back(money);
        fileWithMoney.addExpenseToFile(money);
        break;
    default:
        cout << "Prosze wybrac miedzy opcja 1 lub 2 i wpisac poprawna wartosc transakcji." << endl;
        system("pause");
        break;
    }

    cout << endl << "Dodano transakcje pomyslnie" << endl << endl;
    system ("pause");
}

Money MoneyManager::getNewTransactionData(char choice){
    double valueOfTransaction = 0;
    string details;

    cout << "Hello getting data" << endl;
    system("pause");

    money.setTransactionId(getNewTransactionId());

    cout << "Hello got id" << endl;
    system("pause");

    money.setUserId(LOGGEDIN_USER_ID);

    cout << "Hello got user id" << endl;
    system("pause");

    if(choice == '1'){
        cout << "Podaj wyskosc wplaty lub zarobku : ";
        cin >> valueOfTransaction;

        if (valueOfTransaction < 0){
            cout << "Podana wartosc powinna byc wieksza od 0." << endl;
            do{
                cout << "Podaj wysokosc wplaty lub zarobku : ";
                cin >> valueOfTransaction;
            }while(valueOfTransaction <= 0);

            valueOfTransaction = HelpingMethodes::correctTheNumber(valueOfTransaction);
            money.setAmount(valueOfTransaction);
        }else{
            valueOfTransaction = HelpingMethodes::correctTheNumber(valueOfTransaction);
            money.setAmount(valueOfTransaction);
        }
    }else if(choice == '2'){
        cout << "Podaj wyskosc wyplaty lub wydatku : ";
        cin >> valueOfTransaction;

        if (valueOfTransaction > 0){
            cout << "Podana wartosc powinna byc mniejsza od 0." << endl;
            do{
                cout << "Podaj wysokosc wyplaty lub wydatku  : ";
                cin >> valueOfTransaction;
            }while(valueOfTransaction >= 0);

            valueOfTransaction = HelpingMethodes::correctTheNumber(valueOfTransaction);
            money.setAmount(valueOfTransaction);
        }else{
            valueOfTransaction = HelpingMethodes::correctTheNumber(valueOfTransaction);
            money.setAmount(valueOfTransaction);
        }
    }else{
        cout << "--------BLAD--------- " << endl;
        cout << "Wybor nie zostal przekazany, nie mozna dodac transakcji poprawnie" << endl;
        cout << "Funkcja nie moze byc uzyta poprawnie" << endl;
        cout << "Program zostanie zamkniêty " << endl;
        system("pause");
        exit(0);
    }

    cout << "Hello got value" << endl;
    system("pause");

    choice = HelpingMethodes::selectAnOptionFromTheMoneyMenu();

    switch(choice){
    case '1':
        money.setDate(getTodaysDate());
        break;
    case '2':
        money.setDate(getDateFromUser());
        break;
    default:
        cout << "Prosze wybrac miedzy opcja 1 lub 2 i ustawic date transakcji." << endl;
        system("pause");
        break;
    }

    cout << "Hello got date" << endl;
    system("pause");

    cout << "Dodatkowe informacje o transakcji : ";
    details = HelpingMethodes::getDataLine();
    if(money.getDetails().length() == 0){
        details = money.getDetails() +" "+ details;
    }

    money.setDetails(details);

    cout << "Hello got details" << endl;
    system("pause");

//    cout << "ID : " << money.getTransactionId() << endl;
//    cout << "Amount : " << money.getAmount() << endl;
//    cout << "Date : " << money.getDate() << endl;
//    cout << "Details : " << money.getDetails() << endl;
//    system("pause");

    return money;
}

int MoneyManager::getNewTransactionId() {
    // inaczej trzeba dostac ostatni id-k, najlepiej z pilku

    if(incomesLastId() > expensesLastId()){
        return incomesLastId() + 1;
    }else if(incomesLastId() < expensesLastId()){
        return expensesLastId() + 1;
    }else if(incomesLastId() == 1 && expensesLastId() == 1){
        return 1;
    }else{
        cout << "Cos poszlo nie tak, nie nadano poprawnego Id" << endl;
        system("pause");
        return 0;
    }
}

int MoneyManager::incomesLastId(){
    if(incomes.empty()){
        return 1;
    }else{
        return incomes.back().getTransactionId();
    }
    return 0;
}

int MoneyManager::expensesLastId(){
    if(expenses.empty()){
        return 1;
    }else{
        return expenses.back().getTransactionId();
    }
    return 0;
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

    string todaysYear = getTodaysDate();
    todaysYear = todaysYear.substr(0,4);
    int todaysYearNum = HelpingMethodes::convertStringToInt(todaysYear);

    if((monthNum==2) && ((yearNum%400==0) || ((yearNum%100!=0)&&(yearNum%4==0))) && dayNum<30){
        return true;
    }else if(monthNum==2 && dayNum<29){
        return true;
    }else if((monthNum==1 || monthNum==3 || monthNum==5 || monthNum==7 || monthNum==8 || monthNum==10 || monthNum==12) && dayNum<32){
        return true;
    }else if((monthNum==4 || monthNum==6 || monthNum==9 || monthNum==11) && dayNum<31){
        return true;
    }else if(yearNum <= todaysYearNum){
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

double MoneyManager::calculateBudget(){ //niedziala
    double allIncomesSum = 0;
    double allExpensesSum = 0;

    allIncomesSum = addAllIncomesFromVector();
    allExpensesSum = addAllExpensesFromVector();

    cout << endl << allIncomesSum + allExpensesSum << endl;
    system("pause");

    return allIncomesSum + allExpensesSum;
}

double MoneyManager::addAllIncomesFromVector(){ //Niedziala
    double sum = 0;
    int cos = 0;
    vector <Money>::iterator itr = incomes.begin();

    for (itr; itr <= incomes.end(); itr++){
        sum += itr -> Money::getAmount();
        cout << cos << endl;
        cos++;
    }
    return sum;
}

double MoneyManager::addAllExpensesFromVector(){ //Niedziala
    double sum = 0;
    vector <Money>::iterator itr = expenses.begin();

    for (itr; itr != expenses.end(); ++itr){
        sum += itr -> Money::getAmount();
    }
    return sum;
}
