/*
ID: 27ckuzm1
TASK: milk
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

    iss >> newFarm.price >> newFarm.amount;

    return newFarm;
}

bool compareFarm(Farm f1, Farm f2) { 
    return (f1.price > f2.price); 
}

int main() {
    // get data from  document

    ifstream input;
    input.open("milk.in");
    string data;
    getline(input, data);
    stringstream ss(data);
    int n, m;
    ss >> n >> m;
    cout << n << "\n" << m << endl;

    vector<Farm> farms;

    for ( int i = 0; i < m; ++i ) {
        string rawString;
        getline( input, rawString );
        farms.push_back(splitTimes(rawString)); 
    }

    input.close();

    // loop through, order array based of cheapest

    sort(farms.begin(), farms.end(), compareFarm); 

    // get total amount

    int total = 0;
    int milkGathered = 0;

    while (milkGathered < n) {
        if (farms.back().amount + milkGathered > n) {
            farms.back().amount -= n - milkGathered;
        }

        milkGathered += farms.back().amount;
        total += farms.back().totalCost();

        cout << farms.back().amount << " " << farms.back().price << endl;

        farms.pop_back();
    }

    // output total

    ofstream output;
    output.open("milk.out");
    output << total << endl;
    output.close();

    return 0;
}