#include "Player.hpp"


class coup::Ambassador : public coup::Player
{
public:
    Ambassador(coup::Game &game, std::string player_name) : Player(game, player_name, "Ambassador")
    {
        this->game.addParticipants(*this);
    }
    void transfer(coup::Player &from, coup::Player &to);
    void block(coup::Player &player);
    ~Ambassador() {}
};
