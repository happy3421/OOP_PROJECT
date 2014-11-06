#include "Unit.h"
class Splitter : public Unit{
public:
	Splitter();
};

//Splitter가 빔반사한다음, 빔생성 하나 더해야하는데 유닛에선 할수없는부분인듯.
//따라서, 빔반사 구현O, 빔생성 구현X