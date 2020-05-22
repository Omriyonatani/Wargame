#include "Soldier.hpp"

using namespace std;

class FootSoldier:public Soldier{
    private:
        pair<int,int> search_close_soldier(Board& board,pair<int,int> location)const{
            
        }

    public:
        FootSoldier(int player_number) : 
            Soldier(player_number,100,0,10){}

        void Action(Board& board,int player_number,pair<int,int> location){

        }

        

};