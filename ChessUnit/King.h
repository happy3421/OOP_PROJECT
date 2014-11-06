#include "Unit.h"
class King : public Unit{
private:
	void rotate(int);
	void reflect(int,int,Direction);
public:
	King();
};