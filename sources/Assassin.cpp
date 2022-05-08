#include "Assassin.hpp"
#include <iostream>


namespace coup {

    void Assassin::coup(Player &p){
        if (!p.dead() && this->coin < couPrice && this -> coin >= assassinCoup){
            p.dead();
            this-> coin =  this-> coin - assassinCoup;
            this->game.addB(this, "Contessa");
            this->sCoup = &p;
            this->game.endTurn();
        }
        else if (!p.dead() && this->coin >= couPrice){
            p.dead();
            this->coin = this-> coin - couPrice;
            this->game.endTurn();
        }
        else{
            throw invalid_argument ("error\n");
        }
    }

   
}