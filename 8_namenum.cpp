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

    int[digits] iterators = {0, 0, 0, 0}

    while (iterators[0] < 3) {
        while (iterators[1] < 3) {
            while (iterators[2] < 3) {
                while (iterators[3] < 3) {

                    names.push_back(numbers[])

                    ++iterators[3];
                }   

                ++iterators[2];
            }

            ++iterators[1];
        }
        
        ++iterators[0];
    }

    // cout << names[0] << endl;

    // check each name with file;

    // return good ones;

    return 0;
}