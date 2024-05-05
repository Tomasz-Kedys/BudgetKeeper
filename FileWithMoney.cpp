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
    xml.AddElem("UserId",money.getUserId());
    xml.IntoElem();
    xml.AddElem("Income");
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
    xml.AddElem("UserId",money.getUserId());
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("Id", money.getTransactionId());
    xml.AddElem("Amount", money.getAmount());
    xml.AddElem("Date", money.getDate());
    xml.AddElem("Details", money.getDetails());
    xml.Save("Expenses.xml");
}

vector <Money> FileWithMoney::getAllIncomesOfLoggedInUser(int idOfLoggedInUser){
    Money money;
    CMarkup xml;

    vector <Money> incomes;

    bool fileExists = xml.Load("Incomes.xml");

    if(!fileExists){
        cout << "Plik nie isnieje!!!" << endl;
        cout << "Program nie jest wstanie pobrac poprawnie danych !!!" << endl;
        system("pause");
    }else{
        xml.FindElem();
        xml.IntoElem();
        xml.FindElem("UserId");
        while(atoi(MCD_2PCSZ(xml.GetData())) == idOfLoggedInUser){
            money.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("Income");
            xml.IntoElem();
            xml.FindElem("Id");
            money.setTransactionId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("Amount");
            money.setAmount(stod(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("Date");
            money.setDate(xml.GetData());
            xml.FindElem("Details");
            money.setDetails(xml.GetData());
            xml.OutOfElem();
            incomes.push_back(money);
        }

    }

    return incomes;
}

vector <Money> FileWithMoney::getAllExpensesOfLoggedInUser(int idOfLoggedInUser){
    Money money;
    CMarkup xml;

    vector <Money> expenses;

    bool fileExists = xml.Load("Expenses.xml");

    if(!fileExists){
        cout << "Plik nie isnieje!!!" << endl;
        cout << "Program nie jest wstanie pobrac poprawnie danych !!!" << endl;
        system("pause");
    }else{
        xml.FindElem();
        xml.IntoElem();
        xml.FindElem("UserId");
        while(atoi(MCD_2PCSZ(xml.GetData())) == idOfLoggedInUser){
            money.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("Expense");
            xml.IntoElem();
            xml.FindElem("Id");
            money.setTransactionId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("Amount");
            money.setAmount(stod(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("Date");
            money.setDate(xml.GetData());
            xml.FindElem("Details");
            money.setDetails(xml.GetData());
            xml.OutOfElem();
            expenses.push_back(money);
        }
    }

    return expenses;
}
