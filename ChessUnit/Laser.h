#include "Unit.h"
class Laser : public Unit{
private:
	void move(Cell*);
	void reflect(int,int,Direction);
public:
	Laser();
};
