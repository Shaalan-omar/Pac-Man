#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <math.h>


using namespace std;
using namespace sf;

class ghosts
{
private:
    RectangleShape ghost_box; 
    Texture Texture;
    int currentRow;
    int currentColumn;


public:
    ghosts(int initialRow, int initialColumn, string image);
    void Fright_Mode(string image);
    void moveOnWindow(int arr[23][29]);
    int getRow();
    int getColumn();
    void drawOnWindow(RenderWindow& window);
    void home(int i, int j);
    void move_gedeed(int arr[23][29], int number);



};