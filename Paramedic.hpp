#pragma once
#include "Soldier.hpp"
#include <cmath>

using namespace std;

class Paramedic:public Soldier{

    public:
        Paramedic(int player_number):
            Soldier(player_number,100,0,50,Type::Paramedic){
                set_max_hp(100);
            }

        void Action(vector<vector<Soldier*>>& board,int player_number,pair<int,int> location){
            int i=location.first;
            int j=location.second;


            //yogev implementation

            if((j+1)<board[0].size() && board[i][j+1]!= nullptr  && board[i][j+1]->get_player_number()==player_number){
                board[i][j+1]->HP = board[i][j+1]->get_max_hp();
            }

            if((j-1)>=board[0].size() && board[i][j-1]!= nullptr  && board[i][j-1]->get_player_number()==player_number){
                board[i][j-1]->HP= board[i][j-1]->get_max_hp();
            }

            if((i+1)<board.size() && board[i+1][j]!= nullptr  && board[i+1][j]->get_player_number()==player_number){
                board[i+1][j]->HP= board[i+1][j]->get_max_hp();
            }
            
            if((i-1)>=board.size() && board[i-1][j]!= nullptr && board[i-1][j]->get_player_number()==player_number){
                board[i-1][j]->HP = board[i-1][j]->get_max_hp();
            }

            if(((i+1)<board.size() && (j+1)<board[0].size() ) && board[i+1][j+1]!= nullptr  && board[i+1][j+1]->get_player_number()==player_number){
                board[i+1][j+1]->HP =  board[i+1][j+1]->get_max_hp();
            }

            if(((i-1)>=board.size() && (j+1)<board[0].size() ) && board[i-1][j+1]!= nullptr  && board[i-1][j+1]->get_player_number()==player_number){
                board[i-1][j+1]->HP =  board[i-1][j+1]->get_max_hp();
            }

            if(((i-1)>=board.size() && (j-1)>=board[0].size() ) && board[i-1][j-1]!= nullptr  && board[i-1][j-1]->get_player_number()==player_number){
                board[i-1][j-1]->HP =  board[i-1][j-1]->get_max_hp();
            }

            if(((i+1)<board.size() && (j-1)>=board[0].size() ) && board[i+1][j-1]!= nullptr  && board[i+1][j-1]->get_player_number()==player_number){
                board[i+1][j-1]->HP = board[i+1][j-1]->get_max_hp();
            }

        }

            //omri implementation
            // heal Foot
        //     if(board[i+1][j]->get_player_number() == this-> player_number && board[i+1][j]->get_typeTag() == 1){
        //         if(board[i+1][j]->IsCommander() == 1){
        //             board[i+1][j]-> HP = 150;
        //         }else{
        //             board[i+1][j]-> HP = 100;
        //         }
        //     }
        //     if(board[i][j+1]->get_player_number() == this-> player_number && board[i][j+1]->get_typeTag() == 1){
        //         if(board[i][j+1]->IsCommander() == 1){
        //             board[i][j+1]-> HP = 150;
        //         }else{
        //             board[i][j+1]-> HP = 100;
        //         }
        //     }
        //     if(board[i+1][j+1]->get_player_number() == this-> player_number && board[i+1][j+1]->get_typeTag() == 1){
        //         if(board[i+1][j+1]->IsCommander() == 1){
        //             board[i+1][j+1]-> HP = 150;
        //         }else{
        //             board[i+1][j+1]-> HP = 100;
        //         }
        //     }
        //     if(board[i-1][j-1]->get_player_number() == this-> player_number && board[i-1][j-1]->get_typeTag() == 1){
        //         if(board[i-1][j-1]->IsCommander() == 1){
        //             board[i-1][j-1]-> HP = 150;
        //         }else{
        //             board[i-1][j-1]-> HP = 100;
        //         }
        //     }
        //     if(board[i][j-1]->get_player_number() == this-> player_number && board[i][j-1]->get_typeTag() == 1){
        //         if(board[i][j-1]->IsCommander() == 1){
        //             board[i][j-1]-> HP = 150;
        //         }else{
        //             board[i][j-1]-> HP = 100;
        //         }
        //     }
        //     if(board[i-1][j]->get_player_number() == this-> player_number && board[i-1][j]->get_typeTag() == 1){
        //         if(board[i-1][j]->IsCommander() == 1){
        //             board[i-1][j]-> HP = 150;
        //         }else{
        //             board[i-1][j]-> HP = 100;
        //         }
        //     }
        //     if(board[i+1][j-1]->get_player_number() == this-> player_number && board[i+1][j-1]->get_typeTag() == 1){
        //         if(board[i+1][j-1]->IsCommander() == 1){
        //             board[i+1][j-1]-> HP = 150;
        //         }else{
        //             board[i+1][j-1]-> HP = 100;
        //         }
        //     }
        //     if(board[i-1][j+1]->get_player_number() == this-> player_number && board[i-1][j+1]->get_typeTag() == 1){
        //         if(board[i-1][j+1]->IsCommander() == 1){
        //             board[i-1][j+1]-> HP = 150;
        //         }else{
        //             board[i-1][j+1]-> HP = 100;
        //         }
        //     }






