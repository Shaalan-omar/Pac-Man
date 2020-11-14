#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;
using namespace sf;
class Moving_character
{
protected:
	Texture image; // Pacman and each ghost has an image.
	int initialRow; //Each moving character (Pacman and ghosts)  has an initial row that is updated with time.
	int initialColumn; //Each moving character (Pacman and ghosts)  has an initial column that is updated with time.

public:
	Moving_character(string i, int row, int column); //Construtor that initalizes the tecture name.
	//Pure virstualization, as there is no object of type Moving_Character
    virtual void setRow(int ) = 0; // A function that sets the row
	virtual void setColumn(int ) = 0; //A function that sets the columns
	virtual void moveOnWindow(char direction) = 0; //A function that makes the object move on window
	virtual void drawOnWindow(RenderWindow& window) = 0; //A function that draws on the window
};

