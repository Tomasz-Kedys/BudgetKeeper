#include "UserManager.h"

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
