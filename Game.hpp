#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Player.hpp"
using namespace std;



namespace coup {

    class Game {
        protected:
            


        public:
            vector<string> players();
            Game();
            string turn();
            
    };
}
