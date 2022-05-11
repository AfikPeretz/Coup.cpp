#include "Contessa.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Captain.hpp"
#include "Assassin.hpp"


void coup::Contessa::block(coup::Player &p){
    if (this->game.Blockable(p, "Contessa")){
        coup::Assassin &assassin = dynamic_cast<Assassin &>(p); 
        p.flag1 = true;
        assassin.sc->aliveagain();
        p.flag2 = false;
    }
    else{
        p.flag1 = p.flag2;
        throw "error";
    }
}