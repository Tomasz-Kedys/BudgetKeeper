#ifndef FILEWITHMONEY_H
#define FILEWITHMONEY_H
#include <iostream>
#include "Markup.h"
#include <vector>

#include "Money.h"
#include "HelpingMethodes.h"

using namespace std;

class FileWithMoney {
private:
    Money money;

public:
    FileWithMoney (string nameOfFileWithIncomes, string nameOfFileWithExpenses){};
    void addIncomeToFile(Money money);
    void addExpenseToFile(Money money);
    vector <Money> getAllIncomesOfLoggedInUser (int idOfLoggedInUser);
    vector <Money> getAllExpensesOfLoggedInUser (int idOfLoggedInUser);
};

#endif // FILEWITHMONEY_H
