#include "Captain.hpp"
using namespace coup;

namespace coup {
    Captain::Captain(Game &game,string name) : Player(game,move(name),"Captain") {
    }
    
    void Captain::steal(Player &player){
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
        if(!player.alive) {
            throw runtime_error("the player is already dead");
        }
        if(player.coins() >=2) {
            player.coinsAmount -= 2;
            this->coinsAmount += 2;
            this->howMuchSteal=2;
        } else if(player.coins() == 1) {
            player.coinsAmount -= 1;
            this->coinsAmount += 1;
            this->howMuchSteal = 1;        
        } else {
            this->howMuchSteal = 0;        
        }
        this->last_action_opp = "steal";
        this->last_action_player = &player;
        this->game->set_turn();
    }

    void Captain::block(Player &player){
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
        if(!player.alive) {
            throw runtime_error("the player is already dead");
        }
        //this->check10coins();
        if (player.last_action_opp != "steal") {
            throw runtime_error("cant block not steal action");
        } 
        player.last_action_player->coinsAmount += 2;
        this->coinsAmount-=2;
        this->last_action_opp = "block";
        this->last_action_player = &player;
        //this->game->set_turn();
    }
    
    
}