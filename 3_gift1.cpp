#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string inputText;

    ifstream inputFile("./gift1.in");

    while (getline (inputFile, inputText)) {
        cout << inputText + "\n";
    }

    inputFile.close();
}