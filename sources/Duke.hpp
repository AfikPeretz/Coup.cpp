#include "Player.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>

class coup::Duke : public coup::Player{
    friend class Captain;
    friend class Contessa;
    private: 
        bool flag;
        int size;

    public:
        Duke(coup::Game &game, string pn) : Player(game, pn, "Duke"){
            flag = true;
            game.addParticipants(*this);
            size = 0;
        }
        void block(Player &);
        void tax();
        
        
};
