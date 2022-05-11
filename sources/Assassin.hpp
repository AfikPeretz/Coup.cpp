#include "Player.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#define assp 3

class coup::Assassin : public coup::Player{
    friend class Game;
    friend class Contessa;
    private: 
        bool flag;
        int size;
        

    public:
        Assassin(coup::Game &game, string pn) : Player(game, pn, "Assassin"){
            sc = nullptr;
            flag = true;
            game.addParticipants(*this);
            size = 0;
        }
        virtual void coup(coup::Player &);
        coup::Player *sc;
        
    
};
