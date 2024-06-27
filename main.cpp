#include <iostream>

#include "BudgetKeeper.h"

using namespace std;

int main()
{
    BudgetKeeper budgetKeeper("Users.xml","Incomes.xml","Expenses.xml");
    char choice;

    while (true)
    {
        if (budgetKeeper.someoneIsLoggedOn() == false)
        {
            choice = budgetKeeper.selectAnOptionFromTheMainMenu();
            switch (choice)
            {
            case '1':
                budgetKeeper.registerAnUser();
                break;
            case '2':
                budgetKeeper.logInTheUser();
                break;
            case '3':
                budgetKeeper.printAllUsers();
                system ("pause");
                system ("cls");
                break;
            case '9':
                exit (0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system ("pause");
                break;
            }
        }
        else if(budgetKeeper.someoneIsLoggedOn())
        {
            choice = budgetKeeper.selectAnOptionFromTheUserMenu();

            switch (choice)
            {
            case '1':
                budgetKeeper.addNewTransaction();
                break;
            case '2':
                //budgetKeeper.printThisMonthBalance();
                break;
            case '3':
                //budgetKeeper.printLastMonthBalance();
                break;
            case '4':
                budgetKeeper.printBalanceOfGivenPeriod();
                break;
            case '5':
                budgetKeeper.printAllToConsole();
                break;
            case '6':
                budgetKeeper.printCurrentbudget();
                system ("pause");
                break;
            case '7':
                //budgetKeeper.changePasswordOfloggedInUser();
                break;
            case '8':
                budgetKeeper.logOutTheUser();
                cout << "Wylogowano cie" << endl;
                system ("pause");
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system ("pause");
                break;
            }
        }
    }
    return 0;
}
