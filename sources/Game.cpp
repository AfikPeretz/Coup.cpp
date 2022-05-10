#include <iostream>
#include <stdexcept>
#include "Player.hpp"
#include "Assassin.hpp"
#include "Captain.hpp"




void coup::Game::rbpfl()
{
    coup::Player *player = this->listOfPlayer.at(this->current_player);

    for (auto &pair : this->blockmap)
    {
        std::vector<coup::Player *> &players_by_role = this->blockmap.at(pair.first);
        long i = 0;
        for (coup::Player *p_player : players_by_role)
        {
            if (p_player->name == player->name)
            {
                players_by_role.erase(players_by_role.begin() + i);
            }
            i++;
        }
    }
}

std::vector<std::string> coup::Game::players()
{
    std::vector<std::string> names;
    for (coup::Player *player : this->listOfPlayer)
    {
        if (player->is_alive())
        {
            names.push_back(player->name);
        }
    }

    return names;
}

std::string coup::Game::turn()
{
    return this->listOfPlayer.at(this->current_player)->name;
}

void coup::Game::addParticipants(coup::Player &player)
{
    if (this->listOfPlayer.size() < maximumParticipants && !this->isthegamestart)
    {
        this->listOfPlayer.push_back(&player);
    }
    else
    {
        throw std::runtime_error("Cannot Add More Players!\n");
    }
}

void coup::Game::endThisTurn()
{
    if (this->listOfPlayer.size() <= 1)
    {
        throw "Too few players!\n";
    }
    if (!this->isthegamestart)
    {
        this->isthegamestart = true;
    }

    // get next player that is in game
    this->current_player = (this->current_player + 1) % this->listOfPlayer.size();

    while (!this->listOfPlayer.at(this->current_player)->in_game)
    {
        this->current_player = (this->current_player + 1) % this->listOfPlayer.size();
    }

    this->rbpfl();

    coup::Player &c_player = *this->listOfPlayer.at(this->current_player);

    if (c_player.role_name == "Assassin")
    {
        coup::Assassin &assassin = dynamic_cast<Assassin &>(c_player);
        assassin.last_special_coup = nullptr;
    }
    else if (c_player.role_name == "Captain")
    {
        coup::Captain &captain = dynamic_cast<Captain &>(c_player);
        captain.stole_from = nullptr;
    }
}

void coup::Game::insertToBlockableList(coup::Player *player, const std::string &blocking_role)
{
    this->blockmap.at(blocking_role).push_back(player);
}

bool coup::Game::Blockable(coup::Player &player_to_block, const std::string &my_role)
{
    std::vector<coup::Player *> &potential_players = this->blockmap.at(my_role);
    long i = 0;
    for (const coup::Player *player : potential_players)
    {
        if (player->name == player_to_block.name)
        {
            potential_players.erase(potential_players.begin() + i);
            return true;
        }
        i++;
    }

    return false;
}

std::string coup::Game::winner()
{
    if (this->listOfPlayer.size() <= 1)
    {
        throw "Too few players!\n";
    }

    int counter = 0;
    std::string winner_name;

    for (coup::Player *player : this->listOfPlayer)
    {
        if (player->in_game)
        {
            counter++;
            winner_name = player->name;
        }
    }

    if (counter != 1)
    {
        throw "There are more players in the game!\n";
    }

    return winner_name;
}