#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(Users user){

    CMarkup xml;

    bool fileExists = xml.Load ("Users.xml");

    if (!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }


}
