#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
#define maximumParticipants 6
namespace coup{class Game; class Player; class Duke; class Assassin; class Ambassador; class Captain; class Contessa;} 







class coup::Game{


    protected:

        bool isthegamestart;
        map < string, vector<coup::Player* >> blockmap;
        bool wtf;
        vector<coup::Player *> listOfPlayer;
        vector<string> roList = {"Duke", "Assassin", "Ambassador", "Captain", "Contessa"};
        bool bts;
        size_t cur_p;                 
        


    public:

        Game() : cur_p(0), isthegamestart(false), wtf(false){
            for (string s : roList){
                bts = true;
                pair<string, vector<coup::Player *>> couple = {s, vector<coup::Player* >()};
                blockmap.insert(couple);
            }
        }

        void endThisTurn();
        string turn();
        void addParticipants(coup::Player &);
        vector<string> players();
        void insertToBlockableList(coup::Player *, const string &);
        string winner();
        bool Blockable(coup::Player &, const string &);
        void rbpfl();
        
};


