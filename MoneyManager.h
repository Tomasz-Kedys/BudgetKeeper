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
    double budget;
    const int LOGGEDIN_USER_ID;

    int getNewTransactionId();
    string getTodaysDate();
    string getDateFromUser();
    string changeFormOfMonth(string monthWord);
    Money getNewTransactionData(char choice);
    double calculateBudget();
    double addAllIncomesFromVector();
    double addAllExpensesFromVector();
    bool checkIfDateIsCorrect(string year, string month, string day);
    int incomesLastId();
    int expensesLastId();

public:
    MoneyManager(string nameOfFileWithIncomes, string nameOfFileWithExpenses, int idOfLoggedInUser)
    : fileWithMoney(nameOfFileWithIncomes,nameOfFileWithExpenses), LOGGEDIN_USER_ID(idOfLoggedInUser){
        incomes = fileWithMoney.getAllIncomesOfLoggedInUser(LOGGEDIN_USER_ID);
        expenses = fileWithMoney.getAllExpensesOfLoggedInUser(LOGGEDIN_USER_ID);
        budget = calculateBudget();
    };

    void addNewTransaction();
    void clearVectorsWithMoney();

};

#endif // MONEYMANAGER_H
