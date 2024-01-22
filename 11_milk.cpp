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

    // get total amount

    int total = 0;
    int milkGathered = 0;

    while (milkGathered < n) {
        int cheapestIndex = farms[0].price;

        for (auto &item : farms) {
            if cheapestIndex >= item.price {
                cheapestIndex = item.price;
            }
        }

        milkGathered += farms.amount;
        total += farms.totalCost();

        farms.erase(farms.begin() + (cheapestIndex-1))
    }

    // output total

    ofstream output;
    output.open("milk.out");
    output << total << endl;
    output.close();

    return 0;
}