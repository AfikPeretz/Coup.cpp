#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Player.hpp"
using namespace std;



namespace coup {
    class Ambassador: public Player {
        private:
            

        public:
            Ambassador() : Player(){}
            Ambassador(Game &game, string): Player(){}
            void transfer(Player, Player){}
    };
}
