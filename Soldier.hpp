#pragma once


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

        bool get_Commander(){
            if(this->Commander==1){
                return true;
            }
            return false;
        }

        int get_activity(){
            return this->activity;
        }

};