        //     // heal Sniper
        //     if(board[i+1][j]->get_player_number() == this-> player_number && board[i+1][j]->get_typeTag() == 2){
        //         if(board[i+1][j]->IsCommander() == 1){
        //             board[i+1][j]-> HP = 120;
        //         }else{
        //             board[i+1][j]-> HP = 100;
        //         }
        //     }
        //     if(board[i][j+1]->get_player_number() == this-> player_number && board[i][j+1]->get_typeTag() == 2){
        //         if(board[i][j+1]->IsCommander() == 1){
        //             board[i][j+1]-> HP = 120;
        //         }else{
        //             board[i][j+1]-> HP = 100;
        //         }
        //     }
        //     if(board[i+1][j+1]->get_player_number() == this-> player_number && board[i+1][j+1]->get_typeTag() == 2){
        //         if(board[i+1][j+1]->IsCommander() == 1){
        //             board[i+1][j+1]-> HP = 120;
        //         }else{
        //             board[i+1][j+1]-> HP = 100;
        //         }
        //     }
        //     if(board[i-1][j-1]->get_player_number() == this-> player_number && board[i-1][j-1]->get_typeTag() == 2){
        //         if(board[i-1][j-1]->IsCommander() == 1){
        //             board[i-1][j-1]-> HP = 120;
        //         }else{
        //             board[i-1][j-1]-> HP = 100;
        //         }
        //     }
        //     if(board[i][j-1]->get_player_number() == this-> player_number && board[i][j-1]->get_typeTag() == 2){
        //         if(board[i][j-1]->IsCommander() == 1){
        //             board[i][j-1]-> HP = 120;
        //         }else{
        //             board[i][j-1]-> HP = 100;
        //         }
        //     }
        //     if(board[i-1][j]->get_player_number() == this-> player_number && board[i-1][j]->get_typeTag() == 2){
        //         if(board[i-1][j]->IsCommander() == 1){
        //             board[i-1][j]-> HP = 120;
        //         }else{
        //             board[i-1][j]-> HP = 100;
        //         }
        //     }
        //     if(board[i+1][j-1]->get_player_number() == this-> player_number && board[i+1][j-1]->get_typeTag() == 2){
        //         if(board[i+1][j-1]->IsCommander() == 1){
        //             board[i+1][j-1]-> HP = 120;
        //         }else{
        //             board[i+1][j-1]-> HP = 100;
        //         }
        //     }
        //     if(board[i-1][j+1]->get_player_number() == this-> player_number && board[i-1][j+1]->get_typeTag() == 2){
        //         if(board[i-1][j+1]->IsCommander() == 1){
        //             board[i-1][j+1]-> HP = 120;
        //         }else{
        //             board[i-1][j+1]-> HP = 100;
        //         }
        //     }




        //     // heal Paramedic
        //     if(board[i+1][j]->get_player_number() == this-> player_number && board[i+1][j]->get_typeTag() == 3){
        //         if(board[i+1][j]->IsCommander() == 1){
        //             board[i+1][j]-> HP = 200;
        //         }else{
        //             board[i+1][j]-> HP = 100;
        //         }
        //     }
        //     if(board[i][j+1]->get_player_number() == this-> player_number && board[i][j+1]->get_typeTag() == 3){
        //         if(board[i][j+1]->IsCommander() == 1){
        //             board[i][j+1]-> HP = 200;
        //         }else{
        //             board[i][j+1]-> HP = 100;
        //         }
        //     }
        //     if(board[i+1][j+1]->get_player_number() == this-> player_number && board[i+1][j+1]->get_typeTag() == 3){
        //         if(board[i+1][j+1]->IsCommander() == 1){
        //             board[i+1][j+1]-> HP = 200;
        //         }else{
        //             board[i+1][j+1]-> HP = 100;
        //         }
        //     }
        //     if(board[i-1][j-1]->get_player_number() == this-> player_number && board[i-1][j-1]->get_typeTag() == 3){
        //         if(board[i-1][j-1]->IsCommander() == 1){
        //             board[i-1][j-1]-> HP = 200;
        //         }else{
        //             board[i-1][j-1]-> HP = 100;
        //         }
        //     }
        //     if(board[i][j-1]->get_player_number() == this-> player_number && board[i][j-1]->get_typeTag() == 3){
        //         if(board[i][j-1]->IsCommander() == 1){
        //             board[i][j-1]-> HP = 200;
        //         }else{
        //             board[i][j-1]-> HP = 100;
        //         }
        //     }
        //     if(board[i-1][j]->get_player_number() == this-> player_number && board[i-1][j]->get_typeTag() == 3){
        //         if(board[i-1][j]->IsCommander() == 1){
        //             board[i-1][j]-> HP = 200;
        //         }else{
        //             board[i-1][j]-> HP = 100;
        //         }
        //     }
        //     if(board[i+1][j-1]->get_player_number() == this-> player_number && board[i+1][j-1]->get_typeTag() == 3){
        //         if(board[i+1][j-1]->IsCommander() == 1){
        //             board[i+1][j-1]-> HP = 200;
        //         }else{
        //             board[i+1][j-1]-> HP = 100;
        //         }
        //     }
        //     if(board[i-1][j+1]->get_player_number() == this-> player_number && board[i-1][j+1]->get_typeTag() == 3){
        //         if(board[i-1][j+1]->IsCommander() == 1){
        //             board[i-1][j+1]-> HP = 200;
        //         }else{
        //             board[i-1][j+1]-> HP = 100;
        //         }
        //     }
        // }
};