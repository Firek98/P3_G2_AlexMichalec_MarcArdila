#pragma once
#include <conio.h>
#include "Input.inl.hh"
#include "Map.h"

struct coords {
	int x;
	int y;
};

class Player
{
	char value;
	int hp;
	coords Coords;
	bool active;
	bool moved;

public:
	Player(Map m, char a);
	~Player();
	void movement(enti::InputKey tecla);
	Map &map;
	void setActive(bool a);
	void attack();
	int playerHp();
	bool isAlive();
	bool isActive();
	char playerValue();
	bool playerMoved();

};