#include <iostream>
#include <stdlib.h>
#include "Map.h"
#include "Player.h"
#include "Renderer.hh"
#include <vector>

//FUNCIONES///////////////////////////////////////////////////////////////////////

//COMPROBAR SI UN ENTIO ESTA VIVO O MUERTO////////////////////////////////////////

void checkAlive(std::vector<Player*> &a, std::vector<Player*> &b)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i]->isAlive() == false)
		{
			a[i]->erase();
			a.erase(a.begin() + i);	
		}
	}
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i]->isAlive() == false)
		{
			b[i]->erase();
			b.erase(b.begin() + i);
		}
		
	}
}

//ALGORITMO PARA COMPROBAR QUE JUGADOR JUEGA SEGUN LA FATIGA///////////////////////

void setActivePlayer(std::vector<Player*> a, int actual, int &turnos)
{
	if (actual >= a.size())
	actual = 0;
	if (a.size()==1)
	{
		a[0]->setActive(true);
	}
	else
	{
		int max;
		int maxplayer = actual;
		max = a[actual]->playerFatiga();
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i]->playerFatiga() < max)
			{
				max = a[i]->playerFatiga();
				maxplayer = i;
				a[actual]->setActive(false);
			}
		}
		a[maxplayer]->setActive(true);
		if (maxplayer != actual)
			turnos--;
	}
}

//COMPROBAR QUE ENTIO ESTA ACTIVO//////////////////////////////////////////////////

int checkActive(std::vector<Player*>a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i]->isActive() == true)
		{
			return i;
		}
	}
}

//RESETEAR LA FATIGA//////////////////////////////////////////////////////////////

void resetFatiga(std::vector<Player*> &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		a[i]->resetFatiga();
	}
}

//FUNCIONES DE ATAQUE////////////////////////////////////////////////////////////

void checkTarget(std::vector<Player*> a, char target)
{

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i]->playerValue() == target)
		{
			a[i]->damage(10);
		}
	}
}

void attackBow(std::vector<Player*> a, char values[])
{
	int dmg = int(values[1]);
	char value = values[0];
	dmg = 11 - dmg;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i]->playerValue() == value)
			a[i]->damage(dmg);
	}
}

