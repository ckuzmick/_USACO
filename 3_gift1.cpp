#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    string line;
    vector<string> array;
    map<string, int> peopleDict;

    ifstream inputFile("./gift1.in");

    string stringPeople;
    getline (inputFile, stringPeople);

    int numPeople = stoi(stringPeople);

    cout << numPeople << endl;
    int i = 0;
    string people[numPeople];

    while (i < numPeople) {
        string person;
        getline (inputFile, person);
        // cout << person << endl;
        peopleDict.insert({person, 0});
        i++;
    }

    // while (true) {
        string giftGiver;
        getline (inputFile, giftGiver);

        cout << giftGiver;

        string lineUnprocesssed;
        getline (inputFile, lineUnprocesssed);

        string token;
 
        stringstream ss(lineUnprocesssed);

        vector<string> num;

        while (getline(ss, token, ' ')) {
            num.push_back(token);
        }
        
        int amount = stoi(num[0]);
        int recievers = stoi(num[1]);

        int APP = ceil(amount / recievers);

        cout << amount << giftGiver << recievers << endl << APP << endl;
    // }

    for (auto itr = peopleDict.begin(); itr != peopleDict.end(); ++itr) {
      cout << itr->first << " " << itr->second << endl;
    }

    while (getline (inputFile, line)) {
        array.push_back(line);
    }

    inputFile.close();

    return 0;
}