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


            // heal Foot
            // if(board[i+1][j]->get_player_number() == this-> player_number && board[i+1][j]->get_typeTag() == 1){
            //     if(board[i+1][j]->IsCommander() == 1){
            //         board[i+1][j]-> HP = 150;
            //     }else{
            //         board[i+1][j]-> HP = 100;
            //     }
            // }
            // if(board[i][j+1]->get_player_number() == this-> player_number && board[i][j+1]->get_typeTag() == 1){
            //     if(board[i][j+1]->IsCommander() == 1){
            //         board[i][j+1]-> HP = 150;
            //     }else{
            //         board[i][j+1]-> HP = 100;
            //     }
            // }
            // if(board[i+1][j+1]->get_player_number() == this-> player_number && board[i+1][j+1]->get_typeTag() == 1){
            //     if(board[i+1][j+1]->IsCommander() == 1){
            //         board[i+1][j+1]-> HP = 150;
            //     }else{
            //         board[i+1][j+1]-> HP = 100;
            //     }
            // }
            // if(board[i-1][j-1]->get_player_number() == this-> player_number && board[i-1][j-1]->get_typeTag() == 1){
            //     if(board[i-1][j-1]->IsCommander() == 1){
            //         board[i-1][j-1]-> HP = 150;
            //     }else{
            //         board[i-1][j-1]-> HP = 100;
            //     }
            // }
            // if(board[i][j-1]->get_player_number() == this-> player_number && board[i][j-1]->get_typeTag() == 1){
            //     if(board[i][j-1]->IsCommander() == 1){
            //         board[i][j-1]-> HP = 150;
            //     }else{
            //         board[i][j-1]-> HP = 100;
            //     }
            // }
            // if(board[i-1][j]->get_player_number() == this-> player_number && board[i-1][j]->get_typeTag() == 1){
            //     if(board[i-1][j]->IsCommander() == 1){
            //         board[i-1][j]-> HP = 150;
            //     }else{
            //         board[i-1][j]-> HP = 100;
            //     }
            // }
            // if(board[i+1][j-1]->get_player_number() == this-> player_number && board[i+1][j-1]->get_typeTag() == 1){
            //     if(board[i+1][j-1]->IsCommander() == 1){
            //         board[i+1][j-1]-> HP = 150;
            //     }else{
            //         board[i+1][j-1]-> HP = 100;
            //     }
            // }
            // if(board[i-1][j+1]->get_player_number() == this-> player_number && board[i-1][j+1]->get_typeTag() == 1){
            //     if(board[i-1][j+1]->IsCommander() == 1){
            //         board[i-1][j+1]-> HP = 150;
            //     }else{
            //         board[i-1][j+1]-> HP = 100;
            //     }
            // }






            // // heal Sniper
            // if(board[i+1][j]->get_player_number() == this-> player_number && board[i+1][j]->get_typeTag() == 2){
            //     if(board[i+1][j]->IsCommander() == 1){
            //         board[i+1][j]-> HP = 120;
            //     }else{
            //         board[i+1][j]-> HP = 100;
            //     }
            // }
            // if(board[i][j+1]->get_player_number() == this-> player_number && board[i][j+1]->get_typeTag() == 2){
            //     if(board[i][j+1]->IsCommander() == 1){
            //         board[i][j+1]-> HP = 120;
            //     }else{
            //         board[i][j+1]-> HP = 100;
            //     }
            // }
            // if(board[i+1][j+1]->get_player_number() == this-> player_number && board[i+1][j+1]->get_typeTag() == 2){
            //     if(board[i+1][j+1]->IsCommander() == 1){
            //         board[i+1][j+1]-> HP = 120;
            //     }else{
            //         board[i+1][j+1]-> HP = 100;
            //     }
            // }
            // if(board[i-1][j-1]->get_player_number() == this-> player_number && board[i-1][j-1]->get_typeTag() == 2){
            //     if(board[i-1][j-1]->IsCommander() == 1){
            //         board[i-1][j-1]-> HP = 120;
            //     }else{
            //         board[i-1][j-1]-> HP = 100;
            //     }
            // }
            // if(board[i][j-1]->get_player_number() == this-> player_number && board[i][j-1]->get_typeTag() == 2){
            //     if(board[i][j-1]->IsCommander() == 1){
            //         board[i][j-1]-> HP = 120;
            //     }else{
            //         board[i][j-1]-> HP = 100;
            //     }
            // }
            // if(board[i-1][j]->get_player_number() == this-> player_number && board[i-1][j]->get_typeTag() == 2){
            //     if(board[i-1][j]->IsCommander() == 1){
            //         board[i-1][j]-> HP = 120;
            //     }else{
            //         board[i-1][j]-> HP = 100;
            //     }
            // }
            // if(board[i+1][j-1]->get_player_number() == this-> player_number && board[i+1][j-1]->get_typeTag() == 2){
            //     if(board[i+1][j-1]->IsCommander() == 1){
            //         board[i+1][j-1]-> HP = 120;
            //     }else{
            //         board[i+1][j-1]-> HP = 100;
            //     }
            // }
            // if(board[i-1][j+1]->get_player_number() == this-> player_number && board[i-1][j+1]->get_typeTag() == 2){
            //     if(board[i-1][j+1]->IsCommander() == 1){
            //         board[i-1][j+1]-> HP = 120;
            //     }else{
            //         board[i-1][j+1]-> HP = 100;
            //     }
            // }




            // // heal Paramedic
            // if(board[i+1][j]->get_player_number() == this-> player_number && board[i+1][j]->get_typeTag() == 3){
            //     if(board[i+1][j]->IsCommander() == 1){
            //         board[i+1][j]-> HP = 200;
            //     }else{
            //         board[i+1][j]-> HP = 100;
            //     }
            // }
            // if(board[i][j+1]->get_player_number() == this-> player_number && board[i][j+1]->get_typeTag() == 3){
            //     if(board[i][j+1]->IsCommander() == 1){
            //         board[i][j+1]-> HP = 200;
            //     }else{
            //         board[i][j+1]-> HP = 100;
            //     }
            // }
            // if(board[i+1][j+1]->get_player_number() == this-> player_number && board[i+1][j+1]->get_typeTag() == 3){
            //     if(board[i+1][j+1]->IsCommander() == 1){
            //         board[i+1][j+1]-> HP = 200;
            //     }else{
            //         board[i+1][j+1]-> HP = 100;
            //     }
            // }
            // if(board[i-1][j-1]->get_player_number() == this-> player_number && board[i-1][j-1]->get_typeTag() == 3){
            //     if(board[i-1][j-1]->IsCommander() == 1){
            //         board[i-1][j-1]-> HP = 200;
            //     }else{
            //         board[i-1][j-1]-> HP = 100;
            //     }
            // }
            // if(board[i][j-1]->get_player_number() == this-> player_number && board[i][j-1]->get_typeTag() == 3){
            //     if(board[i][j-1]->IsCommander() == 1){
            //         board[i][j-1]-> HP = 200;
            //     }else{
            //         board[i][j-1]-> HP = 100;
            //     }
            // }
            // if(board[i-1][j]->get_player_number() == this-> player_number && board[i-1][j]->get_typeTag() == 3){
            //     if(board[i-1][j]->IsCommander() == 1){
            //         board[i-1][j]-> HP = 200;
            //     }else{
            //         board[i-1][j]-> HP = 100;
            //     }
            // }
            // if(board[i+1][j-1]->get_player_number() == this-> player_number && board[i+1][j-1]->get_typeTag() == 3){
            //     if(board[i+1][j-1]->IsCommander() == 1){
            //         board[i+1][j-1]-> HP = 200;
            //     }else{
            //         board[i+1][j-1]-> HP = 100;
            //     }
            // }
            // if(board[i-1][j+1]->get_player_number() == this-> player_number && board[i-1][j+1]->get_typeTag() == 3){
            //     if(board[i-1][j+1]->IsCommander() == 1){
            //         board[i-1][j+1]-> HP = 200;
            //     }else{
            //         board[i-1][j+1]-> HP = 100;
            //     }
            // }

            // // heal for every Paramedic that not Commander.
            // for (int i=0; i<board.size(); i++){
            //     for(int j=0; j<board[0].size(); j++){
            //         if(board[i][j] != nullptr && board[i][j]->get_player_number() == this->player_number && board[i][j]->get_typeTag() == type && board[i][j]->IsCommander()==0){
            //             board[i][j]->Action(board,player_number,location);
            //         }
            //     }
            // }
        }
};