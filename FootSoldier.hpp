#include "Soldier.hpp"
// #include <stdlib.h>
#include <cmath>
#include <cstdlib>
#define INF 1000000
using namespace std;

class FootSoldier:public Soldier{
    private:
        pair<int,int> search_close_soldier(vector<vector<Soldier*>> board,pair<int,int> location)const{
            int d=0;
            pair<int,int> closest {0,0};
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(board[i][j]!=nullptr&&board[i][j]->get_player_number()!=this->player_number){
                        int t1=fabs(location.first-i);
                        int t2=fabs(location.second-j);
                        if(d==0){
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
            return closest;
        }

    public:
        //constructor
        FootSoldier(int player_number) : 
            Soldier(player_number,100,0,10){}

        //action
        void Action(vector<vector<Soldier*>>& board,int player_number,pair<int,int> location){
            pair<int,int> attack=search_close_soldier(board,location);
            board[attack.first][attack.second]->HP -=this->activity;
            if(board[attack.first][attack.second]->HP<=0){
                board[attack.first][attack.second]=nullptr;
            }
            
        }

        

};