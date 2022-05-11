#include "Player.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>


class coup::Contessa : public coup::Player{

    private: 
        bool flag;
        int size;


    public:
        Contessa(coup::Game &game, string pn) :  Player(game, pn, "Contessa"){
            flag = true;
            this->game.addParticipants(*this);
            size = 0;
        }
        void block(coup::Player &);


        

};
