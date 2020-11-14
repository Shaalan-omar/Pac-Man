#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

class pellets
{
private:
	

	RectangleShape pellet;
	Texture texture;


public:
	pellets();
	void drawOnWindow(RenderWindow& window);
	void setposition(int x, int y);
	void load(string image);

};
