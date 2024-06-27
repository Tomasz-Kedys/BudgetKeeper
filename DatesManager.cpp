#include "DatesManager.h"

int DatesManager::getTodaysDate() {
    string partOfDate = "";
    int partOfDatePosition = 0;
    string dayOftheWeek = "", month = "", dayOfTheMonth = "", timeOfTheDay = "", year = "";
    time_t now = time (0);
    char* date_time = ctime (&now);
    string date = date_time;
    string FinalDateOutput = "";
    date.erase(date.end()-1);
    date += " ";

    for( int charPos = 0; charPos <= (int) date.length(); charPos++) {
        if(date[charPos] != ' ') {
            partOfDate += date[charPos];
        } else {
            partOfDatePosition++;
            switch (partOfDatePosition) {
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

    month = changeFormOfMonth(month);
    FinalDateOutput = year +"/"+ month +"/"+ dayOfTheMonth;

    return changeDateToNum(FinalDateOutput);
}

string DatesManager::changeFormOfMonth(string monthWord) {

    vector <string> months = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    string zero = "0";

    for(int i = 0; i < (int) months.size(); i++) {
        if (monthWord == months[i]) {
            if((i+1) < 10) {
                string temp = to_string(i+1);
                temp.insert(0,zero);
                return temp;
            } else {
                return to_string(i+1);
            }
        }
    }
    return monthWord;
}

int DatesManager::getDateFromUser() {

    string year = "", month = "", day = "";

    cout << "Wpisz date." << endl;
    do {
        cout << "Podaj rok w formacie yyyy : ";
        cin >> year;
        cout << "Podaj miesiac w formacie mm : ";
        cin >> month;
        cout << "Podaj dzien w formacie dd : ";
        cin >> day;
        if(year.length() != 4 || month.length() != 2 || day.length() != 2) {
            cout << "Podano date w zlym formacie." << endl;
            cout << "Prosze wprwadzic date jescze raz w formacie yyyy/mm/dd." << endl;
            system("pause");
        } else {
            continue;
        }
    } while (year.length() != 4 || month.length() != 2 || day.length() != 2);

    if (checkIfDateIsCorrect(year,month,day) == true) {
        return changeDateToNum(year +"/"+ month +"/"+ day);
    }
    cout << "Podano zla date, nie istniejaca w kalendarzu." << endl;
    system("pause");
    return getDateFromUser();
}

bool DatesManager::checkIfDateIsCorrect(string year, string month, string day) {

    int yearNumber = HelpingMethodes::convertStringToInt(year);
    int monthNumber = HelpingMethodes::convertStringToInt(month);
    int dayNumber = HelpingMethodes::convertStringToInt(day);

    int todaysYear = getTodaysDate();
    todaysYear = todaysYear / 10000;

    if((monthNumber==2) && ((yearNumber%400==0) || ((yearNumber%100!=0)&&(yearNumber%4==0))) && dayNumber<30) {
        return true;
    } else if(monthNumber==2 && dayNumber<29) {
        return true;
    } else if((monthNumber==1 || monthNumber==3 || monthNumber==5 || monthNumber==7 || monthNumber==8 || monthNumber==10 || monthNumber==12) && dayNumber<32) {
        return true;
    } else if((monthNumber==4 || monthNumber==6 || monthNumber==9 || monthNumber==11) && dayNumber<31) {
        return true;
    } else if(yearNumber <= todaysYear) {
        return true;
    } else {
        return false;
    }
}

string DatesManager::serializeTheDate(string dateString) {
    string temp = "";

    for(int i = 0; i != (int)dateString.size(); i++) {
        if(dateString[i] == '/') {
            //do nothing
        } else {
            temp += dateString[i];
        }
    }
    return temp;
}

int DatesManager::changeDateToNum(string dateString) {
    string serialDate = serializeTheDate(dateString);
    int serialDateNum = HelpingMethodes::convertStringToInt(serialDate);

    return serialDateNum;
}
