#include "FileWithMoney.h"

void FileWithMoney::addIncomeToFile(Money money){
    CMarkup xml;

    bool fileExist = xml.Load("Incomes.xml");

    if(!fileExist){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("UserId",money.getUserId());
    xml.IntoElem();
    xml.AddElem("Id", money.getTransactionId());
    xml.AddElem("Amount", money.getAmount());
    xml.AddElem("Date", money.getDate());
    xml.AddElem("Details", money.getDetails());
    xml.Save("Incomes.xml");
}

void FileWithMoney::addExpenseToFile(Money money){
    CMarkup xml;

    bool fileExist = xml.Load("Expenses.xml");

    if(!fileExist){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("UserId",money.getUserId());
    xml.IntoElem();
    xml.AddElem("Id", money.getTransactionId());
    xml.AddElem("Amount", money.getAmount());
    xml.AddElem("Date", money.getDate());
    xml.AddElem("Details", money.getDetails());
    xml.Save("Expenses.xml");
}
