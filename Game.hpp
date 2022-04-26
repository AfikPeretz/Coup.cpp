#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;



namespace coup {
    class Game;
    class Player;
    class Duke;
    class Assassin;
    class Ambassador;
    class Captain;
    class Contessa;

    class Game {
        private:
            


        public:
            vector<string> players();
            Game();
            void add_player(Player &player);
            void print_players();
            string turn();
            
    };
}
