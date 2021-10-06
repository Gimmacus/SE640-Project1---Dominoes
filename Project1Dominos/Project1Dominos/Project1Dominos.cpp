#include <iostream>         
#include <string>
#include "CDominoesAPI.h"
#include "CTable.h"
#include "CRandom.h"
using namespace std;

int main()
{
    int playerCount;
    CTable table;
    cout << "Let's play dominoes! How many people are playing? ";
    cin >> playerCount;
    while (playerCount < table.GameAPI()->MinPlayers() || playerCount > table.GameAPI()->MaxPlayers())
    {
        if (playerCount < table.GameAPI()->MinPlayers())
            cout << "Player count is less than the minimum amount of players. Please try again: ";
        else
            cout << "Player count is more than the maximum amount of players. Please try again: ";
        cin >> playerCount;
    }
    cout << playerCount << " players? Great, let's begin." << endl << endl;
    for (int i = 1; i <= playerCount; i++)
    {
        CPlayer* player = new CPlayer();
        string name = "Player " + to_string(i);
        player->SetPlayerName(name);
        player->setPlayerNumber(i);
        player->setPassed(false);
        table.addPlayerToGame(player);
    }
    table.PlayGame();
    cout << "Looks like that's all for now. Thanks for playing!" << endl;
    system("pause");

    return 0;
}