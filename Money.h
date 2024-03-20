#ifndef MONEY_H
#define MONEY_H
#include <iostream>

using namespace std;

class Money{
private:
    int transactionId, userId;
    string date;
    double numericalValueOfIncomeOrExpense;
    string details;

public:
    void setTransactionId (int newTransactionId);
    void setUserId (int newUserId);
    void setDate (string newDate);
    void setAmount (double newAmount);
    void setDetails (string newDetail);

    int getTransactionId();
    int getUserId();
    string getDate();
    double getAmount();
    string getDetails();
};

#endif // MONEY_H
