#include "Duke.hpp"

namespace coup {

    void Duke::tax(){
        if (this->game.turn() != this->name){
            throw invalid_argument("Wait to your turn!");
        }
        this->coin = this->coin + DukeTax;
        this->game.endTurn();
    }

    void Duke::block(Player &p){
        p.coin = p.coin - foreignAidBonus;
        this->game.endTurn();
    }

    Duke::~Duke(){

    }

}