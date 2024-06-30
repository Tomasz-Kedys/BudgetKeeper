#include "MoneyManager.h"

void MoneyManager::addNewTransaction() {
    char choice = HelpingMethodes::selectAnOptionFromTheTransactionMenu();

    Money money = getNewTransactionData(choice);

    switch(choice) {
    case '1':
        incomes.push_back(money);
        fileWithMoney.addIncomeToFile(money);
        break;
    case '2':
        expenses.push_back(money);
        fileWithMoney.addExpenseToFile(money);
        break;
    case '3':
        cout << "Powracasz do poprzedniego menu ... " << endl;
        return;
    default:
        cout << "Prosze wybrac miedzy opcja 1 lub 2 i wpisac poprawna wartosc transakcji." << endl;
        system("pause");
        break;
    }

    if(choice!='3'){
       cout << endl << "Dodano transakcje pomyslnie" << endl << endl;
    }

    system ("pause");
}

Money MoneyManager::getNewTransactionData(char choice) {

    double amount = getValueOfTransactionFromUser(choice);
    int date = getDateSet();

    if (isnan(amount)) {
        cout << "Powracasz do poprzedniego menu ... " << endl;
        return money;
    }

    if (isnan(date)){
        cout << "Powracasz do poprzedniego menu ... " << endl;
        return money;
    }

    money.setAmount(amount);
    money.setDate(date);
    money.setDetails(getDetailsSet());

    cout << "USER ID : " << money.getUserId() << endl;
    cout << "ID : " << money.getTransactionId() << endl;
    cout << "Amount : " << money.getAmount() << endl;
    cout << "Date : " << money.getDate() << endl;
    cout << "Details : " << money.getDetails() << endl;
    system("pause");

    return money;
}

string MoneyManager::getDetailsSet(){
    string details;
    cout << "Dodatkowe informacje o transakcji (Lub 'b' by wrocic): ";

    details = HelpingMethodes::getDataLine();
    if (details == "b") {
        cout << "Powracasz do poprzedniego menu ... " << endl;
        return details;
    }
    return details;
}

int MoneyManager::getDateSet(){
    int dateGivenByUser = numeric_limits<int>::quiet_NaN();
    char choice = HelpingMethodes::selectAnOptionFromTheMoneyMenu();

    switch(choice) {
    case '1':
        dateGivenByUser = DatesManager::getTodaysDate();
        break;
    case '2':
        dateGivenByUser = DatesManager::getDateFromUser();
        break;
    case '3':
        break;
    default:
        cout << "Prosze wybrac miedzy opcja 1 lub 2 i ustawic date transakcji." << endl;
        system("pause");
        break;
    }
    return dateGivenByUser;
}

double MoneyManager::getValueOfTransactionFromUser(char choice) {
    double valueOfTransaction = 0.0;
    string input = "";

    if(choice == '1') {
        cout << "Podaj wyskosc wplaty lub zarobku (lub 'b' by wrocic to poprzedniego menu): ";
        while (cin >> input) {
            if (input == "b") {
                return numeric_limits<double>::quiet_NaN(); // w teorii zwraca wartosc not a number
            }
            try {
                valueOfTransaction = HelpingMethodes::converStringToDouble(input);
                if (valueOfTransaction < 0) {
                    cout << "Podana wartosc powinna byc wieksza od 0." << endl;
                    continue;
                }
                valueOfTransaction = HelpingMethodes::correctTheNumber(valueOfTransaction);
                return valueOfTransaction;
            } catch (const invalid_argument&) {
                cout << "Podaj wyskosc wplaty lub zarobku (lub 'b' by wrocic to poprzedniego menu): ";
            }
        }
    } else if(choice == '2') {
        cout << "Podaj wyskosc wyplaty lub wydatku : ";
        while (cin >> input) {
            if (input == "b") {
                return numeric_limits<double>::quiet_NaN(); // w teorii zwraca wartosc not a number
            }
            try {
                valueOfTransaction = HelpingMethodes::converStringToDouble(input);
                if (valueOfTransaction > 0) {
                    cout << "Podana wartosc powinna byc mniejsza od 0." << endl;
                    continue;
                }
                    valueOfTransaction = HelpingMethodes::correctTheNumber(valueOfTransaction);
                    return valueOfTransaction;
                } catch (const invalid_argument&) {
                    cout << "Podaj wyskosc wplaty lub zarobku (lub 'b' by wrocic to poprzedniego menu): ";
                }
        }
    } else if(choice == '3') {
        cout << "Powracasz do poprzedniego menu ... " << endl;
        return numeric_limits<double>::quiet_NaN();
    } else {
        cout << "Powracasz do poprzedniego menu ... " << endl;
        return numeric_limits<double>::quiet_NaN();
    }

    return 0;
}

