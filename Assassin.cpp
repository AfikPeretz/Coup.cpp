#include "Assassin.hpp"
#include <iostream>


namespace coup {

    void Assassin::coup(Player &p){
        if (this->game.turn() != this->name){
            throw invalid_argument("Wait to your turn!");
        }
        else if (this->coin < assassinCoup){
            throw invalid_argument("You do not have enough coins to perform this operation!");
        }
        else{
            this->coin = this->coin - assassinCoup;
            p.dead();
            this->game.endTurn();
        }
    }

    Assassin::~Assassin(){
        
    }
    

}