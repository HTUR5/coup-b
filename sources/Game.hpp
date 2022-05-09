#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "Player.hpp"

namespace coup {
    class Player;
    class Game {
        private:
            int _turn;
            vector <Player *> _players;
            //int _winner;        
    
        public:
            Game();
            void turn();
            vector<string> players();
            string winner();
            void add_player(Player *player);
            int get_turn() const;
            void set_turn();
            vector<Player *> get_players();
            ~Game();
    };
} 