#include "Soldier.hpp"

class FootCommander:public Soldier{
    public:
        FootCommander(int player_number) : Soldier(/*(player_number)*/ player_number,/*(HP)*/ 150,/*(Commander)*/ 1, /*(activity)*/ 20){}

};