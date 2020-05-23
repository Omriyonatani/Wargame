#include "Soldier.hpp"
#include <cmath>
#include <cstdlib>
#include "Sniper.hpp"
using namespace std;

class SniperCommander:public Sniper{
    public:
        //constructor
        SniperCommander(int player_number) : 
            Sniper(player_number){
                this->HP+=20;
                this->activity+=100;
                this->Commander=1;
            }
        
        void Action(vector<vector<Soldier*>>& board,int player_number,pair<int,int> location){
            
        }

};