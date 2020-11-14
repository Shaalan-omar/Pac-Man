#include "ghosts.h"

ghosts::ghosts(int initialRow, int initialColumn, string image)
{

    currentRow = initialRow;
    currentColumn = initialColumn;
    ghost_box.setSize(Vector2f(35, 35));
    ghost_box.setPosition(40 * initialColumn, 40 * initialRow);
    Texture.loadFromFile(image);
    ghost_box.setTexture(&Texture);

   

};


void ghosts::moveOnWindow(int arr[23][29]) 
{
    int direction = rand() % 4;
    if (direction == 0)
    {
        if (arr[currentRow - 1][currentColumn] != -11)
        {
            currentRow--;
            ghost_box.move(0, -40);
        }
    }
    else if (direction == 1)
    {
        if (arr[currentRow + 1][currentColumn] != -11)
        {
            currentRow++;
            ghost_box.move(0, 40);
        }
    }
    else if (direction == 2)
    {
        if (arr[currentRow][currentColumn + 1] != -11)
        {
            ghost_box.move(40, 0);
            currentColumn++;
        }
    }

    else if (direction == 3)
    {
        if (arr[currentRow][currentColumn - 1] != -11)
        {
            ghost_box.move(-40, 0);
            currentColumn--;
        }
    }


};


int ghosts::getRow()
{
    return currentRow;
}

int ghosts::getColumn()
{
    return currentColumn;
}


void ghosts::drawOnWindow(RenderWindow& window)
{
    window.draw(ghost_box);
}

void ghosts::Fright_Mode(string image)
{
    Texture.loadFromFile(image);
}

void ghosts::home(int i, int j)
{
    ghost_box.setPosition(40 * j, 40 * i);
    currentRow = i;
    currentColumn = j;

}








void ghosts::move_gedeed(int arr[23][29], int number)
{
    
    if (arr[currentRow + 1][currentColumn] == number)
    {
        currentRow++;
        ghost_box.move(0, 40);
    }
    if (arr[currentRow - 1][currentColumn] == number)
    {
        currentRow--;
        ghost_box.move(0, -40);
    }
       
    if (arr[currentRow][currentColumn - 1] == number)
    {
        ghost_box.move(-40, 0);
        currentColumn--;
    }
        
    if (arr[currentRow][currentColumn + 1] == number)
    {
        ghost_box.move(40, 0);
        currentColumn++;
    }
      
}
