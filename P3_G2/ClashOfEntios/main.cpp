#include <iostream>
#include <stdlib.h>
#include "Map.h"
#include "Player.h"
#include "Renderer.hh"

void main()
{
	Map mapa;
	Player player(mapa);
	mapa.printColoredMap();
	enti::cout << enti::cend;
	
}