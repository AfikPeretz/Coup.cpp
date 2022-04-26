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
            Ambassador(Game, string);
            void income();
            void foreign_aid();
            void block(Player);
            void transfer(Player, Player);
    };
}
