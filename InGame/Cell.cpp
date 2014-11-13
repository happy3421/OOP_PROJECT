#include "Cell.h"

int Cell::getCol(){ return col; }
int Cell::getRow(){ return row; }

void Cell::unitRotate(int CLK){ unit->rotate(CLK); }
void Cell::setUnit(Unit& _unit){ unit=&_unit; }
void Cell::unitMove(Cell& _cell){
	unit->move(&_cell);
	_cell.setUnit(*unit);
	unit = NULL;
}
void Cell::killUnit(){
	unit->die();
	unit = NULL;
}
void Cell::setPos(int _row, int _col){
	row = _row;
	col = _col;
}