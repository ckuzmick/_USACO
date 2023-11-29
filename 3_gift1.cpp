#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string line;
    vector<string> array;
    vector<string> people;

    ifstream inputFile("./gift1.in");

    string stringPeople;
    std::getline (inputFile, stringPeople);

    int numPeople = stoi(stringPeople);

    cout << numPeople;

    while (getline (inputFile, line)) {
        array.push_back(line);
    }

    inputFile.close();

    return 0;
}