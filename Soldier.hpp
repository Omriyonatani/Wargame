#pragma once

#include "Board.hpp"
//using namespace WarGame;
using namespace std;

class Soldier{
        
    public:
        int player_number;  // team 1/2.
        int HP;
        int Commander; //  bool-    0 false,   1 true.
        int activity; //    damage / heal.
        int typeTag;  //  0 = Soldier,   1 = Foot,   2 = Sniper,   3 = Paramedic.

        //Constructor
        Soldier(int player_number, int HP, int Commander, int activity, int typeTag){
            this->player_number=player_number;
            this->HP=HP;
            this->Commander=Commander;
            this->activity=activity;
            this->typeTag=0;
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

        int get_typeTag(){
            return this->typeTag;
        }

        virtual void Action(vector<vector<Soldier*>>& board,int player_number,pair<int,int> location) =0;

};