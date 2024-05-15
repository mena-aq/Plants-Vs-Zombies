#include "Board.h"

Board::Board() {
	for (int lane = 0; lane < 5; lane++) {
		for (int cell = 0; cell < 9; cell++)
			board[lane][cell] = true;
	}
}
bool Board::isAvailable(int lane, int cell) {
	return board[lane][cell];
}
void Board::makeUnavailable(int lane, int cell) {
	board[lane][cell] = false;
}
void Board::makeAllAvailable() {
	for (int lane = 0; lane < 5; lane++) {
		for (int cell = 0; cell < 9; cell++)
			board[lane][cell] = true;
	}
}