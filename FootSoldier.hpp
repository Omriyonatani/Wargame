#pragma once
#include "Soldier.hpp"
// #include <stdlib.h>
#include <cmath>
#include <cstdlib>
#include <iostream>
#define INF 1000000
using namespace std;

class FootSoldier:public Soldier{
    public:
        pair<int,int> search_close_soldier(vector<vector<Soldier*>>& board,pair<int,int> location)const{
            int d=INF;
            pair<int,int> closest {0,0};
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if (i==location.first && j==location.second){
                        continue;
                    }
                    if(board[i][j]!=nullptr && board[i][j]->get_player_number()!=this->player_number){
                        int t1=fabs(location.first-i);
                        int t2=fabs(location.second-j);
                        if(d==INF){
                            d=t1+t2;
                            closest = {i,j};
                        }
                        else if(d>t1+t2){
                            d=t1+t2;
                            closest = {i,j};
                        }
                    }
                }
            }
            cout<<"location "<<location.first<<","<<location.second<<"attack location "<<closest.first<<","<<closest.second<<endl;
            return closest;
        }

        //constructor
        FootSoldier(int player_number) : 
            Soldier(player_number,100,0,10,Type::Foot){
                set_max_hp(100);
            }

        //action
        void Action(vector<vector<Soldier*>>& board,int player_number,pair<int,int> location){
            pair<int,int> attack=search_close_soldier(board,location);
            
            board[attack.first][attack.second]->HP -=this->activity;
            if(board[attack.first][attack.second]->HP<=0){
                board[attack.first][attack.second]=nullptr;
            }
        }
};