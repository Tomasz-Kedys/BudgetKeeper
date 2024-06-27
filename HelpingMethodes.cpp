#include "HelpingMethodes.h"

char HelpingMethodes::selectAnOptionFromTheMainMenu(){
    char choice;

    system ("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    //cout << "3. Wypisz wszystkich Uzytkownikow" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = HelpingMethodes::getCharFromUser();

    return choice;
}

char HelpingMethodes::getCharFromUser(){
    string entry = "";
    char thing  = {0};

    while (true) {
        cin.sync();
        getline (cin, entry);

        if (entry.length() == 1) {
            thing = entry[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return thing;
}

char HelpingMethodes::selectAnOptionFromTheUserMenu(){
    char choice;

    system ("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj nowa transakcje" << endl;
    cout << "2. Wyciag z biezacego miesiaca" << endl;
    cout << "3. Wyciag z zeszlego miesiaca" << endl;
    cout << "4. Wyciag z danego okresu" << endl;
    cout << "5. Wypisz transakcje" << endl;
    cout << "6. Pokaz balans konta" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = HelpingMethodes::getCharFromUser();

    return choice;
}

string HelpingMethodes::getDataLine(){
    string input;
    cin.sync();
    getline(cin, input);
    return input;
}

string HelpingMethodes::changeFirstLetterToCapitalAndRestToSmall(string text){
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

double HelpingMethodes::correctTheNumber(double number){
    stringstream ss;
    double doubleNumberWithSetPrecision;
    ss << fixed << setprecision(3) << number;
    ss >> doubleNumberWithSetPrecision;
    return doubleNumberWithSetPrecision;
}

char HelpingMethodes::selectAnOptionFromTheMoneyMenu(){
    char choice;

    system ("cls");
    cout << "    >>> MENU  DATY <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dzisiaj" << endl;
    cout << "2. Inna Data" << endl;
    cout << "3. Cofnij" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = HelpingMethodes::getCharFromUser();

    return choice;
}

int HelpingMethodes::convertStringToInt(string number){
    int convertedNumber = stoi(number);
    return convertedNumber;
}

string HelpingMethodes::convertIntToString(int number){
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

double HelpingMethodes::converStringToDouble(string number){
    double convertedNumber = stod(number);
    return convertedNumber;
}

char HelpingMethodes::selectAnOptionFromTheTransactionMenu(){
    char choice;

    system ("cls");
    cout << "    >>> MENU  TRANSAKCJI <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Wplata lub przychod" << endl;
    cout << "2. Wyplata lub wydatek" << endl;
    cout << "3. Cofnij" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = HelpingMethodes::getCharFromUser();

    return choice;
}
