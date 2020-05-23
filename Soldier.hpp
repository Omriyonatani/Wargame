#pragma once

#include "Board.hpp"
//using namespace WarGame;
using namespace std;

class Soldier{
        
    public:
        int player_number;
        int HP;
        int Commander;
        int activity; //    damage / heal
        //Constructor
        Soldier(int player_number, int HP, int Commander, int activity){
            this->player_number=player_number;
            this->HP=HP;
            this->Commander=Commander;
            this->activity=activity;
        }


        // Getters
        int get_HP(){
            return this->HP;
        }

        int get_player_number(){
            return this->player_number;
        }

        bool IsCommander(){
            if(this->Commander==1){
                return true;
            }
            return false;
        }

        int get_activity(){
            return this->activity;
        }

        virtual void Action(vector<vector<Soldier*>>& board,int player_number,pair<int,int> location) =0;

};