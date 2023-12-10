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
    int quotient = num;

    while (quotient != 0) {
        converted.push_back(numbers[quotient % base]);
        quotient /= base;
    }

    reverse(converted.begin(), converted.end());

    return converted;
}

int main() {
    ifstream input;
    input.open("dualpal.in");
    string data;
    getline(input, data);
    input.close();

    int n;
    int s;

    istringstream iss(data);

    iss >> n >> s;

    int totalCount = 0;

    ofstream output;
    output.open("dualpal.out");

    while (totalCount < n) {
        ++s;
        int palCount = 0;

        int i = 2;

        while (i <= 10) {
            if (isPal(convert(s, i))) {
                palCount++;
            }
            if (palCount == 2) {
                totalCount++;
                output << s << endl;
                break;
            }

            ++i;
        }
    }

    output.close();

    return 0;
}