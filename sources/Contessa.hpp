#include "Player.hpp"


class coup::Contessa : public coup::Player
{
public:
    Contessa(coup::Game &game, std::string player_name) : Player(game, player_name, "Contessa")
    {
        this->game.addParticipants(*this);
    }
    void block(coup::Player &player);
    ~Contessa() {}
};
