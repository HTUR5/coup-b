
//Contessa
#include <string>
#include "Player.hpp"
using namespace std;
#pragma once
namespace coup{
    class Contessa : public Player
    {
     protected:
   
      
   
        public:
            Contessa(Game &game,string name);
            void block(Player &player);
    };
    
    
    


}