int MoneyManager::getNewTransactionId() {

    if(incomesLastId() > expensesLastId()) {
        return incomesLastId() + 1;
    } else if(incomesLastId() < expensesLastId()) {
        return expensesLastId() + 1;
    } else if(incomesLastId() == 0 && expensesLastId() == 0) {
        return 1;
    } else {
        cout << "Cos poszlo nie tak, nie nadano poprawnego Id" << endl;
        system("pause");
        return 0;
    }
}

int MoneyManager::incomesLastId() {

    if(incomes.empty()) {
        return 0;
    } else {
        return incomes.back().getTransactionId();
    }
    return 0;
}

int MoneyManager::expensesLastId() {
    if(expenses.empty()) {
        return 0;
    } else {
        return expenses.back().getTransactionId();
    }
    return 0;
}

void MoneyManager::clearVectorsWithMoney() {
    incomes.clear();
    expenses.clear();
}

double MoneyManager::calculateBudget() {
    double allIncomesSum = 0;
    double allExpensesSum = 0;

    allIncomesSum = addAllIncomesFromVector();
    allExpensesSum = addAllExpensesFromVector();

    return allIncomesSum + allExpensesSum;
}

double MoneyManager::addAllIncomesFromVector() {
    double sum = 0.0;
    vector <Money>::iterator itr = incomes.begin();

    while(itr!=incomes.end()) {
        sum += itr -> getAmount();
        ++itr;
    }
    return sum;
}

double MoneyManager::addAllExpensesFromVector() {
    double sum = 0.0;
    vector <Money>::iterator itr = expenses.begin();

    while(itr!=expenses.end()) {
        sum += itr -> getAmount();
        ++itr;
    }
    return sum;
}

double MoneyManager::getBudget() {
    return calculateBudget();
}

void MoneyManager::printAllToConsole() {
    vector <Money>::iterator itr = incomes.begin();
    vector <Money>::iterator itr2 = expenses.begin();

    cout << "Incomes: " << endl;
    cout << "-------------------" << endl;
    for(; itr!=incomes.end(); itr++) {
        cout << "USER ID : " << setw(3) << itr->Money::getUserId() <<  endl;
        cout << "ID : " << setw(8) << itr->Money::getTransactionId() <<  endl;
        cout << "Amount : " << setw(7) << itr->Money::getAmount() <<  endl;
        cout << "Date : " << setw(10) << itr->Money::getDate() <<  endl;
        cout << "Details : " << setw(5) << itr->Money::getDetails() <<  endl << endl;
    }

    cout << endl << "Expenses: " << endl;
    cout << "--------------------" << endl;
    for(;itr2!=expenses.end(); itr2++){
        cout << "USER ID : " << setw(3) << itr2->Money::getUserId() << endl;
        cout << "ID : " << setw(8) << itr2->Money::getTransactionId() << endl;
        cout << "Amount : " << setw(5) << itr2->Money::getAmount() << endl;
        cout << "Date : " << setw(10) << itr2->Money::getDate() << endl;
        cout << "Details : " << setw(5) << itr2->Money::getDetails() << endl << endl;
    }
}

void MoneyManager::printBalanceOfGivenPeriod(){
    int firstDateGivenByUser = 0;
    int secondDateGivenByUser = 0;

    vector <Money> transactions;
    transactions.clear();

    transactions.insert(transactions.end(), incomes.begin(), incomes.end());
    transactions.insert(transactions.end(), expenses.begin(), expenses.end());

    vector <Money>::iterator itr = transactions.begin();

    firstDateGivenByUser = getDateSet();

    if (isnan(firstDateGivenByUser)){
        cout << "Powracasz do poprzedniego menu ... " << endl;
        return;
    }

    secondDateGivenByUser = getDateSet();

    if (isnan(secondDateGivenByUser)){
        cout << "Powracasz do poprzedniego menu ... " << endl;
        return;
    }

    sort(transactions.begin(), transactions.end(), [](Money& elierDate, Money& laterDate) {
    return elierDate.getDate() < laterDate.getDate();
    });

    if(firstDateGivenByUser > secondDateGivenByUser){
        cout << "Wyciag z wszystkich transakcji pomiedzy : " << secondDateGivenByUser << " and " << firstDateGivenByUser << endl;
        cout << "//////////////////////////////////////////////////////////////////////////////////////" << endl;
        for(;itr!=transactions.end();itr++){
            int dateTemp = itr->Money::getDate();
            if((dateTemp >= secondDateGivenByUser) && (dateTemp <= firstDateGivenByUser)){
                cout << "USER ID : " << setw(3) << itr->Money::getUserId() << endl;
                cout << "ID : " << setw(8) << itr->Money::getTransactionId() << endl;
                cout << "Amount : " << setw(5) << itr->Money::getAmount() << endl;
                cout << "Date : " << setw(10) << itr->Money::getDate() << endl;
                cout << "Details : " << setw(5) << itr->Money::getDetails() << endl << endl;
            }
        }
    }else if (firstDateGivenByUser < secondDateGivenByUser){
        cout << "Wyciag z wszystkich transakcji pomiedzy : " << firstDateGivenByUser << " and " << secondDateGivenByUser << endl;
        cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
        for(;itr!=transactions.end();itr++){
            int dateTemp = itr->Money::getDate();
            if((dateTemp <= secondDateGivenByUser) && (dateTemp >= firstDateGivenByUser)){
                cout << "USER ID : " << setw(3) << itr->Money::getUserId() << endl;
                cout << "ID : " << setw(8) << itr->Money::getTransactionId() << endl;
                cout << "Amount : " << setw(5) << itr->Money::getAmount() << endl;
                cout << "Date : " << setw(10) << itr->Money::getDate() << endl;
                cout << "Details : " << setw(5) << itr->Money::getDetails() << endl << endl;
            }
        }
    }else if (firstDateGivenByUser == secondDateGivenByUser){
        cout << "Obie podane daty sa takie same." << endl;
        cout << "Bilans z jednego dnia : " << endl;
        cout << "//////////////////////////////////" << endl;
        for(;itr!=transactions.end();itr++){
            int dateTemp = itr->Money::getDate();
            if((dateTemp == secondDateGivenByUser) && (dateTemp == firstDateGivenByUser)){
                cout << "USER ID : " << setw(3) << itr->Money::getUserId() << endl;
                cout << "ID : " << setw(8) << itr->Money::getTransactionId() << endl;
                cout << "Amount : " << setw(5) << itr->Money::getAmount() << endl;
                cout << "Date : " << setw(10) << itr->Money::getDate() << endl;
                cout << "Details : " << setw(5) << itr->Money::getDetails() << endl << endl;
            }
        }
    }else{
        cout << "Cos poszlonie tak ....." << endl;
        cout << "Powrot do porzedniego Menu." << endl;
        return;
    }
}

