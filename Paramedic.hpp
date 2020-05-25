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


            // heal Foot
            if(board[i+1][j]->get_player_number() == this-> player_number && board[i+1][j]->get_typeTag() == 1){
                if(board[i+1][j]->IsCommander() == 1){
                    board[i+1][j]-> HP = 150;
                }else{
                    board[i+1][j]-> HP = 100;
                }
            }
            if(board[i][j+1]->get_player_number() == this-> player_number && board[i][j+1]->get_typeTag() == 1){
                if(board[i][j+1]->IsCommander() == 1){
                    board[i][j+1]-> HP = 150;
                }else{
                    board[i][j+1]-> HP = 100;
                }
            }
            if(board[i+1][j+1]->get_player_number() == this-> player_number && board[i+1][j+1]->get_typeTag() == 1){
                if(board[i+1][j+1]->IsCommander() == 1){
                    board[i+1][j+1]-> HP = 150;
                }else{
                    board[i+1][j+1]-> HP = 100;
                }
            }
            if(board[i-1][j-1]->get_player_number() == this-> player_number && board[i-1][j-1]->get_typeTag() == 1){
                if(board[i-1][j-1]->IsCommander() == 1){
                    board[i-1][j-1]-> HP = 150;
                }else{
                    board[i-1][j-1]-> HP = 100;
                }
            }
            if(board[i][j-1]->get_player_number() == this-> player_number && board[i][j-1]->get_typeTag() == 1){
                if(board[i][j-1]->IsCommander() == 1){
                    board[i][j-1]-> HP = 150;
                }else{
                    board[i][j-1]-> HP = 100;
                }
            }
            if(board[i-1][j]->get_player_number() == this-> player_number && board[i-1][j]->get_typeTag() == 1){
                if(board[i-1][j]->IsCommander() == 1){
                    board[i-1][j]-> HP = 150;
                }else{
                    board[i-1][j]-> HP = 100;
                }
            }
            if(board[i+1][j-1]->get_player_number() == this-> player_number && board[i+1][j-1]->get_typeTag() == 1){
                if(board[i+1][j-1]->IsCommander() == 1){
                    board[i+1][j-1]-> HP = 150;
                }else{
                    board[i+1][j-1]-> HP = 100;
                }
            }
            if(board[i-1][j+1]->get_player_number() == this-> player_number && board[i-1][j+1]->get_typeTag() == 1){
                if(board[i-1][j+1]->IsCommander() == 1){
                    board[i-1][j+1]-> HP = 150;
                }else{
                    board[i-1][j+1]-> HP = 100;
                }
            }






            // heal Sniper
            if(board[i+1][j]->get_player_number() == this-> player_number && board[i+1][j]->get_typeTag() == 2){
                if(board[i+1][j]->IsCommander() == 1){
                    board[i+1][j]-> HP = 120;
                }else{
                    board[i+1][j]-> HP = 100;
                }
            }
            if(board[i][j+1]->get_player_number() == this-> player_number && board[i][j+1]->get_typeTag() == 2){
                if(board[i][j+1]->IsCommander() == 1){
                    board[i][j+1]-> HP = 120;
                }else{
                    board[i][j+1]-> HP = 100;
                }
            }
            if(board[i+1][j+1]->get_player_number() == this-> player_number && board[i+1][j+1]->get_typeTag() == 2){
                if(board[i+1][j+1]->IsCommander() == 1){
                    board[i+1][j+1]-> HP = 120;
                }else{
                    board[i+1][j+1]-> HP = 100;
                }
            }
            if(board[i-1][j-1]->get_player_number() == this-> player_number && board[i-1][j-1]->get_typeTag() == 2){
                if(board[i-1][j-1]->IsCommander() == 1){
                    board[i-1][j-1]-> HP = 120;
                }else{
                    board[i-1][j-1]-> HP = 100;
                }
            }
            if(board[i][j-1]->get_player_number() == this-> player_number && board[i][j-1]->get_typeTag() == 2){
                if(board[i][j-1]->IsCommander() == 1){
                    board[i][j-1]-> HP = 120;
                }else{
                    board[i][j-1]-> HP = 100;
                }
            }
            if(board[i-1][j]->get_player_number() == this-> player_number && board[i-1][j]->get_typeTag() == 2){
                if(board[i-1][j]->IsCommander() == 1){
                    board[i-1][j]-> HP = 120;
                }else{
                    board[i-1][j]-> HP = 100;
                }
            }
            if(board[i+1][j-1]->get_player_number() == this-> player_number && board[i+1][j-1]->get_typeTag() == 2){
                if(board[i+1][j-1]->IsCommander() == 1){
                    board[i+1][j-1]-> HP = 120;
                }else{
                    board[i+1][j-1]-> HP = 100;
                }
            }
            if(board[i-1][j+1]->get_player_number() == this-> player_number && board[i-1][j+1]->get_typeTag() == 2){
                if(board[i-1][j+1]->IsCommander() == 1){
                    board[i-1][j+1]-> HP = 120;
                }else{
                    board[i-1][j+1]-> HP = 100;
                }
            }




            // heal Paramedic
            if(board[i+1][j]->get_player_number() == this-> player_number && board[i+1][j]->get_typeTag() == 3){
                if(board[i+1][j]->IsCommander() == 1){
                    board[i+1][j]-> HP = 200;
                }else{
                    board[i+1][j]-> HP = 100;
                }
            }
            if(board[i][j+1]->get_player_number() == this-> player_number && board[i][j+1]->get_typeTag() == 3){
                if(board[i][j+1]->IsCommander() == 1){
                    board[i][j+1]-> HP = 200;
                }else{
                    board[i][j+1]-> HP = 100;
                }
            }
            if(board[i+1][j+1]->get_player_number() == this-> player_number && board[i+1][j+1]->get_typeTag() == 3){
                if(board[i+1][j+1]->IsCommander() == 1){
                    board[i+1][j+1]-> HP = 200;
                }else{
                    board[i+1][j+1]-> HP = 100;
                }
            }
            if(board[i-1][j-1]->get_player_number() == this-> player_number && board[i-1][j-1]->get_typeTag() == 3){
                if(board[i-1][j-1]->IsCommander() == 1){
                    board[i-1][j-1]-> HP = 200;
                }else{
                    board[i-1][j-1]-> HP = 100;
                }
            }
            if(board[i][j-1]->get_player_number() == this-> player_number && board[i][j-1]->get_typeTag() == 3){
                if(board[i][j-1]->IsCommander() == 1){
                    board[i][j-1]-> HP = 200;
                }else{
                    board[i][j-1]-> HP = 100;
                }
            }
            if(board[i-1][j]->get_player_number() == this-> player_number && board[i-1][j]->get_typeTag() == 3){
                if(board[i-1][j]->IsCommander() == 1){
                    board[i-1][j]-> HP = 200;
                }else{
                    board[i-1][j]-> HP = 100;
                }
            }
            if(board[i+1][j-1]->get_player_number() == this-> player_number && board[i+1][j-1]->get_typeTag() == 3){
                if(board[i+1][j-1]->IsCommander() == 1){
                    board[i+1][j-1]-> HP = 200;
                }else{
                    board[i+1][j-1]-> HP = 100;
                }
            }
            if(board[i-1][j+1]->get_player_number() == this-> player_number && board[i-1][j+1]->get_typeTag() == 3){
                if(board[i-1][j+1]->IsCommander() == 1){
                    board[i-1][j+1]-> HP = 200;
                }else{
                    board[i-1][j+1]-> HP = 100;
                }
            }
        }
};