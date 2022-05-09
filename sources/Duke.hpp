// Duke
#include <string>
#include "Player.hpp"
using namespace std;
#pragma once

namespace coup
{
    class Player;
    class Game;
    class Duke : public Player
    {
    protected:

    public:
        Duke(Game &game, string name);
        void tax();
        void block(Player &player);
    };
}