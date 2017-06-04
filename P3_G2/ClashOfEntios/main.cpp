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
//WIP///

void setActivePlayer(std::vector<Player*> a, int actual)
{
	
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
	int activePlayer;
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
	mapa.printColoredMap();
	enti::cout << enti::cend;

	//BUCLE DE JUEGO/////////////////////////////////////////////////////////////////////////////

	while (Player1.empty() == false || Player2.empty() == false)
	{

		//JUGADOR 1//////////////////////////////////////////////////////////////////////////////
		{
			
			turnos = 10;
			activePlayer = checkActive(Player1);
			mapa.printColoredMap();
			enti::cout << enti::Color::LIGHTMAGENTA << "TURNO DEL JUGADOR 1" << enti::endl;
			enti::cout << enti::Color::YELLOW << "JUGADOR ACTIVO: " << enti::Color::LIGHTCYAN << Player1[activePlayer]->playerValue() << enti::endl;
			enti::cout << enti::Color::YELLOW << "MOVIMIENTOS RESTANTES: " << enti::Color::LIGHTCYAN << turnos;
			enti::cout << enti::cend;
			do {
				Tecla = enti::getInputKey();
				if (Tecla != enti::InputKey::NONE)
				{
					char values[2] = { 0,0 };
					keypressed = false;
					system("cls");
					activePlayer = checkActive(Player1);
					Player1[activePlayer]->movement(Tecla);
					if (Tecla == enti::InputKey::ENTER)
					{
						setActivePlayer(Player1, activePlayer);
						turnos--;
					}
					if (Player1[activePlayer]->playerMoved())
					{
						turnos--;
					
					}
					if (Tecla == enti::InputKey::SPACEBAR)
					{
						enti::cout << enti::Color::YELLOW << "CHOOSE A WEAPON: " << enti::endl;
						enti::cout << enti::Color::YELLOW << "1 - SWORD " << enti::endl;
						enti::cout << enti::Color::YELLOW << "2 - BOW (" << enti::Color::LIGHTCYAN << Player1[activePlayer]->playerArrows() << enti::Color::YELLOW << " ARROWS)" <<  enti::endl;
						enti::cout << enti::cend;
						do {
							Weapon = enti::getInputKey();
							if (Weapon != enti::InputKey::NONE)
							{
								if (Weapon == enti::InputKey::NUM1)
								{
									target = Player1[activePlayer]->attack();
									checkTarget(Player2, target);
									target = 0;
									keypressed = true;
								}
								if (Weapon == enti::InputKey::NUM2)
								{
									Player1[activePlayer]->bowAttack(values);
									if (values[0] != 0 && values[1] != 0)
									{
										attackBow(Player2, values);
									}
									keypressed = true;
								}
								else
									keypressed = true;
							}
						} while (keypressed == false);
						
					}
					checkAlive(Player1, Player2);
					mapa.printColoredMap();
					enti::cout << enti::Color::LIGHTMAGENTA << "TURNO DEL JUGADOR 1" << enti::endl;
					enti::cout << enti::Color::YELLOW << "JUGADOR ACTIVO: " << enti::Color::LIGHTCYAN << Player1[activePlayer]->playerValue() << enti::endl;
					enti::cout << enti::Color::YELLOW << "MOVIMIENTOS RESTANTES: " << enti::Color::LIGHTCYAN << turnos;
					enti::cout << enti::cend;


				}
			} while (turnos != 0);
		}
		//CAMBIO DE TURNO//
		//////////////////////////////////////////////////////////////////////////////////////
		{
			mapa.printColoredMap();
			enti::cout << enti::endl;
			enti::cout << enti::Color::LIGHTMAGENTA << "PRESIONA ENTER PARA CEDER TU TURNO" << enti::endl;
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

		//JUGADOR 2///////////////////////////////////////////////////////////////////////////
		{
			turnos = 10;
			activePlayer = checkActive(Player2);
			mapa.printColoredMap();
			enti::cout << enti::Color::LIGHTMAGENTA << "TURNO DEL JUGADOR 2" << enti::endl;
			enti::cout << enti::Color::YELLOW << "JUGADOR ACTIVO: " << enti::Color::LIGHTCYAN << Player2[activePlayer]->playerValue() << enti::endl;
			enti::cout << enti::Color::YELLOW << "MOVIMIENTOS RESTANTES: " << enti::Color::LIGHTCYAN << turnos;
			enti::cout << enti::cend;
			do {
				Tecla = enti::getInputKey();
				if (Tecla != enti::InputKey::NONE)
				{
					system("cls");
					activePlayer = checkActive(Player2);
					Player2[activePlayer]->movement(Tecla);
					if (Tecla == enti::InputKey::ENTER)
					{
						setActivePlayer(Player2, activePlayer);
						turnos--;
					}
					if (Player2[activePlayer]->playerMoved())
					{
						turnos--;
					}
					checkAlive(Player1, Player2);
					mapa.printColoredMap();
					enti::cout << enti::Color::LIGHTMAGENTA << "TURNO DEL JUGADOR 2" << enti::endl;
					enti::cout << enti::Color::YELLOW << "JUGADOR ACTIVO: " << enti::Color::LIGHTCYAN << Player2[activePlayer]->playerValue() << enti::endl;
					enti::cout << enti::Color::YELLOW << "MOVIMIENTOS RESTANTES: " << enti::Color::LIGHTCYAN << turnos;
					enti::cout << enti::cend;

					
				}
			} while (turnos != 0);
		}
		//CAMBIO DE TURNO//
		//////////////////////////////////////////////////////////////////////////////////////
		{
			mapa.printColoredMap();
			enti::cout << enti::endl;
			enti::cout << enti::Color::LIGHTMAGENTA << "PRESIONA ENTER PARA CEDER TU TURNO" << enti::endl;
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
}