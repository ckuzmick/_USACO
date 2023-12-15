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

int main() {
    ifstream input;
    input.open("milk.in");
    string data;
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

    return 0;
}