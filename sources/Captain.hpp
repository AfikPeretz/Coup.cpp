
#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Player.hpp"
#define captainsteal 2
using namespace std;
using namespace coup;



namespace coup {
    class Captain: public Player {
        private:
            

        public:
            Player *bS;
            Captain(Game, string): Player(game, name, "Captain"){
                this -> game.addPlayer(*this);
            }
            void steal(Player &p){}
            void TheftBlocking(Captain &Captain){}
            ~Captain();
        
        friend class Ambassador;
    };
}
