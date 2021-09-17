#include <iostream>         
#include <string>
#include "CDominoesAPI.h"
#include "CRandom.h"
using namespace std;

int main()
{
    int playerCount;
    CRandom<int> rando;
    //CDominoesAPI dominoesAPI;
    cout << "Let's play dominoes! How many people are playing?";
    cin >> playerCount;
    //while (playerCount < )
    cout << playerCount << "? Great, let's begin." << endl << endl;

    vector<int> temp;
    for (int i = 0; i < 1000; i++)
    {
        temp.push_back(i);
    }
    rando.shuffle(temp);
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << endl;
    }

}