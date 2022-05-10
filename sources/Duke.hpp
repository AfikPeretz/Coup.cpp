#include "Player.hpp"


class coup::Duke : public coup::Player
{
public:
    Duke(coup::Game &game, std::string player_name) : Player(game, player_name, "Duke")
    {
        game.addParticipants(*this);
    }
    void tax();
    void block(Player &player);
    ~Duke() {}
};
