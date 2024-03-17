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
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
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
