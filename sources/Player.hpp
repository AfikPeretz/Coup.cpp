#pragma once
#include "Game.hpp"
#define couPrice 7
#define incomeBonus 1
#define maxCapacity 10
#define foreignAidBonus 2
#define DukeTax 3
using namespace std;



class coup::Player{
    friend class Duke;
    friend class Captain;
    friend class Contessa;
    friend class Assassin;
    friend class Ambassador;
    friend class Game;
public:
    bool isPlaying;
    int coin;
    bool flag1;
    int pnum;
    string name;
    bool flag2;
    vector<string> bRole;
    string roleName;
    coup::Game &game;
    vector<string> gta;
    Player(coup::Game &game, string name, string roleName = "Player") : name(name), bRole(vector<string>()), pnum(0), game(game), roleName(roleName), coin(0), isPlaying(true) {
        flag1 = true;
        flag2 = false;
    }
    void coup(Player &); 
    void dead();                        
    virtual void aliveagain(); 
    void income();
    string role() const;               
    bool iStilNotDead() const;                    
    void foreign_aid();                                    
    int coins() const;                                          

};