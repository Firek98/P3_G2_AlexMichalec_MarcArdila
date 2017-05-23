#include "Map.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

//CONSTRUCTOR DEL MAPA//

Map::Map()
{
	std::ifstream fentrada("default.cfg");

	NUM_COLUMNS = 74;
	NUM_ROWS = 36;

	for (int i = 0; i < NUM_ROWS; i++) 
	{

		md[i] = new char[NUM_COLUMNS];
	}
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLUMNS; j++)
		{
			fentrada >> md[NUM_COLUMNS][NUM_ROWS]; //NO LO SE
		}
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
			std::cout << md[i][j];
		}
		std::cout << std::endl;
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
