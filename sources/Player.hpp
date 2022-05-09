#pragma once
#include <string>
using namespace std;
#include <unordered_map>
#include <array>
#include "Game.hpp"

namespace coup
{
   class Game;
   class Player
   {
   private:
      string Cardname;

   public:
      int howMuchSteal;        
      string last_action_opp;
      Player *last_action_player;
      int coinsAmount;
      bool alive;
      string name;
      Game *game;
      Player(Game &g, string name,const string &cardN);
      void income();
      void foreign_aid();
      virtual void coup(Player &player);
      void check10coins() const;
      string role();
      int coins() const;
      ~Player();
   };
}