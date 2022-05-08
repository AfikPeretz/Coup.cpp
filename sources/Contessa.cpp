#include "Contessa.hpp"
#ifndef ASSASSIN_H
#define ASSASSIN_H
#include "Assassin.hpp"
#endif

namespace coup {

    void Contessa::block (Player &p){
        if (this->game.turn() != this->name){
            throw invalid_argument("Wait to your turn!");
        }
        size_t x = 0;
        if (this -> game.blockPosibly(p, "Contessa")){
            Assassin &assassin = dynamic_cast<Assassin &>(p);
            x++;
            assassin.sCoup->revive();
        }
        else{
            x++;
            throw invalid_argument("error");
        }
    }


}