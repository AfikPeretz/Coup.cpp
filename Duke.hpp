#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Player.hpp"
using namespace std;



namespace coup {
    class Duke: public Player {
        private:
            

        public:
            Duke(Game, string): Player(){}
            void tax(){}
    };
}
