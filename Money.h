#ifndef MONEY_H
#define MONEY_H
#include <iostream>

using namespace std;

class Money{
private:
    int transactionId;
    string date;
    double numericalValueOfIncomeOrExpense;
    string details;

public:
    void setId (int newId);
    void setDate (string newDate);
    void setAmount (double newAmount);
    void setDetails (string newDetail);

    int getId();
    string getDate();
    double getAmount();
    string getDetails();
};

#endif // MONEY_H
