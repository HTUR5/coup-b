#include "Ambassador.hpp"
using namespace coup;

namespace coup {
    
    Ambassador::Ambassador(Game &game,string name) : Player(game,move(name),"Ambassador") {
        this->last_action_player_b = NULL;
    }
    
    void Ambassador::transfer(Player &a, Player &b) {
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
        if(a.game != this->game && b.game != this->game) {
            throw runtime_error("the player and you should be in the same game");
        }
        if(!a.alive || !b.alive) {
            throw runtime_error("the players are dead");
        }
        this->check10coins();
        if(a.coins() > 0) {
            a.coinsAmount--;
            b.coinsAmount++;
            this->last_action_opp = "transfer";
            this->last_action_player = &a;
            this->last_action_player_b = &b;
        } else {
            throw runtime_error("a dont have enough money");
        }
        this->game->set_turn();     
    }
    
    void Ambassador::block(Player &player) {
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
        if (player.last_action_opp != "steal") {
            throw runtime_error("cant block not steal action");
        }
        player.last_action_player->coinsAmount += 2;
        player.coinsAmount-=2;
        this->last_action_opp = "block";
        this->last_action_player = &player; 
        //this->game->set_turn();       
    }

    void Ambassador::PreventSteel(Player &player) {
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
        if(player.last_action_opp != "steal") {
            throw runtime_error("you can block just stealing");
        }
        int amount = howMuchSteal;        
        player.last_action_player->coinsAmount += amount;
        player.coinsAmount -= amount;
        this->last_action_opp = "PreventSteel";
        this->last_action_player = &player;
        this->game->set_turn();
    }

    

}