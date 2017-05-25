#include "Player.h"
#include <conio.h>
#include <stdlib.h>
#include "Input.inl.hh"
#include "Map.h"


char Pj = '@';


Player::Player(Map m) : map(m)
{
}

Player::~Player()
{
}

void Player::pos()
{

}


void Player::movement(enti::InputKey tecla) //WIP
{
	switch (tecla)
	{
	case enti::InputKey::NONE:
		break;
	case enti::InputKey::W:
		if (Coords.x > 0) {

			Coords.x--;
			map.Modify(Coords.x, Coords.y, '@');
			map.Modify(Coords.x + 1, Coords.y, '.');
		}
		break;
	case enti::InputKey::A:
		if (Coords.y > 0) {
	
			Coords.y--;
			map.Modify(Coords.x, Coords.y, '@');
			map.Modify(Coords.x, Coords.y + 1, '.');
		}
		break;
	case enti::InputKey::S:
		if (Coords.x < (map.rows() - 1)) {

			Coords.x++;
			map.Modify(Coords.x, Coords.y, '@');
			map.Modify(Coords.x - 1, Coords.y, '.');
		}
		break;
	case enti::InputKey::D:
		if (Coords.y < (map.columns() - 1)) {

			Coords.y++;
			map.Modify(Coords.x, Coords.y, '@');
			map.Modify(Coords.x, Coords.y - 1, '.');
		}
		break;

	default:
		break;
	}
}