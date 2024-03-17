#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H
#include <iostream>
#include "Markup.h"
#include <vector>
#include <string>

#include "Users.h"
#include "HelpingMethodes.h"

class FileWithUsers {
private:
    Users getUserData();
    int getAmountOfUsersFromFile();
public:
    FileWithUsers(string nameOfFileWithUsers){};
    void addUserToFile(Users user);
    //void saveAllUsersToFile(vector <Users> &users);
    vector <Users> getUsersFromFile();
};

#endif // FILEWITHUSERS_H
