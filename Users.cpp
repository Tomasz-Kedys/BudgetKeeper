#include "Users.h"

void Users::setId (int newId) {
    if (newId >= 0)
    userId = newId;
}
void Users::setLogin (string newLogin) {
    login = newLogin;
}
void Users::setPassword (string newPassword) {
    password = newPassword;
}
void Users::setName(string newName){
    name = newName;
}
void Users::setSurname(string newSurname){
    surname = newSurname;
}
int Users::getId() {
    return userId;
}
string Users::getLogin() {
    return login;
}
string Users::getPassword() {
    return password;
}
string Users::getName(){
    return name;
}
string Users::getSurname(){
    return surname;
}
