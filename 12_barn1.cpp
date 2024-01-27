#include <fstream>
#include <iostream>

using namespace std;

int main() {
    unsigned int maxBoards, totalStalls, totalCows;
    ifstream input;
    input.open("barn1.in");
    input >> maxBoards >> totalStalls >> totalCows;
    int arrayCows[totalCows];
    for (int i = 0; i < totalCows; ++i) {
        input >> arrayCows[i];
    }
    input.close();

    int gaps[totalCows-1];

    for (int i = 0; i < maxBoards-1; ++i) {
        int longestGap = 0;
        for (int j = 0; j < totalCows-1; ++j) {
            if (arrayCows[j+1] - arrayCows[j] > longestGap) {
                longestGap = arrayCows[j+1] - arrayCows[j];
            }
        }
        gaps[i] = longestGap;
        cout << longestGap << endl;
    }

    return 0;
}