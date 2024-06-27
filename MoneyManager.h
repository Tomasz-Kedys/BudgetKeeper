#ifndef MONEYMANAGER_H
#define MONEYMANAGER_H
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

#include "FileWithMoney.h"
#include "Money.h"
#include "HelpingMethodes.h"
#include "DatesManager.h"

using namespace std;

class MoneyManager {
private:
    FileWithMoney fileWithMoney;
    Money money;
    vector <Money> incomes;
    vector <Money> expenses;
    const int LOGGEDIN_USER_ID;

    int getNewTransactionId();
    Money getNewTransactionData(char choice);
    double getValueOfTransactionFromUser(char choice);
    int getDateSet();
    string getDetailsSet();
    double calculateBudget();
    double addAllIncomesFromVector();
    double addAllExpensesFromVector();
    int incomesLastId();
    int expensesLastId();
    vector <Money> sortVectorByDate(int bigger, int smaller, vector <Money> vectorThatNeedsSorting);

public:
    MoneyManager(string nameOfFileWithIncomes, string nameOfFileWithExpenses, int idOfLoggedInUser)
    : fileWithMoney(nameOfFileWithIncomes,nameOfFileWithExpenses), LOGGEDIN_USER_ID(idOfLoggedInUser){
        incomes = fileWithMoney.getAllIncomesOfLoggedInUser(LOGGEDIN_USER_ID);
        expenses = fileWithMoney.getAllExpensesOfLoggedInUser(LOGGEDIN_USER_ID);
    };

    void addNewTransaction();
    void clearVectorsWithMoney();
    double getBudget();
    void printAllToConsole();
    void printBalanceOfGivenPeriod();

};

#endif // MONEYMANAGER_H
