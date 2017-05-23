#pragma once

class Map

{

private:

	int NUM_ROWS;
	int NUM_COLUMNS;
	char **md;

public:

	Map(int diff);
	~Map();
	void Modify(int column, int row, char newc);
	void printColoredMap();
	int rows();
	int columns();
	char md2(int a, int b);
};


