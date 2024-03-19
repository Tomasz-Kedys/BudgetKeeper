#ifndef FILEWITHMONEY_H
#define FILEWITHMONEY_H
#include <iostream>

#include "Money.h"
#include "HelpingMethodes.h"

using namespace std;

class FileWithMoney {
private:
    Money money;

public:
    FileWithMoney (string nameOfFileWithIncomes, string nameOfFileWithExpenses){};
    void addIncomeToFile(Money money);
};

#endif // FILEWITHMONEY_H