void main()
{
	//SETUP DE VARIABLES Y CLASES////////////////////////////////////////////////////////////////////


	enti::InputKey Tecla;
	enti::InputKey Weapon;
	Map mapa;
	int activePlayer1;
	int activePlayer2;
	int turnos;
	char target = 0;
	bool keypressed = false;
	char values[2] = { 0,0 };
	

	Player *player_a = new Player(mapa, 'A');
	Player *player_b = new Player(mapa, 'B');
	Player *player_c = new Player(mapa, 'C');
	Player *player_d = new Player(mapa, 'D');
	Player *player_e = new Player(mapa, 'E');
	Player *player_f = new Player(mapa, 'F');
	Player *player_1 = new Player(mapa, '1');
	Player *player_2 = new Player(mapa, '2');
	Player *player_3 = new Player(mapa, '3');
	Player *player_4 = new Player(mapa, '4');
	Player *player_5 = new Player(mapa, '5');
	Player *player_6 = new Player(mapa, '6');

	std::vector<Player*>Player1{ player_a, player_b, player_c, player_d, player_e, player_f };
	std::vector<Player*>Player2{ player_1, player_2, player_3, player_4, player_5, player_6 };
	Player1[0]->setActive(true);
	Player2[0]->setActive(true);
	activePlayer1 = 0;
	activePlayer2 = 0;
	mapa.printColoredMap();
	enti::cout << enti::cend;

	//BUCLE DE JUEGO/////////////////////////////////////////////////////////////////////////////

	while (Player1.empty() != true && Player2.empty() != true)
	{

		//JUGADOR 1//////////////////////////////////////////////////////////////////////////////
		{
			setActivePlayer(Player1, activePlayer1, turnos);
			turnos = 10;
			activePlayer1 = checkActive(Player1);
			mapa.printColoredMap();
			enti::cout << enti::Color::LIGHTMAGENTA << "PLAYER 1 TURN" << enti::endl;
			enti::cout << enti::Color::YELLOW << "ACTIVE PLAYER: " << enti::Color::LIGHTCYAN << Player1[activePlayer1]->playerValue() << enti::endl;
			enti::cout << enti::Color::YELLOW << "REMAINING MOVEMENTS " << enti::Color::LIGHTCYAN << turnos;
			enti::cout << enti::cend;
			do {
				Tecla = enti::getInputKey();
				if (Tecla != enti::InputKey::NONE)
				{
					char values[2] = { '0','0' };
					keypressed = false;
					system("cls");
					if (Player1[activePlayer1]->playerMovements() != 0 && Player1[activePlayer1]->turno==false)
					{
						Player1[activePlayer1]->increaseFatiga();
						Player1[activePlayer1]->turno = true;
					}
					activePlayer1 = checkActive(Player1);
					Player1[activePlayer1]->movement(Tecla);
					if (Tecla == enti::InputKey::ENTER)
					{
						setActivePlayer(Player1, activePlayer1, turnos);
					}
					if (Player1[activePlayer1]->playerMoved())
					{
						turnos--;
						Player1[activePlayer1]->increaseMovements();
						Player1[activePlayer1]->increaseFatiga();
					}
					if (Tecla == enti::InputKey::z)
					{
						switch (Player1[activePlayer1]->lastMovement())
						{
						case 'W':
							if (mapa.md2(Player1[activePlayer1]->Coords.x + 1, Player1[activePlayer1]->Coords.y) == '.')
							{
								mapa.Modify(Player1[activePlayer1]->Coords.x, Player1[activePlayer1]->Coords.y, '.');
							}
							else if (mapa.md2(Player1[activePlayer1]->Coords.x + 1, Player1[activePlayer1]->Coords.y) == ':')
							{
								mapa.Modify(Player1[activePlayer1]->Coords.x, Player1[activePlayer1]->Coords.y, ':');
							}
							Player1[activePlayer1]->Coords.x++;
							Player1[activePlayer1]->resetMovement();
							mapa.Modify(Player1[activePlayer1]->Coords.x, Player1[activePlayer1]->Coords.y, Player1[activePlayer1]->playerValue());
							turnos++;
							break;
						case 'A':
							if (mapa.md2(Player1[activePlayer1]->Coords.x, Player1[activePlayer1]->Coords.y + 1) == '.')
							{
								mapa.Modify(Player1[activePlayer1]->Coords.x, Player1[activePlayer1]->Coords.y, '.');
							}
							else if (mapa.md2(Player1[activePlayer1]->Coords.x, Player1[activePlayer1]->Coords.y + 1) == ':')
							{
								mapa.Modify(Player1[activePlayer1]->Coords.x, Player1[activePlayer1]->Coords.y, ':');
							}
							Player1[activePlayer1]->Coords.y++;
							Player1[activePlayer1]->resetMovement();
							mapa.Modify(Player1[activePlayer1]->Coords.x, Player1[activePlayer1]->Coords.y, Player1[activePlayer1]->playerValue());
							turnos++;
							break;
						case 'S':
							if (mapa.md2(Player1[activePlayer1]->Coords.x - 1, Player1[activePlayer1]->Coords.y) == '.')
							{
								mapa.Modify(Player1[activePlayer1]->Coords.x, Player1[activePlayer1]->Coords.y, '.');
							}
							else if (mapa.md2(Player1[activePlayer1]->Coords.x - 1, Player1[activePlayer1]->Coords.y) == ':')
							{
								mapa.Modify(Player1[activePlayer1]->Coords.x, Player1[activePlayer1]->Coords.y, ':');
							}
							Player1[activePlayer1]->Coords.x--;
							Player1[activePlayer1]->resetMovement();
							mapa.Modify(Player1[activePlayer1]->Coords.x, Player1[activePlayer1]->Coords.y, Player1[activePlayer1]->playerValue());
							turnos++;
							break;
						case 'D':
							if (mapa.md2(Player1[activePlayer1]->Coords.x, Player1[activePlayer1]->Coords.y - 1) == '.')
							{
								mapa.Modify(Player1[activePlayer1]->Coords.x, Player1[activePlayer1]->Coords.y, '.');
							}
							else if (mapa.md2(Player1[activePlayer1]->Coords.x, Player1[activePlayer1]->Coords.y - 1) == ':')
							{
								mapa.Modify(Player1[activePlayer1]->Coords.x, Player1[activePlayer1]->Coords.y, ':');
							}
							Player1[activePlayer1]->Coords.y--;
							Player1[activePlayer1]->resetMovement();
							mapa.Modify(Player1[activePlayer1]->Coords.x, Player1[activePlayer1]->Coords.y, Player1[activePlayer1]->playerValue());
							turnos++;
							break;
						}
					}
					if (Tecla == enti::InputKey::SPACEBAR)
					{
						mapa.printColoredMap();
						enti::cout << enti::Color::YELLOW << "CHOOSE A WEAPON: " << enti::endl;
						enti::cout << enti::Color::YELLOW << "1 - SWORD " << enti::endl;
						enti::cout << enti::Color::YELLOW << "2 - BOW (" << enti::Color::LIGHTCYAN << Player1[activePlayer1]->playerArrows() << enti::Color::YELLOW << " ARROWS)" <<  enti::endl;
						enti::cout << enti::cend;
						do {
							Weapon = enti::getInputKey();
							if (Weapon != enti::InputKey::NONE)
							{
								if (Weapon == enti::InputKey::NUM1)
								{
									target = Player1[activePlayer1]->attack();
									checkTarget(Player2, target);
									target = 0;
									keypressed = true;
									turnos--;
									Player1[activePlayer1]->increaseMovements();
									Player1[activePlayer1]->increaseFatiga();
								}
								if (Weapon == enti::InputKey::NUM2)
								{
									if (Player1[activePlayer1]->playerArrows() > 0)
									{
										Player1[activePlayer1]->bowAttack(values);
										if (values[0] != 0 && values[1] != 0)
										{
											attackBow(Player2, values);
											Player1[activePlayer1]->consumeArrows();
											turnos--;
											Player1[activePlayer1]->increaseMovements();
											Player1[activePlayer1]->increaseFatiga();
										}
									}
									else
									{
										mapa.printColoredMap();
										enti::cout << enti::Color::LIGHTRED << "NO ARROWS LEFT!" << enti::endl;
										enti::cout << enti::cend;
										enti::systemPause();
									}

									keypressed = true;
								}
								else
									keypressed = true;
							}
						} while (keypressed == false);
						
					}
					checkAlive(Player1, Player2);
					activePlayer1 = checkActive(Player1);
					mapa.printColoredMap();
					enti::cout << enti::Color::LIGHTMAGENTA << "PLAYER 1 TURN" << enti::endl;
					enti::cout << enti::Color::YELLOW << "ACTIVE PLAYER: " << enti::Color::LIGHTCYAN << Player1[activePlayer1]->playerValue() << enti::endl;
					enti::cout << enti::Color::YELLOW << "REMAINING MOVEMENTS: " << enti::Color::LIGHTCYAN << turnos;
					enti::cout << enti::cend;

				}
			} while (turnos != 0);
		}
		//CAMBIO DE TURNO//
		//////////////////////////////////////////////////////////////////////////////////////
		{
			setActivePlayer(Player1, activePlayer1, turnos);
			activePlayer1 = checkActive(Player1);
			mapa.printColoredMap();
			enti::cout << enti::endl;
			enti::cout << enti::Color::LIGHTMAGENTA << "PRESS ENTER TO END YOUR TURN" << enti::endl;
			enti::cout << enti::cend;
			resetFatiga(Player1);
			do
			{
				Tecla = enti::getInputKey();
			} while (Tecla != enti::InputKey::ENTER);

			system("cls");
			mapa.printColoredMap();
			enti::cout << enti::cend;
			if (Player2.empty())
			{
				system("cls");
				enti::cout << enti::Color::LIGHTMAGENTA << "PLAYER 1 WINS!" << enti::endl;
				enti::cout << enti::cend;
				enti::systemPause();
				exit(EXIT_SUCCESS);
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////

		//JUGADOR 2///////////////////////////////////////////////////////////////////////////
		{
			setActivePlayer(Player2, activePlayer2, turnos);
			turnos = 10;
			activePlayer2 = checkActive(Player2);
			mapa.printColoredMap();
			enti::cout << enti::Color::LIGHTMAGENTA << "PLAYER 2 TURN" << enti::endl;
			enti::cout << enti::Color::YELLOW << "ACTIVE PLAYER: " << enti::Color::LIGHTCYAN << Player2[activePlayer2]->playerValue() << enti::endl;
			enti::cout << enti::Color::YELLOW << "REMAINING MOVEMENTS: " << enti::Color::LIGHTCYAN << turnos;
			enti::cout << enti::cend;
			do {
				Tecla = enti::getInputKey();
				if (Tecla != enti::InputKey::NONE)
				{
					char values[2] = { '0','0' };
					keypressed = false;
					system("cls");
					if (Player2[activePlayer2]->playerMovements() != 0 && Player2[activePlayer2]->turno == false)
					{
						Player2[activePlayer2]->increaseFatiga();
						Player2[activePlayer2]->turno = true;
					}
					activePlayer2 = checkActive(Player2);
					Player2[activePlayer2]->movement(Tecla);
					if (Tecla == enti::InputKey::ENTER)
					{
						setActivePlayer(Player2, activePlayer2, turnos);
					}
					if (Player2[activePlayer2]->playerMoved())
					{
						turnos--;
						Player2[activePlayer2]->increaseMovements();
						Player2[activePlayer2]->increaseFatiga();
					}
					if (Tecla == enti::InputKey::z)
					{
						switch (Player2[activePlayer2]->lastMovement())
						{
						case 'W':
							if (mapa.md2(Player2[activePlayer2]->Coords.x + 1, Player2[activePlayer2]->Coords.y) == '.')
							{
								mapa.Modify(Player2[activePlayer2]->Coords.x, Player2[activePlayer2]->Coords.y, '.');
							}
							else if (mapa.md2(Player2[activePlayer2]->Coords.x + 1, Player2[activePlayer2]->Coords.y) == ':')
							{
								mapa.Modify(Player2[activePlayer2]->Coords.x, Player2[activePlayer2]->Coords.y, ':');
							}
							Player2[activePlayer2]->Coords.x++;
							Player2[activePlayer2]->resetMovement();
							mapa.Modify(Player2[activePlayer2]->Coords.x, Player2[activePlayer2]->Coords.y, Player2[activePlayer2]->playerValue());
							turnos++;
							break;
						case 'A':
							if (mapa.md2(Player2[activePlayer2]->Coords.x, Player2[activePlayer2]->Coords.y + 1) == '.')
							{
								mapa.Modify(Player2[activePlayer2]->Coords.x, Player2[activePlayer2]->Coords.y, '.');
							}
							else if (mapa.md2(Player2[activePlayer2]->Coords.x, Player2[activePlayer2]->Coords.y + 1) == ':')
							{
								mapa.Modify(Player2[activePlayer2]->Coords.x, Player2[activePlayer2]->Coords.y, ':');
							}
							Player2[activePlayer2]->Coords.y++;
							Player2[activePlayer2]->resetMovement();
							mapa.Modify(Player2[activePlayer2]->Coords.x, Player2[activePlayer2]->Coords.y, Player2[activePlayer2]->playerValue());
							turnos++;
							break;
						case 'S':
							if (mapa.md2(Player2[activePlayer2]->Coords.x - 1, Player2[activePlayer2]->Coords.y) == '.')
							{
								mapa.Modify(Player2[activePlayer2]->Coords.x, Player2[activePlayer2]->Coords.y, '.');
							}
							else if (mapa.md2(Player2[activePlayer2]->Coords.x - 1, Player2[activePlayer2]->Coords.y) == ':')
							{
								mapa.Modify(Player2[activePlayer2]->Coords.x, Player2[activePlayer2]->Coords.y, ':');
							}
							Player2[activePlayer2]->Coords.x--;
							Player2[activePlayer2]->resetMovement();
							mapa.Modify(Player2[activePlayer2]->Coords.x, Player2[activePlayer2]->Coords.y, Player2[activePlayer2]->playerValue());
							turnos++;
							break;
						case 'D':
							if (mapa.md2(Player2[activePlayer2]->Coords.x, Player2[activePlayer2]->Coords.y - 1) == '.')
							{
								mapa.Modify(Player2[activePlayer2]->Coords.x, Player2[activePlayer2]->Coords.y, '.');
							}
							else if (mapa.md2(Player2[activePlayer2]->Coords.x, Player2[activePlayer2]->Coords.y - 1) == ':')
							{
								mapa.Modify(Player2[activePlayer2]->Coords.x, Player2[activePlayer2]->Coords.y, ':');
							}
							Player2[activePlayer2]->Coords.y--;
							Player2[activePlayer2]->resetMovement();
							mapa.Modify(Player2[activePlayer2]->Coords.x, Player2[activePlayer2]->Coords.y, Player2[activePlayer2]->playerValue());
							turnos++;
							break;
						}
					}
					if (Tecla == enti::InputKey::SPACEBAR)
					{
						mapa.printColoredMap();
						enti::cout << enti::Color::YELLOW << "CHOOSE A WEAPON: " << enti::endl;
						enti::cout << enti::Color::YELLOW << "1 - SWORD " << enti::endl;
						enti::cout << enti::Color::YELLOW << "2 - BOW (" << enti::Color::LIGHTCYAN << Player2[activePlayer2]->playerArrows() << enti::Color::YELLOW << " ARROWS)" << enti::endl;
						enti::cout << enti::cend;
						do {
							Weapon = enti::getInputKey();
							if (Weapon != enti::InputKey::NONE)
							{
								if (Weapon == enti::InputKey::NUM1)
								{
									target = Player2[activePlayer2]->attack();
									checkTarget(Player1, target);
									target = 0;
									keypressed = true;
									turnos--;
									Player2[activePlayer2]->increaseMovements();
									Player2[activePlayer2]->increaseFatiga();
								}
								if (Weapon == enti::InputKey::NUM2)
								{
									if (Player2[activePlayer2]->playerArrows() > 0)
									{
										Player2[activePlayer2]->bowAttack(values);
										if (values[0] != 0 && values[1] != 0)
										{
											attackBow(Player1, values);
											Player2[activePlayer2]->consumeArrows();
											turnos--;
											Player2[activePlayer2]->increaseMovements();
											Player2[activePlayer2]->increaseFatiga();
										}
									}
									else
									{
										mapa.printColoredMap();
										enti::cout << enti::Color::LIGHTRED << "NO ARROWS LEFT!" << enti::endl;
										enti::cout << enti::cend;
										enti::systemPause();
									}

									keypressed = true;
								}
								else
									keypressed = true;
							}
						} while (keypressed == false);

					}
					
					checkAlive(Player1, Player2);
					activePlayer2 = checkActive(Player2);
					mapa.printColoredMap();
					enti::cout << enti::Color::LIGHTMAGENTA << "PLAYER 2 TURN" << enti::endl;
					enti::cout << enti::Color::YELLOW << "ACTIVE PLAYER: " << enti::Color::LIGHTCYAN << Player2[activePlayer2]->playerValue() << enti::endl;
					enti::cout << enti::Color::YELLOW << "REMAINING MOVEMENTS: " << enti::Color::LIGHTCYAN << turnos;
					enti::cout << enti::cend;

				}
			} while (turnos != 0);
		}
		//CAMBIO DE TURNO//
		//////////////////////////////////////////////////////////////////////////////////////
		{
			setActivePlayer(Player2, activePlayer2, turnos);
			activePlayer2 = checkActive(Player1);
			mapa.printColoredMap();
			enti::cout << enti::endl;
			enti::cout << enti::Color::LIGHTMAGENTA << "PRESS ENTER TO END YOUR TURN" << enti::endl;
			enti::cout << enti::cend;
			do
			{
				Tecla = enti::getInputKey();
			} while (Tecla != enti::InputKey::ENTER);

			system("cls");
			mapa.printColoredMap();
			enti::cout << enti::cend;
		}
	    //////////////////////////////////////////////////////////////////////////////////////
		
	}
	system("cls");
	enti::cout << enti::Color::LIGHTMAGENTA << "PLAYER 2 WINS!" << enti::endl;
	enti::cout << enti::cend;
	enti::systemPause();
}