/*
ID: 27ckuzm1
TASK: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // get input text
    ifstream inputFile;
    inputFile.open ("friday.in");
    string inputString;
    getline (inputFile, inputString);
    int inputNum = stoi(inputString);
    inputFile.close();
}