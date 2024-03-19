#include "Money.h"

void Money::setId (int newId){
    if (newId >= 0)
    transactionId = newId;
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
int Money::getId(){
    return transactionId;
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
