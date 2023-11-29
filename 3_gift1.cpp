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
        // get gift giver
        string giftGiver;
        getline (inputFile, giftGiver);

        cout << giftGiver << endl;

        // get line of nums and process it into variables
        string lineUnprocesssed;
        getline (inputFile, lineUnprocesssed);

        string token;
 
        stringstream ss(lineUnprocesssed);

        vector<string> num;

        while (getline(ss, token, ' ')) {
            num.push_back(token);
        }
        
        int amount = stoi(num[0]);
        int numOfRecievers = stoi(num[1]);

        // transform variables into needed ones
        int APP = ceil(amount / numOfRecievers);
        int BACK = amount % numOfRecievers;

        // grab gift recievers
        while (i < numOfRecievers) {
            string person;
            getline (inputFile, person);
            // cout << person << endl;
            peopleDict[ person ] = APP;
            i++;
        }

        // cout << amount << giftGiver << recievers << endl << APP << endl;
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