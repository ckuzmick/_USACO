#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

#define MAXNUMS 12

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

vector<string> getNames() {
    vector<string> names;

    if (level == 1) {
        // make string
    }
    else {
        // getNames(level-1)
    }

    return names;
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

    while (i[0] < 3) {
        i[1] = 0;
        
        while (i[1] < 3) {
            i[2] = 0;

            while (i[2] < 3) {
                i[3] = 0;

                while (i[3] < 3) {
                    cout << makeString(numbers, digits, stringNum, i) << ' ';

                    ++i[3];
                }   

                ++i[2];
            }

            ++i[1];
        }
        
        ++i[0];
    }

    // cout << names[0] << endl;

    // check each name with file;

    // return good ones;

    return 0;
}