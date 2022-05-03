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
            Game game;
            int coin;
            string roleName;
            bool canGetHurt;
            bool isPlaying;
            bool isAlive;
            int playerNumber = 0;
            string name;


        public: 
            Player(Game &game, string name, string roleName) : game(game), name(name), roleName(roleName), coin(0), canGetHurt(false), isPlaying(true), isAlive(true), playerNumber(playerNumber +1){}
            void income();
            void foreign_aid();
            void coup(Player &p);
            int coins();
            string role();
            bool dead();
            void revive();
            ~Player();
    };
}
