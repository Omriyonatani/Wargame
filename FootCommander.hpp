#include "Soldier.hpp"
#include "FootSoldier.hpp"
#include <cmath>

using namespace std;

class FootCommander:public FootSoldier{
    public:
        FootCommander(int player_number) : 
            FootSoldier(player_number){
                this->HP+=50;
                this->activity+=10;
                this->Commander=1;
            }

        void Action(vector<vector<Soldier*>>& board,int player_number,pair<int,int> location){
            
        }


};