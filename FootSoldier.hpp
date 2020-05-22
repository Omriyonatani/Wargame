#include "Soldier.hpp"

class FootSoldier:public Soldier{
    public:
        FootSoldier(int player_number) : Soldier(/*(player_number)*/ player_number,/*(HP)*/ 100,/*(Commander)*/ 0, /*(activity)*/ 10){}

};