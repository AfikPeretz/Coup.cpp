#include "Captain.hpp"

void coup::Captain::steal(coup::Player &player)
{
    if (this->n_coins >= must_coup)
    {
        throw "You have atleast 10 coins you must coup!\n";
    }

    if (this->game.turn() == this->name && player.n_coins >= captain_steals)
    {
        player.n_coins -= captain_steals;
        this->n_coins += captain_steals;
        this->game.insertToBlockableList(this, "Captain");
        this->game.insertToBlockableList(this, "Ambassador");
        this->stole_from = &player;
        this->game.endThisTurn();
    }
    else if (this->game.turn() == this->name && player.n_coins > 0)
    {
        this->n_coins += player.n_coins;
        player.n_coins = 0;
        this->game.endThisTurn();
    }
    else
    {
        throw "Not Enough Coins!\n";
    }
}
void coup::Captain::block(coup::Player &player)
{
    if (this->game.Blockable(player, "Captain") && this->game.Blockable(player, "Ambassador"))
    {
        player.n_coins -= captain_steals;
        coup::Captain &captain = dynamic_cast<Captain &>(player); // player must be a Captain
        captain.stole_from->n_coins += captain_steals;
    }
    else
    {
        throw "Invalid Block\n";
    }
}