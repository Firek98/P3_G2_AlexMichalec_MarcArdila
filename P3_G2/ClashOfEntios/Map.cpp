#include "Map.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Renderer.hh"

//CONSTRUCTOR DEL MAPA//

Map::Map()
{
	std::ifstream fentrada("default.cfg");

	NUM_COLUMNS = 74;
	NUM_ROWS = 36;
	md = new char*[NUM_ROWS];
	for (int i = 0; i < NUM_ROWS; i++) 
	{
		md[i] = new char[NUM_COLUMNS];
		fentrada.getline(md[i], NUM_COLUMNS);
	}
	



}



Map::~Map()
{
}

//MODIFICADOR DEL MAPA//

void Map::Modify(int row, int column, char newc)
{
	md[row][column] = newc;
}


//PARA PRINTAR  A COLOR//

void Map::printColoredMap()
{
	for (int i = 0; i < NUM_ROWS; i++) {

		for (int j = 0; j < NUM_COLUMNS; j++)
		{
			if (md[i][j] == 'X')
				enti::cout << enti::Color::LIGHTRED << md[i][j] << ' ';
			else if (md[i][j] == 'O')
				enti::cout << enti::Color::LIGHTCYAN << md[i][j] << ' ';
			else if (md[i][j] == ':')
				enti::cout << enti::Color::LIGHTGREEN << md[i][j] << ' ';
			else
				enti::cout << enti::Color::WHITE << md[i][j] << ' ';			 
		}
		enti::cout << enti::endl;
	}
}

//FUNCIONES PARA DEVOLVER VALORES PRIVADOS//

int Map::rows()
{
	return NUM_ROWS;
}

int Map::columns()
{
	return NUM_COLUMNS;
}

char Map::md2(int a, int b)
{
	return md[a][b];
}
