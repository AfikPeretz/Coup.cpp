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
#include "Game.hpp"
#define assassinCoup 3
using namespace std;



namespace coup {
    class Assassin: public Player {
        private:
            

        public:
            Player *sCoup;
            Assassin(Game, string): Player(game, name, "Assassin"){
                sCoup = nullptr;
                game.addPlayer(*this);
            }
            void coup(Player &p);
            
    };
}
