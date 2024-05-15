#ifndef Board_H
#define Board_H


class Board {
private:
	bool board[5][9];
public:
	Board();
	bool isAvailable(int lane, int cell);
	void makeUnavailable(int lane, int cell);
	void makeAllAvailable();
};

#endif
