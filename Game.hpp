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
        private:
            vector<Player> playerList;
            map<string, vector<Player* >> roles;
            vector<string> roleList = {"Duke", "Assassin", "Ambassador", "Captain", "Contessa"};
            int curPlayer = 0;

            
            


        public:
            Game();
            vector<string> players();
            string turn();
            string winner();
            void add_player(Player &p);
            ~Game(){}
            
    };
}
