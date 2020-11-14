#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
using namespace std;
using namespace sf;

class pac_man
{
private:
	int currentRow;
	int currentColumn;
	CircleShape pacman;
	Texture texture;
	Texture texture2;
	Texture* current;

public:
	pac_man(int initalRow, int initialColumn, string image1, string image2); // Constructor
	void move(char direction, int arr[][29]);
	void drawonWindow(RenderWindow& window);
	int getRow();
	int getColumn();
	void teleport_left();
	void teleport_right();
	void rotate(char dir);
	void restart();
	void alternate();


};

