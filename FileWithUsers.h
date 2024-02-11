#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H
#include <iostream>
#include "Markup.h"
#include <vector>
#include <string>

#include "Users.h"
#include "StorageFile.h"
#include "HelpingMethodes.h"

class FileWithUsers : public StorageFile{
private:

public:
    FileWithUsers(string nameOfFileWithUsers) : StorageFile (nameOfFileWithUsers) {};
    void addUserToFile(Users user);
    //void saveAllUsersToFile(vector <Users> &users);
    vector <Users> getUsersFromFile();
};

#endif // FILEWITHUSERS_H
