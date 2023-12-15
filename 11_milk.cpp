/*
ID: 27ckuzm1
TASK: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Farm {
    public:
        int price;
        int amount;
}

int main() {
    ifstream input;
    input.open("milk.in");
    string data;
    getline(input, data);
    input.close();

    return 0;
}