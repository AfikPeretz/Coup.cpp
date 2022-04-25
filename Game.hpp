#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;



namespace coup {
    class Game {
        protected:
            vector<Player> players;


        public:
            Game(){}
            void add_player(Player &player);
            void print_players();
            
    };
}
