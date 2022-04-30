#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
#include "Player.hpp"
#define MaxPlayers 6
#define MinPayers 2
using namespace std;



namespace coup {

    class Game {
        protected:
            vector<Player> playerList;
            int players = playerList.size();



        public:
            Game();
            vector<string> players();
            string turn();
            
    };
}
