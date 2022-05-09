#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "Game.hpp"


using namespace std;
using namespace coup;


namespace coup {
    
    class Player;
    
    Game::Game() {   
        this->_turn = -1; 
    }

    void Game::turn() {
        if(this->_turn >= 0) {
            cout << this->_players.at((unsigned long)this->_turn)->name << endl;
        }
    }
    
    vector<string> Game::players() {
        vector<string> players;
        for(unsigned long i = 0; i < this->_players.size(); i++) {
            if(this->_players.at(i)->alive) {
                players.push_back(this->_players.at(i)->name);
            }
        }
        return players;
    }

    std::string Game::winner() {
        if(this->_turn == -1) {
            throw runtime_error("the game was not started");           
        }
        bool firstAlive = false;
        string name = "null";
        for(unsigned long i = 0; i < this->_players.size(); i++) {
            if(this->_players.at(i)->alive && !firstAlive) {
                firstAlive = true;
                name = this->_players.at(i)->name;
            } else if(this->_players.at(i)->alive && firstAlive) {
                throw runtime_error("the player and you should be in the same game");
            }
        }
        return name;
    }

    void Game::add_player(Player *player){
        if(this->_turn > 0) {
            throw runtime_error("the game is already started");
        }
        this->_players.push_back(player);
        if(this->_players.size() == 2) {
            this->_turn = 0;
        }
    }

    int Game::get_turn() const{
        return this->_turn;
    }

    void Game::set_turn(){
        if(this->_turn ==  this->_players.size()-1) {
            this->_turn = 0;
        } else {
            this->_turn +=1;
        }
        if(!(this->_players.at((unsigned long)this->_turn)->alive)) {
            this->set_turn();
        }
    }

    vector<Player *> Game::get_players() {
        return this->_players;
    }

    Game::~Game(){}

}

