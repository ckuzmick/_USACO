/*
ID: 27ckuzm1
TASK: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // get base

    ifstream input;
    input.open("palsquare.in");
    string baseString;
    input >> baseString;
    input.close();
    int base = stoi(baseString);

    cout << base << endl;
    
    return 0;
}
