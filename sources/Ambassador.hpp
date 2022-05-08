#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Captain.hpp"
#ifndef PLAYER_H
#define PLAYER_H
#include "Player.hpp"
#endif
#define captainsteal 2
using namespace std;



namespace coup {
    class Ambassador: public Player {
        private:

        public:
            Ambassador(Game& game, string name): Player(game, name, "Ambassador"){
                this -> game.addPlayer(*this);
            }
            void block(Player &);
            void transfer(Player &p1, Player &p2);
            
    };
}
