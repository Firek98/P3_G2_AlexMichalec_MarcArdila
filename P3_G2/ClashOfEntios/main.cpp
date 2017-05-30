#include <iostream>
#include <stdlib.h>
#include "Map.h"
#include "Player.h"
#include "Renderer.hh"
#include <vector>

void checkAlive(std::vector<Player*> a, std::vector<Player*> b)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i]->isAlive() == false)
		{
			a.erase(a.begin() + i);
		}
	}
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i]->isAlive() == false)
		{
			b.erase(b.begin() + i);
		}

	}
}



void main()
{
	enti::InputKey Tecla;
	Map mapa;

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
//comprobar con iterador si se puede mover

	mapa.printColoredMap();
	do {
		Tecla = enti::getInputKey();
		if (Tecla != enti::InputKey::NONE)
		{
			checkAlive(Player1, Player2);
			system("cls");
			mapa.printColoredMap();
		}
	} while (Player1.empty() || Player2.empty());
	
}