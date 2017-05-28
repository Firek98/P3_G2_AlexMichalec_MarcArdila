#include "Player.h"
#include <conio.h>
#include <stdlib.h>
#include "Input.inl.hh"
#include "Map.h"





Player::Player(Map m) : map(m)
{
	Player1.a.hp = 10;
	Player1.b.hp = 10;
	Player1.c.hp = 10;
	Player1.d.hp = 10;
	Player1.e.hp = 10;
	Player1.f.hp = 10;
	Player2.a.hp = 10;
	Player2.b.hp = 10;
	Player2.c.hp = 10;
	Player2.d.hp = 10;
	Player2.e.hp = 10;
	Player2.f.hp = 10;
	 
	for (int i = 0; i < map.rows(); i++) {

		for (int j = 0; j < map.columns(); j++)
		{
			switch (map.md2(i, j))
			{
			case 'A':
				Player1.a.value = 'A';
				Player1.a.x = i;
				Player1.a.y = j;
				break;
			case 'B':
				Player1.b.value = 'B';
				Player1.b.x = i;
				Player1.b.y = j;
				break;
			case 'C':
				Player1.c.value = 'C';
				Player1.c.x = i;
				Player1.c.y = j;
				break;
			case 'D':
				Player1.d.value = 'D';
				Player1.d.x = i;
				Player1.d.y = j;
				break;
			case 'E':
				Player1.e.value = 'E';
				Player1.e.x = i;
				Player1.e.y = j;
				break;
			case 'F':
				Player1.f.value = 'F';
				Player1.f.x = i;
				Player1.f.y = j;
				break;
			case '1':
				Player2.a.value = '1';
				Player2.a.x = i;
				Player2.a.y = j;
				break;
			case '2':
				Player2.b.value = '2';
				Player2.b.x = i;
				Player2.b.y = j;
				break;
			case '3':
				Player2.c.value = '3';
				Player2.c.x = i;
				Player2.c.y = j;
				break;
			case '4':
				Player2.d.value = '4';
				Player2.d.x = i;
				Player2.d.y = j;
				break;
			case '5':
				Player2.e.value = '5';
				Player2.e.x = i;
				Player2.e.y = j;
				break;
			case '6':
				Player2.f.value = '6';
				Player2.f.x = i;
				Player2.f.y = j;
				break;
			}
		}

	}

}

Player::~Player()
{
}


void Player::turn()
{

}

void Player::movement(enti::InputKey tecla) //WIP
{
	switch (tecla)
	{
	case enti::InputKey::NONE:
		break;
	case enti::InputKey::W:
		if (Player1.a.x > 0) {

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
