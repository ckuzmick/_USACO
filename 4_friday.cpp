/*
ID: 27ckuzm1
TASK: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    // get input text
    ifstream inputFile;
    inputFile.open ("friday.in");
    string inputString;
    getline (inputFile, inputString);
    int inputNum = stoi(inputString);
    inputFile.close();

    const int months = (inputNum * 12) + 1;
    int i = 0;
    int day = 1;
    int month = 0;
    int year = 1900;

    string order[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    map<string, int> monthsDays;
        monthsDays["January"] = 31;
        monthsDays["February"] = 28;
        monthsDays["March"] = 31;
        monthsDays["April"] = 30;
        monthsDays["May"] = 31;
        monthsDays["June"] = 30;
        monthsDays["July"] = 31;
        monthsDays["August"] = 31;
        monthsDays["September"] = 30;
        monthsDays["October"] = 31;
        monthsDays["November"] = 30;
        monthsDays["December"] = 31;
        
    map<int, string> monthsPlacement;
        monthsPlacement[0] = "January";
        monthsPlacement[1] = "February";
        monthsPlacement[2] = "March";
        monthsPlacement[3] = "April";
        monthsPlacement[4] = "May";
        monthsPlacement[5] = "June";
        monthsPlacement[6] = "July";
        monthsPlacement[7] = "August";
        monthsPlacement[8] = "September";
        monthsPlacement[9] = "October";
        monthsPlacement[10] = "November";
        monthsPlacement[11] = "December";

    map<int, string> days;
        days[0] = "Sunday";
        days[1] = "Monday";
        days[2] = "Tuesday";
        days[3] = "Wednesday";
        days[4] = "Thursday";
        days[5] = "Friday";
        days[6] = "Saturday";
    
    map<string, int> values;
        values["Saturday"] = 0;
        values["Sunday"] = 0;
        values["Monday"] = 0;
        values["Tuesday"] = 0;
        values["Wednesday"] = 0;
        values["Thursday"] = 0;
        values["Friday"] = 0;

    while (i < months) {
        if (i == 0) {
            day += 12;
        }
        else {
            string dayOfWeek = days[day % 7];
            values[dayOfWeek] += 1;

            if (year % 4 == 0 && year % 100 != 0 && month == 1) {
                day += 29;
            } if (year % 400 == 0 && month == 1) {
                day += 29;
            } else {
                day += monthsDays[monthsPlacement[month]];
            }

            if (month == 11) {
                month = 0;
                ++year;
            } else {
                ++month;
            }
        }
        
        ++i;
    }

    ofstream outputFile;

    outputFile.open("friday.out");

    for (int i = 0; i < 6; ++i) {
        const string &s = order[i];
        outputFile << values[s] << ' ';
    }

    outputFile << values[order[6]] << endl;

    outputFile.close();

    return 0;
}