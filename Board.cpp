#include "Board.hpp"
#include "Soldier.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

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
    //the location is out of the board
    if(source.first>=Board::board.size() ||
     source.second>=Board::board[0].size()){
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
    else if(direction==MoveDIR::Right){
        j-=1;
    }
    else{
        j+=1;
    }

    //the direction location is out of the board
    if(i>=board.size() || j>=board[0].size()){
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

