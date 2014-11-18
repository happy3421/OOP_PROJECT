#include "Cell.h"

int Cell::getCol(){ return col; }
int Cell::getRow(){ return row; }

void Cell::unitRotate(int CLK){ unit->rotate(CLK); }

void Cell::setUnit(Unit& _unit){ 
	unit=&_unit;
	accessible = false;
}

void Cell::unitMove(Cell& _cell){
	unit->move(&_cell);
	_cell.setUnit(*unit);
	unit = NULL;
	if (unit->getUnitType() == SPLITTER && _cell.accessible == false){
		setUnit(*(_cell.unit));
		_cell.setUnit(*unit);
		unit->move(this);
		_cell.unit->move(&_cell);
	}
}

void Cell::killUnit(){
	unit->die();
	accessible = true;
	unit = NULL;
}

void Cell::setPos(int _row, int _col){
	row = _row;
	col = _col;
}