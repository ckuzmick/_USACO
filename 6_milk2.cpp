/*
ID: 27ckuzm1
TASK: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

class farmer {
    public:
        int timeIn;
        int timeOut;
};

farmer splitTimes(string data) {
    istringstream iss(data);

    farmer newFarmer;

    iss >> newFarmer.timeIn >> newFarmer.timeOut;

    cout << newFarmer.timeIn << endl << newFarmer.timeOut << endl;

    return newFarmer;
}

int main() {
    // get data from input

    ifstream inputFile;
    inputFile.open ("milk2.in");
    string stringNum;
    getline (inputFile, stringNum);
    int num = stoi (stringNum); // get number of farmers/cows

    int i = 0;

    vector<farmer> farmerTimes;

    while (i < num) {
        string rawString; // create string to store raw data
        
        getline (inputFile, rawString); // get data

        farmerTimes.push_back(splitTimes(rawString)); // add new object to vector

        ++i;
    }

    inputFile.close ();
    
    // find longest times

    int withoutMilking;
    int withMilking;

    i = 0;

    while (i < num) {
        int start = farmerTimes[i].timeIn;
        int end = farmerTimes[i].timeOut;
    }

    return 0;
}