/*
ID: 27ckuzm1
TASK: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

int getDigit(string n, int digit) {
    return n[digit] - '2';
}

string makeString(vector< vector<char> >& reference, int& length, string& number, vector<int>& iterationsArray) {  
    string word;
    int iterate = 0;

    while (iterate < length) {
        word.push_back( reference[getDigit(number, iterate)][iterationsArray[iterate]] );

        ++iterate;
    }

    return word;
}

void getPossibleNames(string& number, vector< vector<char> >& reference, ifstream& dict, vector< vector<string> >& possibleNames){
    dict.open("dict.txt");
    string line;
    bool found = false;

    while ( getline(dict, line) ) {
        if ( line[0] == reference[getDigit(number, 0)][0] )
            possibleNames[0].push_back(line);
        if ( line[0] == reference[getDigit(number, 0)][1] )
            possibleNames[1].push_back(line);
        if ( line[0] == reference[getDigit(number, 0)][2] )
            possibleNames[2].push_back(line);
    }

    dict.close();
}

bool checkName(string& name, vector< vector<string> >& possibleNames) {
    if ( find(possibleNames[0].begin(), possibleNames[0].end(), name) != possibleNames[0].end() )
        return true;
    if ( find(possibleNames[1].begin(), possibleNames[1].end(), name) != possibleNames[1].end() )
        return true;
    if ( find(possibleNames[2].begin(), possibleNames[2].end(), name) != possibleNames[2].end() )
        return true;
    return false;
}

void printAllNames(const string& number, const vector<vector<char>>& reference, vector<string>& output, vector< vector<string> >& possibleNames) {
    int digits = number.size();
    vector<int> indices(digits, 0);

    while (true) {
        string word;
        for (int i = 0; i < digits; ++i) {
            word.push_back(reference[getDigit(number, i)][indices[i]]);
        }

        if (checkName(word, possibleNames)) {
            output.push_back(word);
        }

        // Increment indices
        int i = digits - 1;
        while (i >= 0 && ++indices[i] == 3) {
            indices[i] = 0;
            --i;
        }

        // Check if all indices have been exhausted
        if (i < 0) {
            break;
        }
    }
}

int main() {
    time_t start, end;
    time(&start);

    // get input from file;
    ifstream inputFile;
    inputFile.open("namenum.in");
    string stringNum;
    getline(inputFile, stringNum);
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
    int digits = stringNum.size();
    int totalIterations = pow(3, digits);
    vector<int> i;

    for (int j = 0; j < digits; ++j) {
        i.push_back(0);
    }

    // fill vector will all possible names;

    vector< vector<string> > possibleNames{
        vector<string>(),
        vector<string>(),
        vector<string>()
    };
    ifstream dict;
    getPossibleNames(stringNum, numbers, dict, possibleNames);

    printAllNames(stringNum, numbers, names, possibleNames);

    // check each name with file;

    vector<string> goodNames;

    numbers.clear();
    numbers.shrink_to_fit();
    possibleNames.clear();
    possibleNames.shrink_to_fit();

    // return good ones;

    ofstream outputFile;
    outputFile.open("namenum.out");

    if (names.size() == 0) {
        outputFile << "NONE" << endl;
    } else {
        for (int i = 0; i < names.size(); ++i) {
            outputFile << names[i] << endl;
        }
    }

    outputFile.close();

    time(&end);
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << time_taken << " seconds" << endl;

    return 0;
}