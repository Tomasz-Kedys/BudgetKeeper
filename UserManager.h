#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Users.h"
#include "FileWithUsers.h"
#include "HelpingMethodes.h"

using namespace std;

class UserManager {
private:
    int idOfLoggedInUser;
    vector <Users> users;
    FileWithUsers fileWithUsers;

    int getIdOfNewUser();
    bool loginExists (string login);
    Users getNewUserData();
    void saveAllUsersToFile (vector <Users> &users);

public:
    UserManager (string nameOfFileWithUsers) : fileWithUsers (nameOfFileWithUsers) {
        users = fileWithUsers.getUsersFromFile();
        idOfLoggedInUser = 0;
    };
    void registerAnUser();
    void printAllUsers();
    int loggingIn();
    bool someoneIsLoggedOn();
    void setIdOfLoggedUser (int newId);
    int getIdOfLoggedUser();
    void changeLoggedUserPassword();
};

#endif // USERMANAGER_H
