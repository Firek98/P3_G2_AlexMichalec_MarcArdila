#pragma once
#include <conio.h>
#include "Input.inl.hh"
#include "Map.h"
struct properties
{
	int hp;
	char value;
	int x;
	int y;
};
struct player
{
	properties a;
	properties b;
	properties c;
	properties d;
	properties e;
	properties f;
};

class Player
{
	

public:
	Player(Map m);
	~Player();
	void movement(enti::InputKey tecla);
	Map &map;
	player Player1;
	player Player2;
	void turn();

};