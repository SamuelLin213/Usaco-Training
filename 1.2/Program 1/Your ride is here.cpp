/*
ID: samueld6
TASK: ride
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string cometName;
    string groupName;

    ifstream inData;
    ofstream outData;

    inData.open("ride.in");
    outData.open("ride.out");

    inData >> cometName;
    inData >> groupName;

    int cometLen = cometName.length();
    int groupLen = groupName.length();

    int count = 0;

    int cometTotal = int(cometName.at(0)) - 64;
    int groupTotal = int(groupName.at(0)) - 64;

    while(count < (cometLen - 1))
    {
      cometTotal *= int(cometName.at(count+1)) - 64;
      count++;
    }
    count = 0;
    while(count < (groupLen - 1))
    {
      groupTotal *= int(groupName.at(count+1)) - 64;
      count++;
    }

    int cometMod = cometTotal % 47;
    int groupMod = groupTotal % 47;

    if(cometMod == groupMod)
    {
      outData << "GO" << endl;
    }
    else
    {
      outData << "STAY" << endl;
    }

    inData.close();
    outData.close();

    return 0;
}
