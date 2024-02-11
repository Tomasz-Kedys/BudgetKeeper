#ifndef MONEYMANAGER_H
#define MONEYMANAGER_H
#include <iostream>

#include "FileWithMoney.h"
#include "DatesMethodes.h"
#include "Money.h"

using namespace std;

class MoneyManager {
private:
    FileWithMoney fileWithMoney;
    DatesMethodes datesMethodes;
    Money money;
    vector <Money> income;
    vector <Money> expense;
    int Budget;
public:

};

#endif // MONEYMANAGER_H
