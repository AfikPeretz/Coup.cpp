#include "Ambassador.hpp"
#ifndef CAP_H
#define CAP_H
#include "Captain.hpp"
#endif


namespace coup {
    

    void Ambassador::block(Player &p){
        int x = 0;
        if (!this->game.blockPosibly(p, "Ambassador")){
           throw invalid_argument("can not block!");
        }
        p.coin = p.coin - captainsteal;
        x++;
        Captain &captain = dynamic_cast<Captain &>(p); 
        captain.bS -> coin += captainsteal;
    }



    void Ambassador::transfer(Player &p1, Player &p2){
        if (this->game.turn() != this->name){
            throw invalid_argument("Wait to your turn!");
        }
        if (p1.coin<1){
            throw invalid_argument("not have enough balance");
        }
        if (this->coin >= maxCapacity){
            throw invalid_argument("coup is not a choice!");
        }
        p1.coin = p1.coin -1;
        p2.coin = p1.coin +1;
        this->game.endTurn();
    }
    

}