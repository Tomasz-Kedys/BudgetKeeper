#include "FileWithMoney.h"

void FileWithMoney::addIncomeToFile(Money money){
    CMarkup xml;

    bool fileExist = xml.Load("Incomes.xml");

    if(!fileExist){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("all_Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("UserId", money.getUserId());
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
        xml.AddElem("all_Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("UserId",money.getUserId());
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
        cout << "Program nie jest wstanie pobrac danych !!!" << endl << endl;
        system("pause");
    }else{
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Income")){
            xml.FindChildElem("UserId");
            int userId = atoi(MCD_2PCSZ(xml.GetChildData()));
            if(userId == idOfLoggedInUser){
                xml.IntoElem();
                money.setUserId(userId);
                xml.FindElem("Id");
                money.setTransactionId(atoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("Amount");
                double amount = stod(MCD_2PCSZ(xml.GetData()));
                money.setAmount(amount);
                xml.FindElem("Date");
                money.setDate(atoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("Details");
                money.setDetails(xml.GetData());
                xml.OutOfElem();
                incomes.push_back(money);
            }
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
        cout << "Program nie jest wstanie pobrac danych !!!" << endl;
        system("pause");
    }else{
         xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Expense")){
            xml.FindChildElem("UserId");
            int userId = atoi(MCD_2PCSZ(xml.GetChildData()));
            if(userId == idOfLoggedInUser){
                xml.IntoElem();
                money.setUserId(userId);
                xml.FindElem("Id");
                money.setTransactionId(atoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("Amount");
                money.setAmount(stod(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("Date");
                money.setDate(atoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("Details");
                money.setDetails(xml.GetData());
                xml.OutOfElem();
                expenses.push_back(money);
            }
        }
    }
    return expenses;
}
