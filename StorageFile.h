#ifndef STORAGEFILE_H
#define STORAGEFILE_H
#include <iostream>
#include <fstream>

using namespace std;

class StorageFile{
private:
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;
public:
    StorageFile(string incomesFile, string expensesFile)
    : INCOMES_FILE_NAME(incomesFile),EXPENSES_FILE_NAME(expensesFile){};
    string getNameOfFile();
    bool fileIsEmpty();
};

#endif // STORAGEFILE_H
