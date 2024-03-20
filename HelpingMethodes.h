#ifndef HELPINGMETHODES_H
#define HELPINGMETHODES_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <unistd.h>
#include <sys/stat.h>
#include <iomanip>

using namespace std;

class HelpingMethodes {
public:
    static char getCharFromUser();
    static string convertIntToString (int number);
    static int convertStringToInt(string number);
    static float converStringToFloat (string number);
    static string getDataLine();
    static char selectAnOptionFromTheMainMenu();
    static char selectAnOptionFromTheUserMenu();
    static char selectAnOptionFromTheMoneyMenu();
    static char selectAnOptionFromTheTransactionMenu();
    static string getNumber(string text, int charPos);
    static string changeFirstLetterToCapitalAndRestToSmall(string text);
    static double correctTheNumber(double number);
};

#endif // HELPINGMETHODES_H
