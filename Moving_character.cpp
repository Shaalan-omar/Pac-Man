#include "Moving_character.h"

Moving_character::Moving_character(string i, int row, int column)
{
	image.loadFromFile(i);
	initialRow = row;
	initialColumn = column;
}
//A constructor that intializes the texture , row and column for the pacman and ghosts when they inherit from this class.
