#ifndef DATESMANAGER_H
#define DATESMANAGER_H

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <vector>

#include "HelpingMethodes.h"

using namespace std;

class DatesManager{
private:
    static string changeFormOfMonth(string monthWord);
    static string serializeTheDate(string dateString);
    static int changeDateToNum(string dateString);
    static bool checkIfDateIsCorrect(string year, string month, string day);
public:
    static int getTodaysDate();
    static int getDateFromUser();
    static int extractMonthFromGivenDate(int date);
};

#endif // DATESMANAGER_H
