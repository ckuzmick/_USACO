#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

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
    map<int, char[3]> numbers;
        numbers[2] = {'A', 'B', 'C'};
        numbers[3] = {'D', 'E', 'F'};
        numbers[4] = {'G', 'H', 'I'};
        numbers[5] = {'J', 'K', 'L'};
        numbers[6] = {'M', 'N', 'O'};
        numbers[7] = {'P', 'R', 'S'};
        numbers[8] = {'T', 'U', 'V'};
        numbers[9] = {'W', 'X', 'Y'};

    // fill vector will all possible names;

    // check each name with file;

    // return good ones;

    return 0;
}