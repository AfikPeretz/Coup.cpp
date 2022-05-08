#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Player.hpp"
#include "Assassin.hpp"
using namespace std;



namespace coup {
    class Contessa: public Player {
        private:
            

        public:
            Contessa(Game &game, string name): Player(game, name, "Contessa"){
                this -> game.addPlayer(*this);
            }
            void block (Player &);
            
           
    };
}
