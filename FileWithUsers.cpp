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
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("Id",user.getId());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.OutOfElem();
    xml.Save("Users.xml");
}

vector <Users> FileWithUsers::getUsersFromFile(){
    vector <Users> users;

    users = getUserData();

    return users;
}

vector <Users> FileWithUsers::getUserData(){
    Users user;
    CMarkup xml;

    vector <Users> users;

    bool fileExists = xml.Load("Users.xml");

    if(!fileExists){
        cout << "Plik nie isnieje!!!" << endl;
        cout << "Nie pobrano danych!!!" << endl;
    }else{
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("User")){
            xml.IntoElem();
            xml.FindElem("Id");
            user.setId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("Name");
            user.setName(xml.GetData());
            xml.FindElem("Surname");
            user.setSurname(xml.GetData());
            xml.FindElem("Login");
            user.setLogin(xml.GetData());
            xml.FindElem("Password");
            user.setPassword(xml.GetData());
            xml.OutOfElem();
            users.push_back(user);
        }
    }
    return users;
}

void FileWithUsers::saveAllUsersToFile(vector <Users> &users){
    CMarkup xml;

    bool fileExists = xml.Load("Users.xml");

    vector <Users>::iterator itr = users.begin();

    if(!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }else{
        xml.SetDoc("");
        xml.AddElem("Users");
        xml.IntoElem();
        for(;itr!=users.end();itr++){
            xml.AddElem("User");
            xml.IntoElem();
            xml.AddElem("Id", itr->Users::getId());
            xml.AddElem("Name", itr->Users::getName());
            xml.AddElem("Surname", itr->Users::getSurname());
            xml.AddElem("Login", itr->Users::getLogin());
            xml.AddElem("Password", itr->Users::getPassword());
            xml.OutOfElem();
        }
    }
    xml.Save("Users.xml");
}
