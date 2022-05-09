#include "Player.hpp"
#include "Game.hpp"
using namespace coup;
using namespace std;


/*
in every action check:
1.the player is alive
2.the game is active and with more then 2 players
3.the player play in his turn and do action with other players in the same game
4.increament the game turn by one
5.if the player have enough money for his action
6.check if the player have more than 10 coins

after every action check:
1.increament the turn by one
2.save what action this player did and for who

check that every class has the role function
*/



namespace coup {

    Player::Player(Game &g, string name,const string &cardN) {
        int const maxPlayers = 6;
        vector<string> players = g.players();
        //cout << "size:" << players.size() << endl;
        // if(find(players.begin(), players.end(), name) == players.end()) {
        //     throw runtime_error("there is already a player with this name. pick an another name");
        // }
        if(players.size() == maxPlayers) {
            throw runtime_error("there is already 6 players in the game");
        }
        // if(g.get_turn() == -1) {
        //     throw runtime_error("the game is already started");
        // }
        this->alive = true;
        this->last_action_opp = "null";
        this->last_action_player= NULL;
        this->name = move(name);
        this->coinsAmount = 0;
        this->Cardname=cardN;
        g.add_player(this);
        this->game = &g;
        this->howMuchSteal = 0;
        //cout << "1" <<endl;
    }
    
    void Player::income() {
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
        this->coinsAmount++;
        this->last_action_opp = "income";
        this->game->set_turn();
    }
    
    void Player::foreign_aid() {
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
        this->coinsAmount+=2;
        this->last_action_opp = "foreign_aid";
        this->game->set_turn();
    }
    
    void Player::coup(Player &player) {
        int const cost_coup = 7;
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
        if(this->coins() < cost_coup) {
            throw runtime_error("you dont have enough money");
        }
        if(!player.alive) {
            throw runtime_error("the player is already dead");
        }
        player.alive = false;
        this->coinsAmount-=cost_coup;
        this->last_action_opp = "coup_cant_be_block";
        this->last_action_player = &player;   
        this->game->set_turn();      
    }

    void Player::check10coins() const{
        int const checkcoins= 10;
        if(this->coins() >= checkcoins) {
            throw runtime_error("you have to do coup");
        }
    }
    
    string Player::role() {
        return Cardname ;
    }
    
    int Player::coins() const {
        return this->coinsAmount;
    }
    
    Player::~Player() {}
}
