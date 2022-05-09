//Ambassador
#pragma once
#include <string>
#include "Player.hpp"
using namespace std;
namespace coup{
    class Ambassador : public Player
    {
    
    
    protected:
      
        Player *last_action_player_b;
    public:
            Ambassador(Game &game,string name);
            void transfer(Player &a, Player &b);
            void PreventSteel(Player  &player);
            void block(Player &player);
    };
    
    
    


}