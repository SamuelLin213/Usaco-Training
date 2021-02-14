#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  ifstream inData;
  ifstream outData;
  outData.open("gift1.out");
  inData.open("gift1.in");

  int numPpl; //number of people in the friend group
  int amountSplit; //amount of money to be split among rest of friends
  int pplSplit; //amount of people to split money among
  int gifterLoc; //index of friend that's giving the money
  int receiveLoc; //index of friend receiving
  string receiver; //name of receiver
  int moneyPerPerson; //money given to each person
  int remain; //rest of money to store in gifter's account
  bool found; //whether friend's name has been found
  string name; //name of next friend

  inData >> numPpl;
  string friends[10]; //contains names of friends
  int balances[10] = {0}; //contains balance of each person

  //stores names of friends into array
  for(int i = 0; i < numPpl; i++)
  {
    inData >> friends[i];
  }

  //processes rest of input file
  for(int x = 0; x < numPpl; x++)
  {
    inData >> name >> amountSplit >> pplSplit;
    gifterLoc = 0;
    found = false;
    moneyPerPerson = 0;
    remain = 0;

    while(gifterLoc < numPpl && !found)
    {
      if(friends[gifterLoc].compare(name) == 0)
      {
        found = true;
        break;
      }
      else
        gifterLoc++;
    }

    if(pplSplit != 0) //only executes if gifter chooses to give money
    {
      moneyPerPerson = amountSplit/pplSplit;
      remain = amountSplit % pplSplit;

      for(int y = 0; y < pplSplit; y++)
      {
        inData >> receiver;

        found = false;
        receiveLoc = 0;
        while(receiveLoc < numPpl && !found)
        {
          if(friends[receiveLoc].compare(receiver) == 0)
          {
            found = true;
            break;
          }
          else
            receiveLoc++;
        }
        balances[receiveLoc] += moneyPerPerson;
      }
      balances[gifterLoc] = balances[gifterLoc] + remain - amountSplit;
    }
  }

  //outputs balances
  for(int z = 0; z < numPpl; z++)
  {
    cout << friends[z] << " " << balances[z] << endl;
  }

  inData.close();
  outData.close();
}
