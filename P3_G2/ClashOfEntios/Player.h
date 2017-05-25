#pragma once
#include <conio.h>
#include "Input.inl.hh"
class Player
{

public:
	Player(Map m);
	~Player();
	void pos();
	void movement(enti::InputKey tecla);
	Map &map;
	coord Coords;

};
};

