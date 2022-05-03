#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Player.hpp"
#define assassinCoup 3
using namespace std;



namespace coup {
    class Assassin: public Player {
        private:
            

        public:
            Assassin(Game, string): Player(game, name, "Assassin"){
                this -> game.addPlayer(*this);
            }
            void coup(Player &p);
            ~Assassin();
            
    };
}
