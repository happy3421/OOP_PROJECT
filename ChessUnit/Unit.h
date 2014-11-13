#include "../Global.h"

#ifndef UNIT_H
#define UNIT_H

#include "../InGame/Cell.h"

class Unit{
private:
	bool alive;
	Cell* cell;
	UnitType unittype;
	Team team;
protected:
	Direction dir;
public:
	Unit(UnitType);
	void die();
	void init(Direction, Cell*, Team);
	void rotate(int);
	void move(Cell*);
	void reflect(int&,int&, Direction&);
};

#endif UNIT_H