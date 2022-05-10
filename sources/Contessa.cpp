#include "Contessa.hpp"

#include "Assassin.hpp"


void coup::Contessa::block(coup::Player &player)
{
    if (this->game.Blockable(player, "Contessa"))
    {
        std::cout << "Can Block Assassin! " << std::endl;
        coup::Assassin &assassin = dynamic_cast<Assassin &>(player); // player must be an Assassin
        assassin.last_special_coup->revive();
    }
    else
    {
        throw "Invalid Block\n";
    }
}