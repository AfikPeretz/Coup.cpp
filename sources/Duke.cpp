#include "Duke.hpp"

namespace coup {

    void Duke::tax(){
        if (this->game.turn() != this->name){
            throw invalid_argument("Wait to your turn!");
        }
        if (this -> coin >= maxCapacity){
            throw invalid_argument("you have reached the capacity limit!");
        }
        this -> coin = this -> coin + DukeTax;
        this -> game.endTurn();
    }

    void Duke::block(Player &p){
        if (!this -> game.blockPosibly(p, "Duke")){
            throw invalid_argument("error");
        }
        else{
            p.coin = p.coin + foreignAidBonus;
        }
    }


}