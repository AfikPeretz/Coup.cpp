#include "Duke.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Captain.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void coup::Duke::block(coup::Player &p){
    p.flag1 = p.flag2;
    if (this -> game.Blockable(p, "Duke")){

        p.flag2 = true;
        p.coin -= foreignAidBonus;
        p.flag1 = true;
    }
    else{
        p.flag2 = false;
        throw "error";
    }
} 


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void coup::Duke::tax(){
    if(!this -> flag){
        throw "error";
    }
    if (this -> coin >= maxCapacity){
        throw "must coup";
    }
    if (this->game.turn() == this -> name){
        this -> size = DukeTax;
        this->coin += size;
        this->game.endThisTurn();
    }
    else{
        throw "not your turn";
    }
}
