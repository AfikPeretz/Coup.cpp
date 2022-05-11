#include "Player.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>


class coup::Ambassador : public coup::Player{
    private: 
        bool flag;
        int size;


    public:
        Ambassador(coup::Game &game, string pn) : Player(game, pn, "Ambassador"){
            flag = true;
            this -> game.addParticipants(*this);
            size = 0;
        }


        void block(coup::Player &);
        void transfer(coup::Player &, coup::Player &);
    
};
