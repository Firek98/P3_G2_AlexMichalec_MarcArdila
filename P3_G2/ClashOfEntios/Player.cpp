#include "Player.h"
#include <conio.h>
#include <stdlib.h>
#include "Input.inl.hh"
#include "Map.h"





Player::Player(Map m, char a) : map(m)
{
	a = value;
	hp = 10;
	for (int i = 0; i < map.rows(); i++)
	{
		for (int j = 0; j < map.columns(); j++)
		{
			if (map.md2(i, j) == value)
			{
				Coords.x = i;
				Coords.y = j;
			}
		}
	}
}

Player::~Player()
{
}




void Player::movement(enti::InputKey tecla) //WIP
{
	switch (tecla)
	{
	case enti::InputKey::NONE:
		break;
	case enti::InputKey::W:
		if (Coords.x > 0 && (map.md2(Coords.x, Coords.y - 1) == '.' || map.md2(Coords.x, Coords.y - 1) == ':')) {

			Coords.x--;
			map.Modify(Coords.x, Coords.y, value);
			if (map.md2(Coords.x + 1, Coords.y) == '.')
			{
				map.Modify(Coords.x + 1, Coords.y, '.');
			}
			else if (map.md2(Coords.x + 1, Coords.y) == ':')
			{
				map.Modify(Coords.x + 1, Coords.y, ':');
			}
	
		}
		break;
	case enti::InputKey::A:
		if (Coords.y > 0 && (map.md2(Coords.x - 1, Coords.y) == '.' || map.md2(Coords.x - 1, Coords.y) == ':')) {
	
			Coords.y--;
			map.Modify(Coords.x, Coords.y, value);
			if (map.md2(Coords.x, Coords.y + 1) == '.')
			{
				map.Modify(Coords.x, Coords.y + 1, '.');
			}
			else if (map.md2(Coords.x, Coords.y + 1) == ':')
			{
				map.Modify(Coords.x, Coords.y + 1, ':');
			}
			
		}
		break;
	case enti::InputKey::S:
		if (Coords.x < (map.rows() - 1) && (map.md2(Coords.x, Coords.y + 1) == '.' || map.md2(Coords.x, Coords.y + 1) == ':')) {

			Coords.x++;
			map.Modify(Coords.x, Coords.y, value);
			if (map.md2(Coords.x - 1, Coords.y) == '.')
			{
				map.Modify(Coords.x - 1, Coords.y, '.');
			}
			else if (map.md2(Coords.x - 1, Coords.y) == ':') 
			{
				map.Modify(Coords.x - 1, Coords.y, ':');
			}
		}
		break;
	case enti::InputKey::D:
		if (Coords.y < (map.columns() - 1) && (map.md2(Coords.x + 1, Coords.y) == '.' || map.md2(Coords.x + 1, Coords.y) == ':')) {

			Coords.y++;
			map.Modify(Coords.x, Coords.y, value);
			if (map.md2(Coords.x, Coords.y - 1) == '.')
			{
				map.Modify(Coords.x, Coords.y - 1, '.');
			}
			else if (map.md2(Coords.x, Coords.y - 1) == ':')
			{
				map.Modify(Coords.x, Coords.y - 1, ':');
			}
		}
		break;

	default:
		break;
	}
}

bool Player::isActive(bool a)
{
	return a;
}

void Player::attack()
{
	
}

bool Player::isAlive()
{
	if (hp <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
