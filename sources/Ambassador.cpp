#include "Ambassador.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Captain.hpp"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void coup::Ambassador::block(coup::Player &p){
    p.flag2 = true;
    if (this -> game.Blockable(p, "Ambassador")){
        p.coin = p.coin - cs;
        p.flag1 = true;
        coup::Captain &captain = dynamic_cast<Captain &>(p); 
        captain.stf->coin =  captain.stf->coin + cs;
    }
    else{
        p.flag1 = false;
        throw "can not do this operation";
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void coup::Ambassador::transfer(coup::Player &f, coup::Player &t){
    f.flag1 = true;
    if (this -> coin >= maxCapacity){
        f.flag2 = false;
        throw "must coup";
    }

    if (f.flag1 && f.coin > 0){
        t.coin += 1;
        f.coin -= 1;
        this -> game.endThisTurn();
    }
    
    else{
        throw "you poor";
    }
}


