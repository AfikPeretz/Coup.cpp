#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#ifndef PLAYER_H
#define PLAYER_H
#include "Player.hpp"
#endif
#define DukeTax 3
using namespace std;



namespace coup {
    class Duke: public Player {
        private:
            

        public:
            Duke(Game &game, string name): Player(game, name, "Duke"){
                this -> game.addPlayer(*this);
            }
            void tax();
            void block(Player &p);
    };
}
