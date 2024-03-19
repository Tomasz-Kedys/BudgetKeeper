#ifndef MONEYMANAGER_H
#define MONEYMANAGER_H
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <iomanip>

#include "FileWithMoney.h"
#include "Money.h"
#include "HelpingMethodes.h"

using namespace std;

class MoneyManager {
private:
    FileWithMoney fileWithMoney;
    Money money;
    vector <Money> incomes;
    vector <Money> expenses;
    int budget;

    int getNewTransactionId();
    string getTodaysDate();
    string getDateFromUser();
    string changeFormOfMonth(string monthWord);
    Money getNewIncomeData();
    bool checkIfDateIsCorrect(string year, string month, string day);

public:
    MoneyManager(string nameOfFileWithIncomes, string nameOfFileWithExpenses)
    : fileWithMoney(nameOfFileWithIncomes,nameOfFileWithExpenses){};

    void addNewIncome();
    void clearVectorsWithMoney();

};

#endif // MONEYMANAGER_H
