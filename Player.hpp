#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Game.hpp"
using namespace std;



namespace coup {
    class Player {
        private:
            

        public: 
            void income();
            void foreign_aid();
            void coup(Player &player);
            void die();
            void revive();
            int coins();
            void role();
            void block(Player);
            

    };
}
