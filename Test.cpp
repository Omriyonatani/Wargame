#include "doctest.h"
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <complex>

using namespace std;
using namespace WarGame;

Board demo_board_foot(){
    Board board(8,8);
    board[{0,1}] = new FootSoldier(1);
	board[{0,3}] = new FootCommander(1);
	board[{0,5}] = new FootSoldier(1);

    board[{7,1}] = new FootSoldier(2);
	board[{7,3}] = new FootCommander(2);
	board[{7,5}] = new FootSoldier(2);
    return board;
}

Board demo_board_sniper(){
    Board board(8,8);
    board[{0,1}] = new Sniper(1);
	board[{0,3}] = new Sniper(1);
	board[{0,5}] = new SniperCommander(1);

    board[{7,1}] = new Sniper(2);
	board[{7,3}] = new Sniper(2);
	board[{7,5}] = new SniperCommander(2);
    return board;
}

Board demo_board_all(){
    Board board(8,8);
    board[{0,1}] = new FootSoldier(1);
	board[{0,3}] = new FootCommander(1);
	board[{0,5}] = new Sniper(1);
    board[{0,7}] = new SniperCommander(1);
    board[{1,2}] = new Paramedic(1);
    board[{1,5}] = new ParamedicCommander(1);

    board[{7,1}] = new FootSoldier(2);
	board[{7,3}] = new FootCommander(2);
	board[{7,5}] = new Sniper(2);
    board[{7,7}] = new SniperCommander(2);
    board[{6,2}] = new Paramedic(2);
    board[{6,5}] = new ParamedicCommander(2);
    return board;
}

TEST_CASE("wqeq"){
    Board board(8,8);
    board[{0,1}] = new FootSoldier(1);
	board[{0,3}] = new FootCommander(1);
	board[{0,5}] = new FootSoldier(1);

    board[{7,1}] = new FootSoldier(2);
	board[{7,3}] = new FootCommander(2);
	board[{7,5}] = new FootSoldier(2);

    CHECK(board[{7,1}]->get_HP()==100);

    CHECK_THROWS(board.move(1,{0,1},Board::MoveDIR::Down));
    CHECK_THROWS(board.move(1,{5,1},Board::MoveDIR::Down));
    board.move(1,{0,1}, Board::MoveDIR::Up);
    CHECK(board[{7,1}]->get_HP()==90);
    CHECK(board.has_soldiers(2)==true);
    CHECK(board[{1,1}]!=nullptr);

}

TEST_CASE("Location out of board Exception"){
    Board board=demo_board_foot();
    CHECK_THROWS(board.move(1,{0,8},Board::MoveDIR::Down));
    board.move(1,{0,1},Board::MoveDIR::Right);
    CHECK_THROWS(board.move(1,{0,1},Board::MoveDIR::Right));
    CHECK_THROWS(board.move(2,{7,1},Board::MoveDIR::Up));

    for(int i=0;i<4;i++){
        board.move(1,{0,3},Board::MoveDIR::Left);
    }
    CHECK_THROWS(board.move(1,{0,3},Board::MoveDIR::Left));

    CHECK_THROWS(board.move(2,{7,3},Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2,{7,5},Board::MoveDIR::Up));

    board.move(2,{7,1},Board::MoveDIR::Down);
    board.move(2,{7,1},Board::MoveDIR::Up);
    CHECK_THROWS(board.move(2,{7,1},Board::MoveDIR::Up));

}

TEST_CASE("No soldier in location Exception"){
    Board board=demo_board_all();
    CHECK_THROWS(board.move(1,{0,2},Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1,{0,4},Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1,{3,4},Board::MoveDIR::Up));
    board.move(1,{1,2},Board::MoveDIR::Up);
    CHECK_THROWS(board.move(1,{1,2},Board::MoveDIR::Up));
    board.move(2,{7,1},Board::MoveDIR::Down);
    CHECK_THROWS(board.move(2,{7,1},Board::MoveDIR::Down));
    board.move(2,{6,5},Board::MoveDIR::Left);
    CHECK_THROWS(board.move(2,{6,5},Board::MoveDIR::Down));
}

TEST_CASE("There is soldier at the direction step Exception"){
    Board board=demo_board_all();
    board.move(2,{7,7},Board::MoveDIR::Left);
    CHECK_THROWS(board.move(2,{7,7},Board::MoveDIR::Left));
    CHECK_THROWS(board.move(2,{7,5},Board::MoveDIR::Up));
    board.move(2,{6,7},Board::MoveDIR::Down);
    CHECK_THROWS(board.move(2,{7,1},Board::MoveDIR::Right));
    CHECK_THROWS(board.move(2,{7,3},Board::MoveDIR::Left));
    CHECK_THROWS(board.move(2,{7,2},Board::MoveDIR::Left));
    CHECK_THROWS(board.move(2,{7,2},Board::MoveDIR::Right));
    board.move(1,{0,7},Board::MoveDIR::Left);
    CHECK_THROWS(board.move(1,{1,5},Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1,{0,6},Board::MoveDIR::Left));
    board.move(1,{1,2},Board::MoveDIR::Up);
    CHECK_THROWS(board.move(1,{0,3},Board::MoveDIR::Left));
    CHECK_THROWS(board.move(1,{0,1},Board::MoveDIR::Right));

}

TEST_CASE("Soldier belong to another player Exception"){
    
}

TEST_CASE("Moves and Actions Test"){
    Board board=demo_board_all();
    board.move(1,{0,1},Board::MoveDIR::Up);//foot attack
    CHECK(((board[{6,2}]->HP==90) || (board[{7,1}]->HP==90)));//attack the paramedic or the FootCommander
    board.move(2,{7,5},Board::MoveDIR::Left);//sniper attack
    CHECK(board[{1,5}]->HP==150);//attack the ParamedicCommander
    board.move(1,{0,3},Board::MoveDIR::Up);//FootCommander attack
    CHECK((board[{6,2}]->HP==70 || board[{7,3}]->HP==130));//attack the Paramedic or FootCommander
    CHECK((board[{6,2}]->HP==60 || board[{7,1}]->HP==120));//activate all FootCommander
}

TEST_CASE("After action - check HP to the right soldier-  Test"){
    
}
