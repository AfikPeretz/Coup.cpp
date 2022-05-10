#pragma once
#include "Game.hpp"
#define inc 1
#define aid 2
#define coup_price 7
#define must_coup 10
using namespace std;



class coup::Player{
    friend class Duke;
    friend class Captain;
    friend class Contessa;
    friend class Assassin;
    friend class Ambassador;
    friend class Game;


private:
    int n_coins;
    int idx;
    string name;
    string role_name;
    bool in_game;
    coup::Game &game;
    vector<string> blocking_roles;

public:
    // methods
    Player(coup::Game &game, string player_name, string role_name = "Player") : name(player_name),
                                                                                          n_coins(0),
                                                                                          in_game(true),
                                                                                          game(game),
                                                                                          role_name(role_name),
                                                                                          blocking_roles(vector<string>()),
                                                                                          idx(0) {} // end of constructor

    void income();                    
    void foreign_aid();                
    virtual void coup(Player &player); 
    void die();                        
    void revive();                     
    int coins() const;                       
    string role() const;               
    bool is_alive() const;                   
    ~Player() {}

    
};