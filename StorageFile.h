#ifndef STORAGEFILE_H
#define STORAGEFILE_H
#include <iostream>
#include <fstream>

using namespace std;

class StorageFile{
private:
    const string FILE_NAME;
public:
    StorageFile(string fileName) : FILE_NAME(fileName){};
    string getNameOfFile();
    bool fileIsEmpty();
};

#endif // STORAGEFILE_H
