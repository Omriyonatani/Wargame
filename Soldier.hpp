#pragma once

class Soldier{
    public:
        int player_number;
        int HP;
        Soldier(){}
        Soldier(int player_number){
            HP=100;
        }
        virtual void activity(Soldier& opponent)=0;
};
