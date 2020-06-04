#include "Board.hpp"
#include "Soldier.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "ParamedicCommander.hpp"
#include "Paramedic.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;
using namespace WarGame;

// operator for putting soldiers on the game-board during initialization.
Soldier*& Board:: operator[](std::pair<int,int> location){
    if(location.first>=Board::board.size() ||
     location.second>=Board::board[0].size()){
        throw new std::logic_error("You are out of the board\n");
    }
    
    return Board::board[location.first][location.second];
}

// operator for reading which soldiers are on the game-board.
Soldier* Board:: operator[](std::pair<int,int> location) const{
    if(location.first>=Board::board.size() ||
     location.second>=Board::board[0].size()){
        throw new std::logic_error("You are out of the board\n");
    }

    return Board::board[location.first][location.second];
}

 // returns true iff the board contains one or more soldiers of the given player.
bool Board:: has_soldiers(uint player_number) const{
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]!=nullptr&&
            board[i][j]->get_player_number()==player_number){
                return true;
            }
        }
    }
    return false;
}

std::vector<Soldier*> Board::get_soldiers(uint player_number,Soldier::Type t) const{
    std::vector<Soldier*> soldiers;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]!=nullptr&&
            board[i][j]->get_player_number()==player_number && board[i][j]->get_typeTag()==t && board[i][j]->IsCommander()==false){
                soldiers.push_back(board[i][j]);
            }
        }
    }
    return soldiers;
}

// The function "move" tries to move the soldier of player "player"
    //     from the "source" location to the "target" location,
    //     and activates the special ability of the soldier.
    // If the move is illegal, it throws "std::invalid_argument". 
    // Illegal moves include:
    //  * There is no soldier in the source location (i.e., the soldier pointer is null);
    //  * The soldier in the source location belongs to the other player.
    //  * There is already another soldier (of this or the other player) in the target location.
    // IMPLEMENTATION HINT: Do not write "if" conditions that depend on the type of soldier!
    // Your code should be generic. All handling of different types of soldiers 
    //      must be handled by polymorphism.
void Board:: move(uint player_number, std::pair<int,int> source, MoveDIR direction){
    //the player dont have any soldiers on the board
    if(!has_soldiers(player_number)){
        return;
    }
    if(player_number==1&&!has_soldiers(2)){
        return;
    }
    if(player_number==2&&!has_soldiers(1)){
        return;
    }
    //the location is out of the board
    if(source.first>=Board::board.size() ||
     source.second>=Board::board[0].size() || source.first<0 || source.second<0){
        throw new std::logic_error("Your source location are out of the board\n");
    }
    //in this location there is no soldier
    if(board[source.first][source.second]==nullptr){
        throw new std::logic_error("There is no soldier in this location\n");
    }
    //this soldier belong to the second player
    if(board[source.first][source.second]->get_player_number()!=player_number){
        throw new std::logic_error("This soldier is'nt belong to you\n");
    }

    int i=source.first;
    int j=source.second;
    
    if(direction==MoveDIR::Up){
        i+=1;
    }
    else if(direction==MoveDIR::Down){
        i-=1;
    }
    if(player_number==1){
        if(direction==MoveDIR::Right){
            j-=1;
        }
        else if(direction==MoveDIR::Left){
            j+=1;
        }
    }
    else{
        if(direction==MoveDIR::Right){
            j+=1;
        }
        else if(direction==MoveDIR::Left){
            j-=1;
            cout<<j<<endl;
        }
    }

    //the direction location is out of the board
    if(i>=board.size() || j>=board[0].size() || i<0 || j<0){
        throw new std::logic_error("Your direction location is out of the board\n");
    }
    //at the direction location there is a soldier
    if(board[i][j]!=nullptr){
        throw new std::logic_error("There is a soldier at the direction location\n");
    }
    pair<int,int> location (i,j); 
    board[i][j]=board[source.first][source.second];
    board[source.first][source.second]=nullptr;
    board[i][j]->Action(board,player_number,location);

}

WarGame::Board fillCommBoard(){
    WarGame::Board p (5,5);
    p[{0,0}] = new FootSoldier(1);
    p[{0,1}] = new FootSoldier(2);
    p[{0,3}] = new SniperCommander(2);
    p[{0,4}] = new FootCommander(2);
    p[{2,0}] = new Paramedic(2);
    p[{2,1}] = new Paramedic(1);
    p[{2,2}] = new FootCommander(1);
    p[{2,3}] = new SniperCommander(1);
    p[{4,0}] = new Sniper(1);
    p[{4,1}] = new Sniper(2);
    p[{4,3}] = new ParamedicCommander(1);
    p[{4,4}] = new ParamedicCommander(2);
    return p;
}

// int main(){
//       WarGame::Board p = fillCommBoard();
//     p.move(1,{2,2},WarGame::Board::Up);
            
//     p.move(1,{2,3},WarGame::Board::Down);
            
//     p.move(1,{4,3},WarGame::Board::Down);
          
//     p.move(2,{0,4},WarGame::Board::Up);

//     p.move(2,{0,3},WarGame::Board::Left);

//     p.move(2,{4,4},WarGame::Board::Down);
// }

