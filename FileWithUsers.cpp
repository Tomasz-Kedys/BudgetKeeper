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
    int amountOfUsers = getAmountOfUsersFromFile();

    if(amountOfUsers > 0){
      users = getUserData(amountOfUsers);
    }else{
        cout << "Nie udalo sie otworzyc pliku i popranie pobrac danych !!!" << endl;
        system("pause");
    }

    return users;
}

vector <Users> FileWithUsers::getUserData(int amountOfUsers){
    Users user;
    CMarkup xml;

    vector <Users> users;

    bool fileExists = xml.Load("Users.xml");

    if(!fileExists){
        cout << "Plik nie isnieje!!!" << endl;
        cout << "Program nie jest wstanie pobrac poprawnie danych !!!" << endl;
        system("pause");
    }else{
        xml.FindElem();
        xml.IntoElem();
        while (amountOfUsers > 0){
            xml.FindElem("User");
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
            --amountOfUsers;
        }
    }
    return users;
}

int FileWithUsers::getAmountOfUsersFromFile(){
    CMarkup xml;
    int amountOfUsers = 0;

    bool fileExists = xml.Load ("Users.xml");

    if (!fileExists){
        return amountOfUsers;
    }else{
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User")){
            ++amountOfUsers;
        }
    }

    return amountOfUsers;
}
