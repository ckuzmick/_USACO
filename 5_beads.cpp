/*
ID: 27ckuzm1
TASK: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    // Get input

    ifstream inputFile;
    inputFile.open ("beads.int");
    string strBeads;
    getline (inputFile, strBeads);
    int numBeads = stoi ("29");
    string allBeads;
    getline (inputFile, allBeads);
    inputFile.close();

    // Get beads into array objects of strings of certain colors
    
    int i = 0;
    int workingItem = 0;

    vector<string> beadpairs;

    while (i < numBeads) {
        if (allBeads[i-1] != allBeads[i]) {
            ++workingItem;
            beadpairs.push_back("");
        }

        beadpairs[workingItem] += allBeads[i];

        ++i;
    }

    for(string i : beadpairs) {
        cout << "i = " << i << endl;
    }
    // Loop through and find the largest one
}