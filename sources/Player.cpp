#include <iostream>
#include "Player.hpp"




void coup::Player::income()
{
    if (this->game.turn() == this->name)
    {
        this->n_coins += inc;
        this->game.endThisTurn();
    }
    else
    {
        throw "This is not your turn or you have atleast 10 coins!\n";
    }
}

// get foreign aid
void coup::Player::foreign_aid()
{
    if (this->game.turn() == this->name && this->n_coins < must_coup)
    {
        this->n_coins += aid;
        this->game.insertToBlockableList(this, "Duke");
        this->game.endThisTurn();
    }
    else
    {
        throw "This is not your turn or you have atleast 10 coins!\n";
    }
}

// coup
void coup::Player::coup(Player &player)
{
    if (player.is_alive() && this->n_coins >= coup_price)
    {
        this->n_coins -= coup_price;
        player.die();
        this->game.endThisTurn();
    }
    else
    {
        throw "Player is already dead or you dont have enough coins!\n";
    }
}


// get number of coins
int coup::Player::coins() const { return this->n_coins; }

// get the role of the player
std::string coup::Player::role() const { return this->role_name; }

// check if the player is alive
bool coup::Player::is_alive() const { return this->in_game; }

// die
void coup::Player::die()
{
    this->in_game = false;
}

// revive
void coup::Player::revive()
{
    this->in_game = true;
}