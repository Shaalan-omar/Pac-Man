#include "pellets.h"

pellets::pellets()
{
	texture.loadFromFile("pellets.png");
	pellet.setSize(Vector2f(20, 20));
	pellet.setTexture(&texture);

};


void pellets::drawOnWindow(RenderWindow& window)
{

	window.draw(pellet);



}
void pellets::setposition(int x, int y)
{
	pellet.setPosition(x, y);
}
;

void pellets::load(string image)
{
	texture.loadFromFile(image);

};

