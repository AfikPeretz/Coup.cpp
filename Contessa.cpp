#include "Contessa.hpp"

namespace coup {

    void Contessa::AssassinationBlock (Assassin &assassin){
        if (this->game.turn() != this->name){
            throw invalid_argument("Wait to your turn!");
        }
        assassin.coin = assassin.coin + assassinCoup;
        this -> isAlive = true;
        this -> revive();
        this -> game.endTurn();
    }

    Contessa::~Contessa(){
        
    }

}