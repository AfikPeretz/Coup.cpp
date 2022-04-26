#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Game.hpp"
#include "Player.hpp"
using namespace std;



namespace coup {
    class Player {
        protected:
            string name;
            string role_name;
            bool isPlaying;
            Game game;
            int lastMove;
                
            

        public:
            Player(Game game, string player_name) {} 

            void income();
            void foreign_aid();
            void coup(Player &player);
            void die();
            void revive();
            int coins();
            void role();

    };
}
