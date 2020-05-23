#include "Soldier.hpp"
#include "Paramedic.hpp"
#include <cmath>

using namespace std;

class ParamedicCommander:public Paramedic{

    public:
        ParamedicCommander(int player_number):
            Paramedic(player_number){
                this->HP+=100;
                this->activity+=100;
                this->Commander=1;
            }

        void Action(vector<vector<Soldier*>>& board,int player_number,pair<int,int> location){
            
        }
        
};