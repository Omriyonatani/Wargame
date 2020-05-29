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
                set_max_hp(200);
            }

        void Action(vector<vector<Soldier*>>& board,int player_number,pair<int,int> location){
            int i=location.first;
            int j=location.second;

            //commander's heal
            this->Paramedic::Action(board,player_number,location);

            //regular paramedics heal
            for (int i=0; i<board.size(); i++){
                for(int j=0; j<board[0].size(); j++){
                    if(board[i][j] != nullptr && board[i][j]->get_player_number() == this->player_number && board[i][j]->get_typeTag() == type && board[i][j]->IsCommander()==false){
                        std::pair<int,int> location_paramedic {i,j};
                        board[i][j]->Action(board,player_number,location_paramedic);
                    }
                }
            }

        }
};