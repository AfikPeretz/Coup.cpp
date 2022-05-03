
#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Player.hpp"
using namespace std;
using namespace coup;



namespace coup {
    class Captain: public Player {
        private:
            

        public:
            Captain(Game, string): Player(game, name, "Captain"){
                this -> game.addPlayer(*this);
            }
            void steal(Player &player){}
            void TheftBlocking(Captain &Captain){}
        
        friend class Ambassador;
    };
}
