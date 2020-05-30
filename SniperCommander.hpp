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
                set_max_hp(120);
            }
        
        void Action(vector<vector<Soldier*>>& board,int player_number,pair<int,int> location){
            // my attack
            this->Sniper::Action(board,player_number,location);

            // attack for every Sniper that not Commander.
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