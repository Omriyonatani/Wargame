#pragma once

#include "Board.hpp"
//using namespace WarGame;
using namespace std;

class Soldier{
    private:
        int max_hp; //max hp for soldier type 
      
    public:
        enum Type{Foot,Sniper,Paramedic};
        int player_number;  // team 1/2.
        int HP;
        int Commander; //  bool-    0 false,   1 true.
        int activity;//damage / heal
        Type type; //soldier type
              

        //Constructor
        Soldier(int player_number, int HP, int Commander, int activity, Type type){
            this->player_number=player_number;
            this->HP=HP;
            this->Commander=Commander;
            this->activity=activity;
            this->type=type;
            // this->max_hp=max_hp;
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

        int get_max_hp(){
            return this->max_hp;
        };

        Type get_typeTag(){
            return this->type;
        }

        //Setter
        void set_max_hp(int hp){
            this->max_hp=hp;
        }

        virtual void Action(vector<vector<Soldier*>>& board,int player_number,pair<int,int> location) =0;

};