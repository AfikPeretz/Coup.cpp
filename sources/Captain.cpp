#include "Captain.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void coup::Captain::steal(coup::Player &p){
    int x = this -> coin;
    if (x >= maxCapacity){
        throw "must coup";
    }
    p.flag1 = true;
    p.flag2 = false;
    if (this -> game.turn() == this -> name && p.coin >= cs){
        p.coin -= cs;
        this -> coin += cs;
        this -> game.insertToBlockableList(this, "Captain");
        p.flag1 = false;
        this -> game.insertToBlockableList(this, "Ambassador");
        this -> stf = &p;
        p.flag2 = true;
        this -> game.endThisTurn();
    }
    else if (this -> game.turn() == this -> name && p.coin > 0){
        p.flag1 = p.flag2;
        this -> coin += p.coin;
        p.coin = 0;
        this -> game.endThisTurn();
    }
    else{
        throw "you poor";
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void coup::Captain::block(coup::Player &p){
    if (this -> game.Blockable(p, "Ambassador") && this -> game.Blockable(p, "Captain")){
        p.flag1 = true;
        p.coin -= cs;
        coup::Captain &captain = dynamic_cast<Captain &>(p); 
        p.flag2 = false;
        captain.stf -> coin += cs;
        p.flag1 = p.flag2;
    }
    else{
        p.flag1 = p.flag2;
        throw "error";
    }
}