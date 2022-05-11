#include "Assassin.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Captain.hpp"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void coup::Assassin::coup(coup::Player &p){
    if (this -> coin >= couPrice && p.iStilNotDead() ){
        this -> coin -= couPrice;
        p.flag1 = true;
        p.dead();
        p.flag2 = false;
        this -> game.endThisTurn();
    }
    else if (p.iStilNotDead() && this -> coin < couPrice && this -> coin >= assp){
        this -> coin -= assp;
        p.dead();
        p.flag1 = true;
        this -> game.insertToBlockableList(this, "Contessa");
        p.flag2 = false;
        this -> sc = &p;
        this -> game.endThisTurn();
    }
    else{
        throw "Player already dead";
    }
}