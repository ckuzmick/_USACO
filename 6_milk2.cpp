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
#include <vector>
#include <algorithm>

using namespace std;

struct farmer {
    public:
        int timeIn;
        int timeOut;
};

farmer splitTimes(string data) {
    istringstream iss(data);

    farmer newFarmer;

    iss >> newFarmer.timeIn >> newFarmer.timeOut;

    // cout << newFarmer.timeIn << endl << newFarmer.timeOut << endl;

    return newFarmer;
}

bool covered(double time, const vector<farmer>& array) {
    time += .5;

    for (const farmer& i : array) {
        if (time > i.timeIn && time < i.timeOut) {
            return true;
        }
    }

    return false;
}

int findLongest(const string& str, char target) {
    int maxLength = 0;
    int currentLength = 0;

    for (char currentChar : str) {
        if (currentChar == target) {
            // Increment the current streak
            ++currentLength;
        } else {
            // Reset the current streak if the character changes
            currentLength = 0;
        }

        // Update the maximum length if needed
        maxLength = std::max(maxLength, currentLength);
    }

    return maxLength;
}


int main() {
    // get data from input

    ifstream inputFile;
    inputFile.open ("milk2.in");
    string stringNum;
    getline (inputFile, stringNum);
    int num = stoi (stringNum); // get number of farmers/cows

    int i = 0;

    int largest = 0;
    int smallest = 100000;

    vector<farmer> farmerTimes;

    while (i < num) {
        string rawString; // create string to store raw data
        
        getline (inputFile, rawString); // get data

        farmerTimes.push_back(splitTimes(rawString)); // add new object to vector

        if (farmerTimes.back().timeIn < smallest) {
            smallest = farmerTimes.back().timeIn;
        }

        if (farmerTimes.back().timeOut > largest) {
            largest = farmerTimes.back().timeOut;
        }

        ++i;
    }

    inputFile.close ();

    // get into string

    i = smallest;

    string all;

    while (i >= smallest && i <= largest) {
        if (!covered(i, farmerTimes)) {
            all += '0';
        } else {
            all += '1';
        }

        ++i;
    }

    all.pop_back();

    cout << largest << ' ' << smallest << endl << all << endl;

    // count out

    int withMilking = findLongest(all, '1');    
    int withoutMilking = findLongest(all, '0');

    // cout << withMilking << ' ' << withoutMilking << endl;

    ofstream outputFile;
    outputFile.open("milk2.out");
    outputFile << withMilking << ' ' << withoutMilking << "\n";
    outputFile.close();

    return 0;
}