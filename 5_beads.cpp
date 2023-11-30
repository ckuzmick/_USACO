/*
ID: 27ckuzm1
TASK: beads
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Get input

    ifstream inputFile;
    inputFile.open ("beads.int");
    string strBeads;
    getline (inputFile, strBeads);
    int numBeads = stoi(strBeads);
    string allBeads;
    getline (inputFile, allBeads);
    inputFile.close();

    // Get beads into array objects of strings of certain colors

    while (i = 0; i < numBeads;) {
        string beadpairs[numBeads];

        if (allBeads[i] == allBeads[i+1] || allBeads[i+1] == 0) {
            beadpairs[] += allBeads[i]
        }
    }

    // Loop through and find the largest one
}