#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;

class Users{
    int userId;
    string name, surname;
    string login, password;
public:
    void setId (int newId);
    void setLogin (string newLogin);
    void setPassword (string newPassword);
    void setName (string newName);
    void setSurname (string newSurname);

    int getId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
};

#endif // USER_H
