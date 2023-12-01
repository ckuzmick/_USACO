/*
ID: 27ckuzm1
TASK: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string getString(char x) {
    string s(1, x);
    return s;   
}

int main() {
    // Get input

    ifstream inputFile;
    inputFile.open ("beads.in");
    string strBeads;
    getline (inputFile, strBeads);
    int numBeads = stoi (strBeads);
    string allBeads;
    getline (inputFile, allBeads);
    inputFile.close();

    // Get beads into array objects of strings of certain colors
    
    int i = 1;
    int workingItem = 0;
    vector<string> pairsBeads;

    pairsBeads.push_back(getString(allBeads[0]));

    if (pairsBeads[0] == "w") {
        bool firstError = true;
        while (firstError) {
            pairsBeads[0] += allBeads[i];

            if (pairsBeads[0].back() != 'w') {
                firstError = false;
            }

            ++i;
        }
    }

    while (i < numBeads) {
        if (allBeads[i] == 'w' || pairsBeads[workingItem][0] == allBeads[i]) {
            pairsBeads[workingItem] += allBeads[i];
        } else {
            pairsBeads.push_back(getString(allBeads[i]));
            ++workingItem;
        }

        ++i;
    }

    if (pairsBeads[0].find(pairsBeads.back()[0]) != string::npos) {
        pairsBeads[0] += pairsBeads.back();
        pairsBeads.pop_back();
    }

    // Loop through and find the largest one

    int objectsIndexer = 1;
    int maxBeads = pairsBeads.back().size() + pairsBeads[0].size();
    int obj1 = pairsBeads.size() - 1;
    int obj2 = 0;

    while (objectsIndexer < pairsBeads.size()) {
        if (maxBeads < (pairsBeads[objectsIndexer].size() + pairsBeads[objectsIndexer - 1].size())) {
            maxBeads = pairsBeads[objectsIndexer].size() + pairsBeads[objectsIndexer - 1].size();

            obj1 = objectsIndexer - 1;
            obj2 = objectsIndexer;
        }
        ++objectsIndexer;
    }

    if (obj1 == 0) {
        bool obj2going = true;

        while (obj2going) {
            if (pairsBeads.back()[pairsBeads.back().length() - 1] == 'w') {
                ++maxBeads;
            } else {
                obj2going = false;
            }
        }
    }

    bool obj1going = true;
    
    while (obj1going) {
        if (pairsBeads[obj1 - 1][pairsBeads[obj1 - 1].length() - 1] == 'w') {
            pairsBeads[obj1 - 1].pop_back();
            ++maxBeads;
        } else {
            obj1going = false;
        }
    }

    bool obj2going = true;
    
    while (obj2going) {
        if (pairsBeads[obj2 + 1][pairsBeads[obj2 + 1].length() + 1] == 'w') {
            pairsBeads[obj2 + 1].pop_back();
            ++maxBeads;
        } else {
            obj2going = false;
        }
    }

    ofstream outputFile;
    outputFile.open("beads.out");
    outputFile << maxBeads + 1 << "\n";
    outputFile.close();

    return 0;
}