#include "Player.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#define cs 2

class coup::Captain : public coup::Player{
    friend class Game;
    friend class Ambassador;
    private: 
        bool flag;
        int size;
    

    public:
        coup::Player *stf;
        Captain(coup::Game &game, std::string pn) : Player(game, pn, "Captain"), stf(nullptr){
            flag = true;
            this->game.addParticipants(*this);
            size = 0;
        }
        void block(coup::Player &);
        void steal(coup::Player &);
        
        
};
