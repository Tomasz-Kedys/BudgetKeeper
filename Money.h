#ifndef MONEY_H
#define MONEY_H
#include <iostream>

using namespace std;

class Money{
private:
    int transactionId, userId, date;
    double numericalValueOfIncomeOrExpense;
    string details;

public:
    void setTransactionId (int newTransactionId);
    void setUserId (int newUserId);
    void setDate (int newDate);
    bool setAmount (double newAmount);
    void setDetails (string newDetail);

    int getTransactionId();
    int getUserId();
    int  getDate();
    double getAmount();
    string getDetails();
};

#endif // MONEY_H
