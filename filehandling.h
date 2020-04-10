#ifndef FileHandling
#define FileHandling

#include<iostream>
#include<fstream>
using namespace std;
class fh{
    private:

    public:
        fstream Database;
        //creating function to be called when data is stored
        void AddInputDataToFile();

};
#endif