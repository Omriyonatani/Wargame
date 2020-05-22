#include "Soldier.hpp"

class FootCommander:public FootSoldier{
    public:
        FootCommander(int player_number) : 
            FootSoldier(player_number){
                this->HP+=50;
                this->activity+=10;
                this->Commander=1;
            }


};