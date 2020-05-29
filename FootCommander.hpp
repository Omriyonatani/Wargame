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
                    set_max_hp(150);
            }

        // Commander attack makes all this type Soldier attack.
        void Action(vector<vector<Soldier*>>& board,int player_number,pair<int,int> location){
            // my attack
            this->FootSoldier::Action(board,player_number,location);

            // attack for every FootSoldier that not Commander.

            for (int i=0; i<board.size(); i++){
                for(int j=0; j<board[0].size(); j++){
                    if(board[i][j] != nullptr && board[i][j]->get_player_number() == this->player_number && board[i][j]->get_typeTag() == type && board[i][j]->IsCommander()==false){
                        std::pair<int,int> location_foot {i,j};
                        board[i][j]->Action(board,player_number,location_foot);
                    }
                }
            }
        }
};