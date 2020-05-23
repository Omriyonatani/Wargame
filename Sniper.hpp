#pragma once
#include "Soldier.hpp"
#include <cmath>
#include <cstdlib>
using namespace std;

class Sniper:public Soldier{
    public:
        //constructor
        Sniper(int player_number) : 
            Soldier(player_number,100,0,50,2){}

        void Action(vector<vector<Soldier*>>& board,int player_number,pair<int,int> location){
            
        }

};