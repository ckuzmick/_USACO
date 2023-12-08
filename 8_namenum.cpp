#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

int getDigit(string n, int digit) {
    int result = n[digit] - '0';

    return result - 2;
}

string makeString(vector< vector<char> > reference, int length, string number, vector<int> iterationsArray) {
    string word;
    int iterate = 0;

    while (iterate < length) {
        word.push_back( reference[getDigit(number, iterate)][iterationsArray[iterate]] );

        ++iterate;
    }

    return word;
}

void printAllNames(vector<int>& i, int level, vector< vector<char> >& reference, int digits, string number, vector<string> output) {
    if (level == digits) {
        output.push_back(makeString(reference, digits, number, i));
        return;
    }

    for (int j = 0; j < 3; ++j) {
        i[level] = j;
        printAllNames(i, level + 1, reference, digits, number, output);
    }
}

bool findName(string name, ifstream file) {
    string line;

    while ( getline(file, line) ) {
        size_t pos = line.find(name);
        if ( pos != string::npos)
            return true
    }

    return false;
}

int main() {
    // get input from file;
    ifstream inputFile;
    inputFile.open("namenum.in");
    string stringNum;
    getline(inputFile, stringNum);
    int num = stoi(stringNum);
    inputFile.close();

    // define variables;
    vector<string> names;
    vector< vector<char> > numbers{ 
            {'A', 'B', 'C'},
            {'D', 'E', 'F'},
            {'G', 'H', 'I'},
            {'J', 'K', 'L'},
            {'M', 'N', 'O'},
            {'P', 'R', 'S'},
            {'T', 'U', 'V'},
            {'W', 'X', 'Y'}
        };
    int digits = stringNum.length();
    int totalIterations = pow(3, digits);
    vector<int> i{0, 0, 0, 0};

    // fill vector will all possible names;

    printAllNames(i, 0, numbers, digits, stringNum, names);

    // cout << names[0] << endl;

    cout << names.size() << endl;

    // check each name with file;

    // return good ones;

    return 0;
}