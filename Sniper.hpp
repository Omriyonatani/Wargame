#pragma once
#include "Soldier.hpp"
#include <cmath>
#include <cstdlib>
using namespace std;

class Sniper:public Soldier{
    public:
    pair<int,int> search_strongest_soldier(vector<vector<Soldier*>>& board,pair<int,int> location)const{
        int d=0;
        pair<int,int> strongest {0,0};
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if (i==location.first && j==location.second){
                    continue;
                }
                if(board[i][j]!=nullptr && board[i][j]->get_player_number()!=this->player_number){
                    int t1=board[i][j]->get_HP();
                    if(t1>d){
                        d=t1;
                        strongest = {i,j};
                    }
                }
            }
        }
        cout<<"location "<<location.first<<","<<location.second<<"attack location "<<strongest.first<<","<<strongest.second<<endl;
        return strongest;
    }

        //constructor
        Sniper(int player_number) : 
            Soldier(player_number,100,0,50,Type::Sniper){
                set_max_hp(100);
            }


        ~Sniper(){
            cout<<"Sniper destructor"<<endl;
        }
        void Action(vector<vector<Soldier*>>& board,int player_number,pair<int,int> location){
            pair<int,int> attack=search_strongest_soldier(board,location);

            board[attack.first][attack.second]->HP -=this->activity;
            if(board[attack.first][attack.second]->HP<=0){
                board[attack.first][attack.second]=nullptr;
            }
        }



};