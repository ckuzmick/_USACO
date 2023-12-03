/*
ID: 27ckuzm1
TASK: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

#define MAXTILES 10

using namespace std;

bool equality(vector< vector<int> > a, vector< vector<int> > b, int size) {
    int x = 0;
    int y = 0;

    while (y < size) {
        while (x < size) {
            if (a[y][x] != b[y][x]) {
                return false;
            }

            ++x;
        }

        ++y;
    }

    return true;
}

vector< vector<int> > rotate(vector< vector<int> > input, int size) {
    vector< vector<int> > building;
    building.resize(size, vector<int>(size, 0));

    int x = 0;
    int y = 0;

    while (y < size) {
        x = 0;

        while (x < size) {
            building[x][y] = input[y][x];

            ++x;
        }

        ++y;
    }

    y = 0;

    while (y < size) {
        reverse(building[y].begin(), building[y].end());

        ++y;
    }

    return building;
}

vector< vector<int> > reflect(vector< vector<int> > input, int size) {
    int i = 0;

    vector< vector<int> > building = input;

    reverse(building.begin(), building.end());

    return building;
}

void printvector(vector< vector<int> > input, int size) {
    int x = 0;
    int y = 0;

    while (y < size) {
        x = 0;

        while (x < size) {
            cout << input[x][y] << ' ';

            ++x;
        }

        cout << endl;

        ++y;
    }
}

int main() {
    // get input n;
    ifstream inputFile;
    inputFile.open ("transform.in");
    string stringNum;
    getline (inputFile, stringNum);
    const size_t n = stoi (stringNum);

    // get the first square;
    vector< vector<int> > inputSquare;
    inputSquare.resize(n, vector<int>(n, 0));

    int y = 0;

    while (y < n) {
        int x = 0;
        string inputLine;
        getline (inputFile, inputLine);

        while (x < n) {
            if (inputLine[x] == '@') {
                inputSquare[x][y] = 0;
            }
            if (inputLine[x] == '-') {
                inputSquare[x][y] = 1;
            }

            ++x;
        }

        ++y;
    }

    // get the second square;
    vector< vector<int> > outputSquare;
    outputSquare.resize(n, vector<int>(n, 0));

    y = 0;

    while (y < n) {
        int x = 0;
        string inputLine;
        getline (inputFile, inputLine);

        while (x < n) {
            if (inputLine[x] == '@') {
                outputSquare[x][y] = 0;
            }
            if (inputLine[x] == '-') {
                outputSquare[x][y] = 1;
            }

            ++x;
        }

        ++y;
    }

    // get all differences and output;

    ofstream outputFile;

    const vector< vector<int> > ninety = rotate(rotate(rotate(inputSquare, n), n), n);

    if (ninety == outputSquare) {
        outputFile.open("transform.out");
        outputFile << '1' << "\n";
        outputFile.close();
        return 0;
    }

    const vector< vector<int> > one_eighty = rotate(rotate(inputSquare, n), n);

    if (one_eighty == outputSquare) {
        outputFile.open("transform.out");
        outputFile << '2' << "\n";
        outputFile.close();
        return 0;
    }

    const vector< vector<int> > two_seventy = rotate(inputSquare, n);

    if (two_seventy == outputSquare) {
        outputFile.open("transform.out");
        outputFile << '3' << "\n";
        outputFile.close();
        return 0;
    }

    const vector< vector<int> > reflected = reflect(inputSquare, n);

    printvector(inputSquare, n);
    cout << endl;
    printvector(reflected, n);
    cout << endl;
    printvector(outputSquare, n);

    if (reflected == outputSquare) {
        outputFile.open("transform.out");
        outputFile << '4' << "\n";
        outputFile.close();
        return 0;
    }

    const vector< vector<int> > rtwo_seventy = rotate(reflect(inputSquare, n), n);
    const vector< vector<int> > rone_eighty = rotate(rotate(reflect(inputSquare, n), n), n);
    const vector< vector<int> > rninety = rotate(rotate(rotate(reflect(inputSquare, n), n), n), n);

    if (rtwo_seventy == outputSquare || rone_eighty == outputSquare || rninety == outputSquare) {
        outputFile.open("transform.out");
        outputFile << '5' << "\n";
        outputFile.close();
        return 0;
    }

    if (inputSquare == outputSquare) {
        outputFile.open("transform.out");
        outputFile << '6' << "\n";
        outputFile.close();
        return 0;
    }

    outputFile.open("transform.out");
    outputFile << '7' << "\n";
    outputFile.close();

    return 0;
}