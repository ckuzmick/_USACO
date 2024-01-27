#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    // Read input

    int numCows;
    string finalInfections;

    cin >> numCows;
    cin >> finalInfections;

    // Solve Problem

    int originalCows = 1;

    if (finalInfections.find('0') != string::npos) {
        // do stuff
    }

    // Write Output

    cout << originalCows;

    return 0;
}