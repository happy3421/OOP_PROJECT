#include "../ChessUnit/Unit.h"

class Cell{
private:
	Unit *unit;
	int row;
	int col;
	bool acessible;

public:
	int getRow();
	int getCol();

	void unitRotate(int);
	void setUnit(Unit&);
	void killUnit();
	void unitMove(Cell&);
	void setPos(int, int);



};
