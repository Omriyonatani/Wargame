#include "Soldier.hpp"
#include <cmath>

using namespace std;

class Paramedic:public Soldier{

    public:
        Paramedic(int player_number):
            Soldier(player_number,100,0,50){}

        void Action(vector<vector<Soldier*>>& board,int player_number,pair<int,int> location){
            
        }
        
};