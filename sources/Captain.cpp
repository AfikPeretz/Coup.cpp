#include "Captain.hpp"



namespace coup {

    void Captain::steal(Player &p){
        if (this->game.turn() != this -> name){
            throw invalid_argument("Wait to your turn!");
        }
        if (p.coin < captainsteal){
            throw invalid_argument("not have enough balance");
        }
        if (p.coin >= maxCapacity){
            throw invalid_argument("coup is not a choice!");
        }
        if (p.coin >= captainsteal && this -> game.turn() == this -> name ){
            this -> coin = this->coin + captainsteal;
            p.coin =  p.coin - captainsteal;
            this -> game.addB(this, "Ambassador");
            this -> game.addB(this, "Captain");
            this -> bS = &p;
            this -> game.endTurn();
        }
        else if (this -> game.turn() == this -> name){
            this->coin = this->coin + p.coin;
            p.coin = 0;
            this->game.endTurn();
        }
    }



    void Captain::block(Player &p){
        int x = 0;
        if (!this->game.blockPosibly(p, "Captain")){
           throw invalid_argument("can not block!");
        }
        if ( !this->game.blockPosibly(p, "Ambassador")){
           throw invalid_argument("can not block!");
        }
        p.coin = p.coin - captainsteal;
        x++;
        Captain &captain = dynamic_cast<Captain &>(p); 
        captain.bS -> coin += captainsteal;
        
    }


}