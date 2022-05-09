#include "Duke.hpp"
using namespace coup;

namespace coup {
    class Player;
    class Duke;
    
    Duke::Duke(Game &game,string name): Player(game,move(name),"Duke") {}
    
    void Duke::tax() {
        if(this->game->get_turn() == -1) {
            throw runtime_error("the game can start with at least 2 players");
        }
        if(this->game->get_players().at((unsigned long)game->get_turn())->name != this->name) {
            throw runtime_error("this is not your turn");
        }
        if(!this->alive) {
            throw runtime_error("you are dead!!");
        }
        this->check10coins();
        this->coinsAmount += 3;
        this->last_action_opp = "tax";
        this->game->set_turn();
    }
    
    void Duke::block(Player &player) {
        if(this->game->get_turn() == -1) {
            throw runtime_error("the game can start with at least 2 players");
        }
        // if(this->game->get_players().at((unsigned long)game->get_turn())->name != this->name) {
        //     throw runtime_error("this is not your turn");
        // }
        if(!this->alive) {
            throw runtime_error("you are dead!!");
        }
        if(player.game != this->game) {
            throw runtime_error("the player and you should be in the same game");
        }
        if(!player.alive) {
            throw runtime_error("the player is already dead");
        }
        //this->check10coins();
        if (player.last_action_opp != "foreign_aid") {
            throw runtime_error("cant block not foreign_aid action");
        } 
        player.alive = true;
        this->last_action_opp = "block";
        this->last_action_player = &player; 
        //this->game->set_turn();
    }

   
}