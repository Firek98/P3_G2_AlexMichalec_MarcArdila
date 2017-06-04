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
	bool undo;
	bool redo;
	int arrows;

public:

	bool turno;
	int fatiga;
	int movimientos;
	Player(Map m, char a);
	~Player();
	void movement(enti::InputKey tecla);
	Map &map;
	void setActive(bool a);
	int playerHp();
	bool isAlive();
	bool isActive();
	char playerValue();
	bool playerMoved();
	bool playerUndo();
	bool playerRedo();
	int playerArrows();
	int playerFatiga();
	char attack();
	void damage(int a);
	void erase();
	void bowAttack(char values[]);
	void consumeArrows();
	void resetFatiga();

	

};