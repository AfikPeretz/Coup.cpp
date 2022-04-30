#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Game.hpp"
#define incomeBonus 1
#define foreignAidBonus 2
using namespace std;



namespace coup {
    class Player {
        protected:
            int coins;
            string name;
            string role_name;
            bool isPlaying;
            Game game;


        public: 
            void income();
            void foreign_aid();
            void coup(Player &player);
            int coins();
            void role();
            

    };
}
