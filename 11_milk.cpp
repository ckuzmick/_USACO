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

    iss.clear();

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
        rawString.clear();
        rawString.shrink_to_fit();
    }

    input.close();

    // get total amount

    int total = 0;
    int milkGathered = 0;

    while (milkGathered < n) {
        int cheapestIndex = 0;

        for (int i=0; i < farms.size(); ++i) {
            if (farms[cheapestIndex].price >= farms[i].price) {
                cout << farms[cheapestIndex].price << ' ' << farms[i].price << endl;
                cheapestIndex = i;
            }
        }

        if (milkGathered + farms[cheapestIndex].amount > n) {
            farms[cheapestIndex].amount = n - milkGathered;
            milkGathered = n;
            total += farms[cheapestIndex].price * farms[cheapestIndex].amount;
        } else {
            milkGathered += farms[cheapestIndex].amount;
            total += farms[cheapestIndex].price * farms[cheapestIndex].amount;
        }
        
        farms.erase(farms.begin() + cheapestIndex);
    }

    farms.clear();
    farms.shrink_to_fit();

    // output total

    ofstream output;
    output.open("milk.out");
    output << total << endl;
    output.close();

    return 0;
}