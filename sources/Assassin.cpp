#include "Assassin.hpp"
using namespace coup;

namespace coup {
    class Player;
    class Duke;
    
    Assassin::Assassin (Game &game,string name) : Player(game,move(name),"Assassin") {} 
    
    void  Assassin::coup(Player &player) {
        int const coup_cost = 7;
        if (this->coins() >= coup_cost) {
            Player::coup(player);
            return;
        }
        if(this->game->get_turn() == -1) {
            throw runtime_error("the game can start with at least 2 players");
        }
        if(this->game->get_players().at((unsigned long)game->get_turn())->name != this->name) {
            throw runtime_error("this is not your turn");
        }
        if(!this->alive) {
            throw runtime_error("you are dead!!");
        }
        if(player.game != this->game) {
            throw runtime_error("the player and you should be in the same game");
        }
        if(this->coins() < 3) {
            throw runtime_error("you dont have enough money");
        }
        if(!player.alive) {
            throw runtime_error("the player is already dead");
        }
        player.alive = false;
        this->coinsAmount -= 3;
        this->last_action_opp = "coup";
        this->last_action_player = &player; 
        this->game->set_turn();
    }

}