void MoneyManager::printThisMonthBalance(){
    int thisMonth = DatesManager::extractMonthFromGivenDate(DatesManager::getTodaysDate());

    vector <Money> transactions;
    transactions.clear();

    transactions.insert(transactions.end(), incomes.begin(), incomes.end());
    transactions.insert(transactions.end(), expenses.begin(), expenses.end());

    vector <Money>::iterator itr = transactions.begin();

    sort(transactions.begin(), transactions.end(), [](Money& elierDate, Money& laterDate) {
    return elierDate.getDate() < laterDate.getDate();
    });

    cout << "Wyciag z wszystkich transakcji z miesiaca bierzacego : " << thisMonth << endl;
    cout << "////////////////////////////////////////////////////////////" << endl;

    if(!transactions.empty()){
        for(;itr!=transactions.end();itr++){
            int readDateMonth = DatesManager::extractMonthFromGivenDate(itr->Money::getDate());
            if(thisMonth == readDateMonth){
                cout << "USER ID : " << setw(3) << itr->Money::getUserId() << endl;
                cout << "ID : " << setw(8) << itr->Money::getTransactionId() << endl;
                cout << "Amount : " << setw(5) << itr->Money::getAmount() << endl;
                cout << "Date : " << setw(10) << itr->Money::getDate() << endl;
                cout << "Details : " << setw(5) << itr->Money::getDetails() << endl << endl;
            }
        }
    }else{
        cout << "W tym miesiacu nie przeprowadzono zadnych transakcji " << endl;
    }
}

void MoneyManager::printLastMonthBalance(){
    int lastMonth = DatesManager::extractMonthFromGivenDate(DatesManager::getTodaysDate())-1;

    vector <Money> transactions;
    transactions.clear();

    transactions.insert(transactions.end(), incomes.begin(), incomes.end());
    transactions.insert(transactions.end(), expenses.begin(), expenses.end());

    vector <Money>::iterator itr = transactions.begin();

    sort(transactions.begin(), transactions.end(), [](Money& elierDate, Money& laterDate) {
    return elierDate.getDate() < laterDate.getDate();
    });

    cout << "Wyciag z wszystkich transakcji z zeszlego miesiaca : " << lastMonth << endl;
    cout << "////////////////////////////////////////////////////////////" << endl;

    if(!transactions.empty()){
        for(;itr!=transactions.end();itr++){
            int readDateMonth = DatesManager::extractMonthFromGivenDate(itr->Money::getDate());
            if(lastMonth == readDateMonth){
                cout << "USER ID : " << setw(3) << itr->Money::getUserId() << endl;
                cout << "ID : " << setw(8) << itr->Money::getTransactionId() << endl;
                cout << "Amount : " << setw(5) << itr->Money::getAmount() << endl;
                cout << "Date : " << setw(10) << itr->Money::getDate() << endl;
                cout << "Details : " << setw(5) << itr->Money::getDetails() << endl << endl;
            }
        }
    }else{
        cout << "W zeszlym miesiacu nie przeprowadzono zadnych transakcji " << endl;
    }
}
