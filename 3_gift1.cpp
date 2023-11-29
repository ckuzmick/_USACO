#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string line;
    vector<string> array;
    vector<string> people;

    ifstream inputFile("./gift1.in");

    string stringPeople;
    getline (inputFile, stringPeople);

    int numPeople = stoi(stringPeople);

    cout << numPeople;

    while (i < numPeople) {
        string person = inputFile[i];
        cout << person;
        i++;
    }

    while (getline (inputFile, line)) {
        array.push_back(line);
    }

    inputFile.close();

    return 0;
}