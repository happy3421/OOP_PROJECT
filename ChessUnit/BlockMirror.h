#include "Unit.h"
class BlockMirror : public Unit{
private:
	void reflect(int&, int&, Direction&);
public:
	BlockMirror();
};