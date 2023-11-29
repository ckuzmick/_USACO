/*
ID: 27ckuzm1
TASK: gift1
LANG: C++                 
*/

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
    vector<string> insertOrder;

    ifstream inputFile("gift1.in");

    string stringPeople;
    getline (inputFile, stringPeople);

    int numPeople = stoi(stringPeople);

    // cout << numPeople << endl;
    int i = 0;
    string people[numPeople];

    while (i < numPeople) {
        string person;
        getline (inputFile, person);
        // cout << person << endl;
        peopleDict.insert({person, 0});
        insertOrder.push_back(person);
        i++;
    }

    int indexer = 0;

    while (indexer < numPeople) {
        // get gift giver
        string giftGiver;
        getline (inputFile, giftGiver);

        // cout << giftGiver << endl;

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
        int BACK;
        int APP;

        if (numOfRecievers == 0) {
            BACK = 0;
            APP = 0;
        } else {
            BACK = amount % numOfRecievers;
            APP = ceil(amount / numOfRecievers);
        }
        
        peopleDict[ giftGiver ] -= amount;
        peopleDict[ giftGiver ] += BACK;

        // cout << APP;

        i = 0;

        // grab gift recievers
        while (i < numOfRecievers) {
            string person;
            getline (inputFile, person);
            // cout << person << endl;
            // cout << person;
            peopleDict[ person ] += APP;
            i++;
        }

        indexer++;

        // cout << amount << giftGiver << recievers << endl << APP << endl;
    }

    ofstream outputFile;
    outputFile.open("gift1.out");

    for (int i = 0; i < insertOrder.size(); ++i) {
        const string &s = insertOrder[i];
        outputFile << s << ' ' << peopleDict[s] << '\n';
    }

    // for (auto itr = peopleDict.begin(); itr != peopleDict.end(); ++itr) {
    //   outputFile << itr->first << " " << itr->second << endl;
    // }

    while (getline (inputFile, line)) {
        array.push_back(line);
    }

    inputFile.close();
    outputFile.close();

    return 0;
}