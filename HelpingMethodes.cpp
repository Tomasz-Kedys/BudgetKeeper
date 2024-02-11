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
