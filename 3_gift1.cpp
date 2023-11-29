#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string line;
    vector<string> array;

    ifstream inputFile("./gift1.in");

    string stringPeople;
    getline (inputFile, stringPeople);

    int numPeople = stoi(stringPeople);

    cout << numPeople << endl;
    int i = 0;
    string people[numPeople];

    while (i < numPeople) {
        string person;
        getline (inputFile, person);
        cout << person << endl;
        i++;
    }

    while (getline (inputFile, line)) {
        array.push_back(line);
    }

    inputFile.close();

    return 0;
}