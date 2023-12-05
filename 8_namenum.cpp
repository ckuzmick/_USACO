#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

#define MAXNUMS 12

using namespace std;

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

    // fill vector will all possible names;

    int i = 0;

    cout << totalIterations;

    while (i < totalIterations) {
        names.push_back("");

        int itwo = digits - 1;

        cout << ' ';

        while (itwo >= 0) {
            int n = i % numbers[(stringNum[itwo] - '0') - 2].size();
            
            cout << numbers[(stringNum[itwo] - '0') - 2][n];

            --itwo;
        }

        ++i;
    }

    // cout << names[0] << endl;

    // check each name with file;

    // return good ones;

    return 0;
}