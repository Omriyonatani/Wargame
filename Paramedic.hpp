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

        ~Paramedic(){
            cout<<"Paramedic destructor"<<endl;
        }

        void Action(vector<vector<Soldier*>>& board,int player_number,pair<int,int> location){
            int i=location.first;
            int j=location.second;

            if((j+1)<board[0].size() && board[i][j+1]!= nullptr  && board[i][j+1]->get_player_number()==player_number){
                board[i][j+1]->HP = board[i][j+1]->get_max_hp();
            }

            if((j-1)>=0&&(j-1)<board[0].size() && board[i][j-1]!= nullptr  && board[i][j-1]->get_player_number()==player_number){
                board[i][j-1]->HP= board[i][j-1]->get_max_hp();
            }

            if((i+1)<board.size() && board[i+1][j]!= nullptr  && board[i+1][j]->get_player_number()==player_number){
                board[i+1][j]->HP= board[i+1][j]->get_max_hp();
            }
            
            if((i-1)>=0&&(i-1)<board.size() && board[i-1][j]!= nullptr && board[i-1][j]->get_player_number()==player_number){
                board[i-1][j]->HP = board[i-1][j]->get_max_hp();
            }

            if(((i+1)<board.size() && (j+1)<board[0].size() ) && board[i+1][j+1]!= nullptr  && board[i+1][j+1]->get_player_number()==player_number){
                board[i+1][j+1]->HP =  board[i+1][j+1]->get_max_hp();
            }

            if(((i-1)>=0&&(i-1)<board.size() && (j+1)<board[0].size() ) && board[i-1][j+1]!= nullptr  && board[i-1][j+1]->get_player_number()==player_number){
                board[i-1][j+1]->HP =  board[i-1][j+1]->get_max_hp();
            }

            if(((i-1)>=0&&(i-1)<board.size() && (j-1)>=0&&(j-1)<board[0].size() ) && board[i-1][j-1]!= nullptr  && board[i-1][j-1]->get_player_number()==player_number){
                board[i-1][j-1]->HP =  board[i-1][j-1]->get_max_hp();
            }

            if(((i+1)<board.size() && (j-1)>=0&&(j-1)<board[0].size() ) && board[i+1][j-1]!= nullptr  && board[i+1][j-1]->get_player_number()==player_number){
                board[i+1][j-1]->HP = board[i+1][j-1]->get_max_hp();
            }
        }
};