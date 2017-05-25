#include <iostream>
#include <stdlib.h>
#include "Map.h"
#include "Player.h"
#include "Renderer.hh"

void main()
{
	Map mapa;
	mapa.printColoredMap();
	enti::cout << enti::cend;
}