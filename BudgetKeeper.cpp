#include "BudgetKeeper.h"

bool BudgetKeeper::someoneIsLoggedOn(){
    if(userManager.someoneIsLoggedOn()){
        return true;
    }else{
        return false;
    }
}

char BudgetKeeper::selectAnOptionFromTheMainMenu(){
    return HelpingMethodes::selectAnOptionFromTheMainMenu();
}

void BudgetKeeper::registerAnUser(){
    userManager.registerAnUser();
}

void BudgetKeeper::logInTheUser(){
    userManager.loggingIn();
    if(userManager.someoneIsLoggedOn()){
        moneyManager = new MoneyManager(FILE_NAME_WITH_INCOMES,FILE_NAME_WITH_EXPENSES,userManager.getIdOfLoggedUser());
    }
}

void BudgetKeeper::printAllUsers(){
    userManager.printAllUsers();
}

char BudgetKeeper::selectAnOptionFromTheUserMenu(){
    return HelpingMethodes::selectAnOptionFromTheUserMenu();
}

void BudgetKeeper::addNewTransaction(){
    moneyManager->addNewTransaction();
}

void BudgetKeeper::logOutTheUser(){
    moneyManager->clearVectorsWithMoney();
    userManager.setIdOfLoggedUser(0);
}

void BudgetKeeper::printCurrentbudget(){
    cout << endl <<  "Your current budget amounts to : " << moneyManager->getBudget() << endl << endl;
}

void BudgetKeeper::printAllToConsole(){
    moneyManager->printAllToConsole();
}

void BudgetKeeper::printBalanceOfGivenPeriod(){
    moneyManager->printBalanceOfGivenPeriod();
}

void BudgetKeeper::printThisMonthBalance(){
    moneyManager->printThisMonthBalance();
}

void BudgetKeeper::printLastMonthBalance(){
    moneyManager->printLastMonthBalance();
}

void BudgetKeeper::changePasswordOfloggedInUser(){
    userManager.changeLoggedUserPassword();
}
