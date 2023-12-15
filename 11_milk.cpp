/*
ID: 27ckuzm1
TASK: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Farm {
    public:
        int price;
        int amount;

        int totalCost() {
            return price * amount;
        }
};

Farm splitTimes(string data) {
    istringstream iss(data);

    Farm newFarm;

    iss >> newFarm.amount >> newFarm.price;

    return newFarm;
}

bool compareFarm(Farm f1, Farm f2) { 
    return (f1.price > f2.price); 
}

int main() {
    // get data from  document

    ifstream input;
    input.open("milk.in");
    istringstream data;
    getline(input, data);
    istringstream dataStream(data);

    int n;
    int m;

    dataStream >> n >> m;

    vector<Farm> farms;

    for ( int i = 0; i < m; ++i ) {

        string rawString;

        getline( input, rawString );

        farms.push_back(splitTimes(rawString)); 

        cout << farms.back().amount << endl;

    }

    input.close();

    // loop through, order array based of cheapest

    sort(farms.begin(), farms.end(), compareFarm); 

    // get total amount

    int total = 0;
    int milkGathered = 0;

    while (milkGathered < n) {
        milkGathered += farms.back().amount;
        total += farms.back().totalCost();

        if () {

        }

        farms.pop_back();
    }

    // output total

    cout << total << endl;

    return 0;
}