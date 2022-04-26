#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Player.hpp"
using namespace std;



namespace coup {
    class Assassin: public Player {
        private:
            

        public:
            Assassin(Game, string);
            void income();
            void foreign_aid();
            int coins();
            void block(Player);
            void coup (Player);
            
    };
}
