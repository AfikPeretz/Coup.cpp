#include "Ambassador.hpp"



namespace coup {
    

    void Ambassador::TheftBlocking(Captain &Captain){
        if (this->game.turn() != this->name){
            throw invalid_argument("Wait to your turn!");
        }
        Captain.coin = Captain.coin - captainsteal;
        this->coin = coin + captainsteal;
        this->game.endTurn();
    }

    void Ambassador::transfer(Player &p1, Player &p2){
        if (this->game.turn() != this->name){
            throw invalid_argument("Wait to your turn!");
        }
        if (p1.coin<1){
            throw invalid_argument("not have enough balance");
        }
        p1.coin = p1.coin -1;
        p2.coin = p1.coin +1;
        this->game.endTurn();
    }
    

}