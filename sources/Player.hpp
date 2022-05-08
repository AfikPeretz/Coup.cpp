#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Game.hpp"
#define incomeBonus 1
#define couPrice 7
#define foreignAidBonus 2
using namespace std;



namespace coup {
    class Player {
        friend class Game;
        friend class Ambassador;
        friend class Captain;
        friend class Contessa;
        friend class Duke;
      
        protected:
            Game& game;
            vector<string> bR;
            size_t coin;
            string roleName;
            bool canGetHurt;
            bool isPlaying;
            bool isAlive;
            size_t playerNumber;
            string name;


        public: 
            Player(Game &game, string name, string roleName) : game(game), name(name), bR(vector<string>()), roleName(roleName), coin(0), canGetHurt(false), isPlaying(true), isAlive(true), playerNumber(0){}
            void income();
            void foreign_aid();
            void coup(Player &p);
            int coins();
            string role();
            bool dead();
            void revive();
    };
}
