#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Player.hpp"
#include "Captain.hpp"
using namespace std;



namespace coup {
    class Ambassador: public Player {
        private:
            

            

        public:
            Ambassador(Game &game, string name): Player(game, name, "Ambassador"){

            }
            void transfer(Player &player1, Player &player2){}
            void TheftBlocking(Captain &Captain){}
    };
}
