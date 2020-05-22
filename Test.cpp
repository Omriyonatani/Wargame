#include "doctest.h"
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include <complex>

using namespace std;
using namespace WarGame;

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

    board.move(1,{0,1}, Board::MoveDIR::Up);
    CHECK(board[{7,1}]->get_HP()==90);
    CHECK(board.has_soldiers(2)==true);
    CHECK(board[{1,1}]!=nullptr);

}
