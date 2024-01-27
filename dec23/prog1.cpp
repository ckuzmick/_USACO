#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    // Read input

    int numCows, numCanes;
    cin >> numCows >> numCanes;

    vector<int> cowHeights;
    vector<int> caneHeights;

    for (int i = 0; i < numCows; ++i) {
        int digit;
        cin >> digit;
        cowHeights.push_back(digit);
    }

    for (int i = 0; i < numCanes; ++i) {
        int digit;
        cin >> digit;
        caneHeights.push_back(digit);
    }

    // Solve the problem

    for (int& i : caneHeights) {
        int hheight = i;
        int lheight = 0;

        for (int& i : cowHeights) {
            int amt = min(max(0, i - lheight), hheight-lheight);
            lheight = min(max(lheight, i), hheight);
            i += amt;
            // cout << '[' << lheight << ", " << hheight << ", " << i << ']' << endl;   
        }
    }

    // Write output

    for (int& i : cowHeights) {
        cout << i << endl;
    }

    return 0;
}
