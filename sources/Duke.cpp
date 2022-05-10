#include "Duke.hpp"

void coup::Duke::tax()
{
    if (this->n_coins >= must_coup)
    {
        throw "You have atleast 10 coins you must coup!\n";
    }

    if (this->game.turn() == this->name)
    {
        this->n_coins += 3;
        this->game.endThisTurn();
    }
    else
    {
        throw "This is not your turn!\n";
    }
}

void coup::Duke::block(coup::Player &player)
{
    if (this->game.Blockable(player, "Duke"))
    {
        std::cout << "Duke Block Successfull!" << std::endl;
        player.n_coins -= aid;
    }
    else
    {
        throw "Invalid Block!\n";
    }
}