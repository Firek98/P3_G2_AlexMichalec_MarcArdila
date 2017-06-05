#include "Player.h"
#include <conio.h>
#include <stdlib.h>
#include "Input.inl.hh"
#include "Map.h"
#include "Renderer.hh"





Player::Player(Map m, char a) : map(m)
{
	firstmove = false;
	lastmovement = '0';
	movimientos = 0;
	turno = false;
	fatiga = 0;
	arrows = 10;
	value = a;
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




void Player::movement(enti::InputKey tecla)
{
	moved = false;
	char static aux;
	if (firstmove == false)
	{
		aux = '.';
		firstmove = true;
	}
		switch (tecla)
		{
		case enti::InputKey::NONE:			
			break;
		case enti::InputKey::W:
			if (Coords.x > 0 && (map.md2(Coords.x - 1, Coords.y) == '.' || map.md2(Coords.x - 1, Coords.y) == ':')) {

				map.Modify(Coords.x, Coords.y, aux);
				Coords.x--;
				if (aux != map.md2(Coords.x, Coords.y))
				{
					aux = map.md2(Coords.x, Coords.y);
				}
				map.Modify(Coords.x, Coords.y, value);
				moved = true;
				lastmovement = 'W';
			}
			else
				moved = false;
			break;
		case enti::InputKey::A:
			if (Coords.y > 0 && (map.md2(Coords.x, Coords.y - 1) == '.' || map.md2(Coords.x, Coords.y - 1) == ':')) {

				map.Modify(Coords.x, Coords.y, aux);
				Coords.y--;
				if (aux != map.md2(Coords.x, Coords.y))
				{
					aux = map.md2(Coords.x, Coords.y);
				}
				map.Modify(Coords.x, Coords.y, value);
				moved = true;
				lastmovement = 'A';
			}
			else
				moved = false;
			break;
		case enti::InputKey::S:
			if (Coords.x < (map.rows() - 1) && (map.md2(Coords.x + 1, Coords.y) == '.' || map.md2(Coords.x + 1, Coords.y) == ':')) {

				map.Modify(Coords.x, Coords.y, aux);
				Coords.x++;
				if (aux != map.md2(Coords.x, Coords.y))
				{
					aux = map.md2(Coords.x, Coords.y);
				}
				map.Modify(Coords.x, Coords.y, value);
				moved = true;
				lastmovement = 'S';
			}
			else
				moved = false;
			break;
		case enti::InputKey::D:
			if (Coords.y < (map.columns() - 1) && (map.md2(Coords.x, Coords.y + 1) == '.' || map.md2(Coords.x, Coords.y + 1) == ':')) {

				map.Modify(Coords.x, Coords.y, aux);
				Coords.y++;
				if (aux != map.md2(Coords.x, Coords.y))
				{
					aux = map.md2(Coords.x, Coords.y);
				}
				map.Modify(Coords.x, Coords.y, value);
				moved = true;
				lastmovement = 'D';
			}
			else
				moved = false;
			break;			
		case enti::InputKey::ENTER:
			active = false;			
		default:
			break;
		}
	}


void Player::setActive(bool a)
{
	active = a;
}

char Player::attack()
 {
	bool keypressed = false;
	enti::InputKey dir;
	map.printColoredMap();
	enti::cout << enti::Color::YELLOW << "WHAT DIRECTION?" << enti::endl;
	enti::cout << "1 - UP" << enti::endl;
	enti::cout << "2 - DOWN" << enti::endl;
	enti::cout << "3 - LEFT" << enti::endl;
	enti::cout << "4 - RIGHT" << enti::endl;
	enti::cout << enti::cend;
	do {
		dir = enti::getInputKey();
		if (dir != enti::InputKey::NONE)
		{
			switch (dir)
			{
			case enti::InputKey::NUM1:
				if (map.md2(Coords.x - 1, Coords.y) == 'A')
					return 'A';
				else if (map.md2(Coords.x - 1, Coords.y) == 'B')
					return 'B';
				else if (map.md2(Coords.x - 1, Coords.y) == 'C')
					return 'C';
				else if (map.md2(Coords.x - 1, Coords.y) == 'D')
					return 'D';
				else if (map.md2(Coords.x - 1, Coords.y) == 'E')
					return 'E';
				else if (map.md2(Coords.x - 1, Coords.y) == 'F')
					return 'F';
				else if (map.md2(Coords.x - 1, Coords.y) == '1')
					return '1';
				else if (map.md2(Coords.x - 1, Coords.y) == '2')
					return '2';
				else if (map.md2(Coords.x - 1, Coords.y) == '3')
					return '3';
				else if (map.md2(Coords.x - 1, Coords.y) == '4')
					return '4';
				else if (map.md2(Coords.x - 1, Coords.y) == '5')
					return '5';
				else if (map.md2(Coords.x - 1, Coords.y) == '6')
					return '6';
				else
				{
					map.printColoredMap();
					enti::cout << enti::Color::YELLOW << "YOU FAILED" << enti::endl;
					enti::cout << enti::cend;
					enti::systemPause();
					return '0';
				}
				keypressed = true;
				break;
			case enti::InputKey::NUM2:
				if (map.md2(Coords.x + 1, Coords.y) == 'A')
					return 'A';
				else if (map.md2(Coords.x + 1, Coords.y) == 'B')
					return 'B';
				else if (map.md2(Coords.x + 1, Coords.y) == 'C')
					return 'C';
				else if (map.md2(Coords.x + 1, Coords.y) == 'D')
					return 'D';
				else if (map.md2(Coords.x + 1, Coords.y) == 'E')
					return 'E';
				else if (map.md2(Coords.x + 1, Coords.y) == 'F')
					return 'F';
				else if (map.md2(Coords.x + 1, Coords.y) == '1')
					return '1';
				else if (map.md2(Coords.x + 1, Coords.y) == '2')
					return '2';
				else if (map.md2(Coords.x + 1, Coords.y) == '3')
					return '3';
				else if (map.md2(Coords.x + 1, Coords.y) == '4')
					return '4';
				else if (map.md2(Coords.x + 1, Coords.y) == '5')
					return '5';
				else if (map.md2(Coords.x + 1, Coords.y) == '6')
					return '6';
				else
				{
					map.printColoredMap();
					enti::cout << enti::Color::YELLOW << "YOU FAILED" << enti::endl;
					enti::cout << enti::cend;
					enti::systemPause();
					return '0';
				}
				keypressed = true;
				break;
			case enti::InputKey::NUM3:
				if (map.md2(Coords.x, Coords.y - 1) == 'A')
					return 'A';
				else if (map.md2(Coords.x, Coords.y - 1) == 'B')
					return 'B';
				else if (map.md2(Coords.x, Coords.y - 1) == 'C')
					return 'C';
				else if (map.md2(Coords.x, Coords.y - 1) == 'D')
					return 'D';
				else if (map.md2(Coords.x, Coords.y - 1) == 'E')
					return 'E';
				else if (map.md2(Coords.x, Coords.y - 1) == 'F')
					return 'F';
				else if (map.md2(Coords.x, Coords.y - 1) == '1')
					return '1';
				else if (map.md2(Coords.x, Coords.y - 1) == '2')
					return '2';
				else if (map.md2(Coords.x, Coords.y - 1) == '3')
					return '3';
				else if (map.md2(Coords.x, Coords.y - 1) == '4')
					return '4';
				else if (map.md2(Coords.x, Coords.y - 1) == '5')
					return '5';
				else if (map.md2(Coords.x, Coords.y - 1) == '6')
					return '6';
				else
				{
					map.printColoredMap();
					enti::cout << enti::Color::YELLOW << "YOU FAILED" << enti::endl;
					enti::cout << enti::cend;
					enti::systemPause();
					return '0';
				}
				keypressed = true;
				break;
			case enti::InputKey::NUM4:
				if (map.md2(Coords.x, Coords.y + 1) == 'A')
					return 'A';
				else if (map.md2(Coords.x, Coords.y + 1) == 'B')
					return 'B';
				else if (map.md2(Coords.x, Coords.y + 1) == 'C')
					return 'C';
				else if (map.md2(Coords.x, Coords.y + 1) == 'D')
					return 'D';
				else if (map.md2(Coords.x, Coords.y + 1) == 'E')
					return 'E';
				else if (map.md2(Coords.x, Coords.y + 1) == 'F')
					return 'F';
				else if (map.md2(Coords.x, Coords.y + 1) == '1')
					return '1';
				else if (map.md2(Coords.x, Coords.y + 1) == '2')
					return '2';
				else if (map.md2(Coords.x, Coords.y + 1) == '3')
					return '3';
				else if (map.md2(Coords.x, Coords.y + 1) == '4')
					return '4';
				else if (map.md2(Coords.x, Coords.y + 1) == '5')
					return '5';
				else if (map.md2(Coords.x, Coords.y + 1) == '6')
					return '6';
				else
				{
					map.printColoredMap();
					enti::cout << enti::Color::YELLOW << "YOU FAILED" << enti::endl;
					enti::cout << enti::cend;
					enti::systemPause();
					return '0';
				}
			}
			}
			
		}while (keypressed == false);
	}

void Player::bowAttack(char values[])
{
	int i = 3;
	bool keypressed = false;
	enti::InputKey dir;
	map.printColoredMap();
	enti::cout << enti::Color::YELLOW << "WHAT DIRECTION?" << enti::endl;
	enti::cout << "1 - UP" << enti::endl;
	enti::cout << "2 - DOWN" << enti::endl;
	enti::cout << "3 - LEFT" << enti::endl;
	enti::cout << "4 - RIGHT" << enti::endl;
	enti::cout << enti::cend;
	do {
		dir = enti::getInputKey();
		if (dir != enti::InputKey::NONE)
		{
			switch (dir)
			{
			case enti::InputKey::NUM1:
				while(i<=10)
				{
					if (map.md2(Coords.x - i, Coords.y) == 'X')
					{
						values[0] = '0';
						values[1] = '0';
						break;
					}
					if (map.md2(Coords.x - i, Coords.y) == 'A')
					{
						values[0] = 'A';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x - i, Coords.y) == 'B')
					{
						values[0] = 'B';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x - i, Coords.y) == 'C')
					{
						values[0] = 'C';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x - i, Coords.y) == 'D')
					{
						values[0] = 'D';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x - i, Coords.y) == 'E')
					{
						values[0] = 'E';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x - i, Coords.y) == 'F')
					{
						values[0] = 'F';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x - i, Coords.y) == '1')
					{
						values[0] = '1';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x - i, Coords.y) == '2')
					{
						values[0] = '2';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x - i, Coords.y) == '3')
					{
						values[0] = '3';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x - i, Coords.y) == '4')
					{
						values[0] = '4';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x - i, Coords.y) == '5')
					{
						values[0] = '5';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x - i, Coords.y) == '6')
					{
						values[0] = '6';
						values[1] = i;
						break;
					}
					i++;
				}
				if (values[0] == '0' && values[1] == '0')
				{
					map.printColoredMap();
					enti::cout << enti::Color::YELLOW << "YOU FAILED" << enti::endl;
					enti::cout << enti::cend;
					enti::systemPause();
				}
				keypressed = true;
				break;
			case enti::InputKey::NUM2:
				while (i <= 10)
				{
					if (map.md2(Coords.x + i, Coords.y) == 'X')
					{
						values[0] = '0';
						values[1] = '0';
						break;
					}
					if (map.md2(Coords.x + i, Coords.y) == 'A')
					{
						values[0] = 'A';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x + i, Coords.y) == 'B')
					{
						values[0] = 'B';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x + i, Coords.y) == 'C')
					{
						values[0] = 'C';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x + i, Coords.y) == 'D')
					{
						values[0] = 'D';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x + i, Coords.y) == 'E')
					{
						values[0] = 'E';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x + i, Coords.y) == 'F')
					{
						values[0] = 'F';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x + i, Coords.y) == '1')
					{
						values[0] = '1';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x + i, Coords.y) == '2')
					{
						values[0] = '2';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x + i, Coords.y) == '3')
					{
						values[0] = '3';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x + i, Coords.y) == '4')
					{
						values[0] = '4';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x + i, Coords.y) == '5')
					{
						values[0] = '5';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x + i, Coords.y) == '6')
					{
						values[0] = '6';
						values[1] = i;
						break;
					}
					i++;
				}
				if (values[0] == '0' && values[1] == '0')
				{
					map.printColoredMap();
					enti::cout << enti::Color::YELLOW << "YOU FAILED" << enti::endl;
					enti::cout << enti::cend;
					enti::systemPause();
				}
				keypressed = true;
				break;
			case enti::InputKey::NUM3:
				while (i <= 10)
				{
					if (map.md2(Coords.x, Coords.y - i) == 'X')
					{
						values[0] = '0';
						values[1] = '0';
						break;
					}
					if (map.md2(Coords.x, Coords.y - i) == 'A')
					{
						values[0] = 'A';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y - i) == 'B')
					{
						values[0] = 'B';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y - i) == 'C')
					{
						values[0] = 'C';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y - i) == 'D')
					{
						values[0] = 'D';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y - i) == 'E')
					{
						values[0] = 'E';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y - i) == 'F')
					{
						values[0] = 'F';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y - i) == '1')
					{
						values[0] = '1';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y - i) == '2')
					{
						values[0] = '2';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y - i) == '3')
					{
						values[0] = '3';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y - i) == '4')
					{
						values[0] = '4';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y - i) == '5')
					{
						values[0] = '5';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y - i) == '6')
					{
						values[0] = '6';
						values[1] = i;
						break;
					}
					i++;
				}
				if (values[0] == '0' && values[1] == '0')
				{
					map.printColoredMap();
					enti::cout << enti::Color::YELLOW << "YOU FAILED" << enti::endl;
					enti::cout << enti::cend;
					enti::systemPause();
				}
				keypressed = true;
				break;
			case enti::InputKey::NUM4:
				while (i <= 10)
				{
					if (map.md2(Coords.x, Coords.y + i) == 'X')
					{
						values[0] = '0';
						values[1] = '0';
						break;
					}
					if (map.md2(Coords.x, Coords.y + i) == 'A')
					{
						values[0] = 'A';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y + i) == 'B')
					{
						values[0] = 'B';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y + i) == 'C')
					{
						values[0] = 'C';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y + i) == 'D')
					{
						values[0] = 'D';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y + i) == 'E')
					{
						values[0] = 'E';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y + i) == 'F')
					{
						values[0] = 'F';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y + i) == '1')
					{
						values[0] = '1';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y + i) == '2')
					{
						values[0] = '2';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y + i) == '3')
					{
						values[0] = '3';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y + i) == '4')
					{
						values[0] = '4';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y + i) == '5')
					{
						values[0] = '5';
						values[1] = i;
						break;
					}
					else if (map.md2(Coords.x, Coords.y + i) == '6')
					{
						values[0] = '6';
						values[1] = i;
						break;
					}
					i++;
				}
				if (values[0] == '0' && values[1] == '0')
				{
					map.printColoredMap();
					enti::cout << enti::Color::YELLOW << "YOU FAILED" << enti::endl;
					enti::cout << enti::cend;
					enti::systemPause();
				}
				keypressed = true;
				break;
			}
		}
	} while (keypressed == false);
}

void Player::consumeArrows()
{
	arrows--;
}

void Player::resetFatiga()
{
	fatiga -= movimientos;
	movimientos = 0;
	turno = false;
}

char Player::lastMovement()
{
	return lastmovement;
}

void Player::resetMovement()
{
	lastmovement = '0';
}

void Player::increaseMovements()
{
	movimientos++;
}

void Player::increaseFatiga()
{
	fatiga++;
}

int Player::playerMovements()
{
	return movimientos;
}



void Player::damage(int a)
{
	hp -= a;
}

void Player::erase()
{
	value = '.';
	map.Modify(Coords.x, Coords.y, value);
}

	

int Player::playerArrows()
{
	return arrows;
}

int Player::playerFatiga()
{
	return fatiga;
}


int Player::playerHp()
{
	return hp;
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

bool Player::isActive()
{
	return active;
}

char Player::playerValue()
{
	return value;
}

bool Player::playerMoved()
{
	return moved;
}






