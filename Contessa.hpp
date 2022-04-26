#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Player.hpp"
using namespace std;



namespace coup {
    class Contessa: public Player {
        private:
            

        public:
            Contessa(Game, string);
            void income();
            void foreign_aid();
            void block(Player);
            
    };
}
