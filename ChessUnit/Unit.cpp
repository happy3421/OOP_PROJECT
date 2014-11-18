#include "Unit.h"
Unit::Unit(UnitType unittype){
	this->unittype=unittype;
	this->alive=1;
}
void Unit::init(Direction dir, Cell* cell, Team team){
	this->dir=dir;
	this->cell=cell;
	this->team=team;
}

UnitType Unit::getUnitType(){ return unittype; }

void Unit::rotate(int CLK){
	int dir_num=this->dir;
	
	if(CLK==1)
		dir_num++;
	else if(CLK==-1)
		dir_num--;
	
	if(dir_num>3)
		dir_num=0;
	else if(dir_num<0)
		dir_num=3;

	this->dir=static_cast<Direction>(dir_num);
}
void Unit::move(Cell *cell){
	this->cell=cell;
}
void Unit::reflect(int &beamrow,int &beamcol,Direction &beamdir){
	switch(beamdir){
		case SOUTH:	//�������� ������ �Ʒ���
			switch(this->dir){
				case NORTH:	//������� NORTH�� ����
					beamdir=EAST;			
					beamrow++;
					break;
				case WEST:
					beamdir=WEST;
					beamrow--;
					break;
				default:
					die();
					break;
			}
		case NORTH:	//�������� �Ʒ��� ����
			switch(this->dir){
				case SOUTH:	//�����
					beamdir=WEST;			
					beamrow--;
					break;
				case EAST:
					beamdir=EAST;
					beamrow++;
					break;
				default:
					die();
					break;
			}
		case EAST:	//�������� �����ʹ������� ���� ->
			switch(this->dir){
				case SOUTH:	//�����
					beamdir=SOUTH;			
					beamcol++;
					break;
				case WEST:
					beamdir=NORTH;
					beamcol--;
					break;
				default:
					die();
					break;
			}
		case WEST:
			switch(this->dir){
				case NORTH:	//�����
					beamdir=NORTH;			
					beamcol--;
					break;
				case WEST:
					beamdir=SOUTH;
					beamcol++;
					break;
				default:
					die();
					break;
			}
	}
}
void Unit::die(){
	this->cell=NULL;
	alive=0;
}