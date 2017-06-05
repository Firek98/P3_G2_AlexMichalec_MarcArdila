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
	
	bool undone;
	char value;
	int hp;
	bool active;
	bool moved;
	char lastmovement;
	int arrows;
	int fatiga;
	int movimientos;

public:

	bool turno;
	Player(Map m, char a);
	~Player();
	void movement(enti::InputKey tecla);
	Map &map;
	coords Coords;
	void setActive(bool a);
	int playerHp();
	bool isAlive();
	bool isActive();
	char playerValue();
	bool playerMoved();
	int playerArrows();
	int playerFatiga();
	char attack();
	void damage(int a);
	void erase();
	void bowAttack(char values[]);
	void consumeArrows();
	void resetFatiga();
	char lastMovement();
	void resetMovement();
	void increaseMovements();
	void increaseFatiga();
	int playerMovements();
	

};