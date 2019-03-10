#ifndef GAMEOF21_H
#define GAMEOF21_H
#include "Die.cpp"

class GameOf21
{
private:
    int player;
    int computer;
    Die* die;
    void Game();
    void diceRoll(int&, bool=false);
    void results();
    
public:
    GameOf21();
};
#endif