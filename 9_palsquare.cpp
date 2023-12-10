/*
ID: 27ckuzm1
TASK: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

void push_back_string(string& str1, string str2) {
    for(int i = 0; str2[i] != '\0'; i++)
    {
        str1.push_back(str2[i]);
    }
}

bool isPal(string numString) {
    int length = numString.length();
    for (int i = 0; i < length / 2; i++) {
        if (numString[i] != numString[length - i - 1]) {
            return false;
        }
    }
    return true;
}

string convert(int num, int base) {
    string numbers = "0123456789ABCDEFGHIJ";
    string converted;
    int quotient = floor(num / base);
    push_back_string(converted, to_string(num % base));

    while (quotient != 0) {
        quotient = floor(quotient / base);
        push_back_string(converted, to_string(quotient % base));
    }

    push_back_string(converted, to_string(quotient % base));
    reverse(converted.begin(), converted.end());

    return converted;
}

int main() {
    // get base

    ifstream input;
    input.open("palsquare.in");
    string baseString;
    input >> baseString;
    input.close();
    int base = stoi(baseString);

    // ofstream output;
    // output.open("palsquare.out");

    // for (int i = 1; i <= 300; i++) {
    //     int square = i * i;
    //     string stringSquare = convert(square, base);

    //     if (isPal(stringSquare)) {
    //         output << convert(i, base) << ' ' << stringSquare << endl;
    //     }
    // }

    // output.close();

    cout << convert(10, 10) << endl;
    
    return 0;
}
