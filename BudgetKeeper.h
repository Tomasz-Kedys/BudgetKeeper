#ifndef BUDGETKEEPER_H
#define BUDGETKEEPER_H
#include <iostream>

#include "UserManager.h"
#include "MoneyManager.h"

using namespace std;

class BudgetKeeper{
private:
    UserManager userManager;
    MoneyManager *moneyManager;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;

public:
    BudgetKeeper(string nameOfFileWithUsers, string nameOfFileWithIncomes, string nameOfFileWithExpenses)
    : userManager(nameOfFileWithUsers), FILE_NAME_WITH_INCOMES(nameOfFileWithIncomes), FILE_NAME_WITH_EXPENSES(nameOfFileWithExpenses){
        moneyManager = NULL;
    };
    ~BudgetKeeper(){
        delete moneyManager;
        moneyManager = NULL;
    }

    bool someoneIsLoggedOn();
    char selectAnOptionFromTheMainMenu();
    void registerAnUser();
    void logInTheUser();
    void printAllUsers();
    void changePasswordOfloggedInUser();
    char selectAnOptionFromTheUserMenu();
    void addNewTransaction();
    void logOutTheUser();
    void addNewExpense();
    void printCurrentbudget();
    void printAllToConsole();
    void printBalanceOfGivenPeriod();
    void printThisMonthBalance();
    void printLastMonthBalance();
};

#endif // BUDGETKEEPER_H
