#include "Player.hpp"
#include "Duke.hpp"
#include "doctest.h"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace coup;
using namespace std;

TEST_CASE("check") {
    Game game_1{};
    Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};
    CHECK_THROWS(duke.coins());
    CHECK_THROWS(duke.die());
    CHECK_THROWS(duke.foreign_aid());
    CHECK_THROWS(duke.income());
    CHECK_THROWS(duke.tax());
    CHECK_THROWS(duke.revive());
    CHECK_THROWS(duke.role());
    CHECK_THROWS(assassin.coins());
    CHECK_THROWS(assassin.die());
    CHECK_THROWS(assassin.foreign_aid());
    CHECK_THROWS(assassin.income());
    CHECK_THROWS(assassin.revive());
    CHECK_THROWS(assassin.role());
    CHECK_THROWS(ambassador.coins());
    CHECK_THROWS(ambassador.die());
    CHECK_THROWS(ambassador.foreign_aid());
    CHECK_THROWS(ambassador.income());
    CHECK_THROWS(ambassador.revive());
    CHECK_THROWS(ambassador.role());
    CHECK_THROWS(captain.coins());
    CHECK_THROWS(captain.die());
    CHECK_THROWS(captain.foreign_aid());
    CHECK_THROWS(captain.income());
    CHECK_THROWS(captain.revive());
    CHECK_THROWS(captain.role());
    CHECK_THROWS(contessa.coins());
    CHECK_THROWS(contessa.die());
    CHECK_THROWS(contessa.foreign_aid());
    CHECK_THROWS(contessa.income());
    CHECK_THROWS(contessa.revive());
    CHECK_THROWS(contessa.role());

   
}