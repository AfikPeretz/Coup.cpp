#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
#include "Player.hpp"
#include "Assassin.hpp"
#include "Captain.hpp"
#define MaxPlayers 6
#define MinPlayers 2
using namespace std;



namespace coup {
    
    class Game {

        private:
            bool gameRuning;
            vector<string> players; 
            vector<Player* > playerList;
            map<string, vector<Player* >> roles;
            vector<string> roleList = {"Duke", "Assassin", "Ambassador", "Captain", "Contessa"};
            int curPlayer;
            string TheWinner;



        public:
            Game();
            ~Game() {}
            vector<string> players();
            string turn();
            void endTurn();
            string winner();
            void addPlayer(Player &p); 
            void addB(Player* p, const string &);
            bool blockPosibly(Player &p, const string &mr); 
            void removePCBB(); 
    };
}
