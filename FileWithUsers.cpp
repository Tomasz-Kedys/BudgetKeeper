#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(Users user){

    CMarkup xml;

    bool fileExists = xml.Load ("Users.xml");

    if (!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Id",user.getId());
    xml.IntoElem();
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.OutOfElem();
    xml.Save("Users.xml");
}

vector <Users> FileWithUsers::getUsersFromFile(){
    Users user;

    int amountOfUsers = getAmountOfUsersFromFile();
    cout << amountOfUsers << endl;
    system ("pause");

    vector <Users> users;

    while(amountOfUsers > 0){
        cout << "im in" << endl;
        system("pause");
        user = getUserData();
        users.push_back(user);
        --amountOfUsers;
    }

    return users;
}

Users FileWithUsers::getUserData(){
    Users user;
    CMarkup xml;

    xml.Load("Users.xml");

    xml.FindElem();
    xml.IntoElem();
    xml.FindElem("id");
    xml.IntoElem();
        user.setId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.IntoElem();
        xml.FindElem("Name");
        user.setName(xml.GetData());
        xml.FindElem("Surname");
        user.setSurname(xml.GetData());
        xml.FindElem("Login");
        user.setLogin(xml.GetData());
        xml.FindElem("Password");
        user.setPassword(xml.GetData());
    xml.OutOfElem();

    cout << "User data :" << endl;
    cout << "Id : " << user.getId() << endl;
    cout << "Name : " << user.getName() << endl;
    cout << "Surname : " << user.getSurname() << endl;
    cout << "Login : " << user.getLogin() << endl;
    cout << "Password : " << user.getPassword() << endl;

    system ("pause");

    return user;
}

int FileWithUsers::getAmountOfUsersFromFile(){
    CMarkup xml;
    int amountOfUsers = 0;

    bool fileExists = xml.Load ("Users.xml");

    if (!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("Id")){
        ++amountOfUsers;
    }

    return amountOfUsers;
}
