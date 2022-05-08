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
#define maxCapacity 10
using namespace std;



namespace coup {
    class Player {
        friend class Game;
        friend class Assassin;
        friend class Ambassador;
        friend class Captain;
        friend class Contessa;
        friend class Duke;
      
        protected:
            Game& game;
            vector<string> bR;
            int coin;
            string roleName;
            bool isPlaying;
            bool isAlive;
            int playerNumber;
            string name;
            bool canGetHurt;


        public: 
            Player(Game &game, string name, string roleName = "didnt have yet") : game(game), name(name), bR(vector<string>()), roleName(roleName), coin(0), canGetHurt(false), isPlaying(true), isAlive(true), playerNumber(0){}
            ~Player() {}
            void income();
            void foreign_aid();
            void coup(Player &p);
            int coins();
            string role();
            bool dead();
            virtual void revive();
    };
}
