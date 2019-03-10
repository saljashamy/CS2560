#include <iostream>
#include <string>
#include "GameOf21.h"
using namespace std;
GameOf21::GameOf21()
{
    computer = 0;
    player = 0;
    die = new Die();
    Game();
}
void GameOf21::diceRoll(int& p, bool display)
{
    die->roll();
    p += die->getValue();
    string print = (display == true) ? ("First Dice: " + to_string(die->getValue())): ("");
    die->roll();
    p += die->getValue();
    print += (display == true) ? ("  Second Dice: " + to_string(die->getValue())) : ("");
    if (display){
        cout << print << endl;
    }
}
void GameOf21::Game()
{
    bool play = true;
    cout << "[Game of 21]" << endl;
    int round = 1;
    while(player < 21 && play)
    {
        cout << "> Round " << round << endl;
        cout << "Computer rolls" << endl;
        GameOf21::diceRoll(computer);
        cout << "Player rolls" << endl;
        GameOf21::diceRoll(player, true);
        cout << "Player sum: " << player << endl;
        cout << "Another round? (Y/N)" << endl;
        char select;
        cin >> select;
        play = (toupper(select) == 'Y') ? true : false;
        round++;
    }
    GameOf21::results();
}
void GameOf21::results()
{
    if (player <= 21 && computer <=21){
        if (player > computer){
            cout << "Player wins: " << player << " Computer sum: " << computer << endl;
        }
        else if (computer > player){
            cout << "Computer wins: " << computer << " Player sum: " << player << endl;
        }
        else{
            cout << "Player ties: " << computer << " Computer ties: " << player << endl;
        }
    } 
    else{
        if (player <= 21){
            cout << "Player wins: " << player << " Computer sum: " << computer << endl;
        }
        else if (computer <= 21){
            cout << "Computer wins: " << computer << " Player sum: " << player << endl;
        }
        else{
             cout << "Player losses: " << computer << " Computer losses: " << player << endl;
        }
    }
}