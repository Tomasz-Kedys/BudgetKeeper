#include "Money.h"

void Money::setTransactionId (int newTransactionId){
    if (newTransactionId >= 0)
    transactionId = newTransactionId;
}
void Money::setUserId(int newUserId){
    if(newUserId >= 0)
    userId = newUserId;
}
void Money::setDate (string newDate){
    date = newDate;
}
void Money::setAmount (double newAmount){
    numericalValueOfIncomeOrExpense = newAmount;
}
void Money::setDetails (string newDetail){
    details = newDetail;
}
int Money::getTransactionId(){
    return transactionId;
}
int Money::getUserId(){
    return userId;
}
string Money::getDate(){
    return date;
}
double Money::getAmount(){
    return numericalValueOfIncomeOrExpense;
}
string Money::getDetails(){
    return details;
}
