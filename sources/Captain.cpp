#include "Captain.hpp"



namespace coup {

    void Captain::steal(Player &p){
        if (this->game.turn() != this->name){
            throw invalid_argument("Wait to your turn!");
        }
        else if (p.coin < captainsteal){
            throw invalid_argument("not have enough balance");
        }
        else{
            p.coin -= captainsteal;
            this->coin += captainsteal;
            this->canGetHurt = true;
            this->game.endTurn();
        }
    }

    void Captain::TheftBlocking(Captain &Captain){
        if (this->game.turn() != this->name){
            throw invalid_argument("Wait to your turn!");
        }
        Captain.coin = Captain.coin - captainsteal;
        this->coin = coin + captainsteal;
        this->game.endTurn();
    }

    Captain::~Captain(){
        
    }


}