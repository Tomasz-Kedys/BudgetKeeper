#include "UserManager.h"

void UserManager::saveAllUsersToFile(vector <Users> &users){
    fileWithUsers.saveAllUsersToFile(users);
}

bool UserManager::someoneIsLoggedOn(){
    if(idOfLoggedInUser > 0){
        return true;
    }else
    return false;
}

void UserManager::registerAnUser(){
    Users user = getNewUserData();

    users.push_back (user);
    fileWithUsers.addUserToFile (user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system ("pause");
}

Users UserManager::getNewUserData(){
    Users user;

    user.setId (getIdOfNewUser() );

    string login, password;
    string name, surname;
    do {
        cout << "Podaj login: ";
        cin >> login;

        user.setLogin (login);
    } while (loginExists (user.getLogin() ) == true);

    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword (password);

    cout << "Podaj Imie: ";
    name = HelpingMethodes::changeFirstLetterToCapitalAndRestToSmall(HelpingMethodes::getDataLine());
    user.setName(name);

    cout << "Poadj Nazwisko: ";
    surname = HelpingMethodes::changeFirstLetterToCapitalAndRestToSmall(HelpingMethodes::getDataLine());
    user.setSurname(surname);

    return user;
}

int UserManager::getIdOfNewUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

void UserManager::printAllUsers(){
        for (int i = 0; i < (int) users.size(); i++) {
        cout << users[i].getId() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << endl;
    }
}

int UserManager::loggingIn(){
    Users user;
    string login = "", password = "";

    if(!users.empty()){
        cout << endl << "Podaj login: ";
        login = HelpingMethodes::getDataLine ();
        vector <Users>::iterator itr = users.begin();
        while (itr != users.end() ) {
            if (itr -> Users::getLogin() == login) {
                for (int tries = 3; tries > 0; tries--) {
                    cout << "Podaj haslo. Pozostalo prob: " << tries << ": ";
                    password = HelpingMethodes::getDataLine();

                    if (itr -> Users::getPassword() == password) {
                        cout << endl << "Zalogowales sie." << endl << endl;
                        system ("pause");
                        idOfLoggedInUser = itr -> Users::getId();
                        return idOfLoggedInUser;
                    }
                }
                cout << "Wprowadzono 3 razy bledne haslo." << endl;
                system ("pause");
                return 0;
            }
            itr++;
        }
        cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
        system("pause");
    } else {
        cout << "Nie ma zarejestrowanych uzytkownikow" << endl;
        system("pause");
    }
    return 0;
}

bool UserManager::loginExists(string login){
    for (int i = 0; i < (int) users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::setIdOfLoggedUser(int newId){
    if(idOfLoggedInUser > 0){
        idOfLoggedInUser = newId;
    }
}

int UserManager::getIdOfLoggedUser(){
    return idOfLoggedInUser;
}

void UserManager::changeLoggedUserPassword(){
    string newPassword = "";
    cout << "Podaj nowe haslo : ";
    newPassword = HelpingMethodes::getDataLine();

    vector <Users>::iterator itr = users.begin();
    for(; itr != users.end(); itr++){
        if(itr->Users::getId() == getIdOfLoggedUser()){
            itr->Users::setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system ("pause");
        }
    }
    saveAllUsersToFile(users);
}
