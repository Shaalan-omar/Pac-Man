#include "pac_man.h"

pac_man::pac_man(int initialRow, int initialColumn, string image1, string image2)
{
	currentRow = initialRow;
	currentColumn = initialColumn;
	pacman.setRadius(20);
	pacman.setPosition(40 * initialColumn + 20, 40 * initialRow + 20);
	texture.loadFromFile(image1);
	texture2.loadFromFile(image2);
	current = &texture;
	pacman.setTexture(current);
	pacman.setOrigin(20, 20);

};

int pac_man::getRow()
{
	return currentRow;
}

int pac_man::getColumn()
{
	return currentColumn;
};


void pac_man::teleport_left()
{
	pacman.move(-1120, 0);
	currentColumn = 0;
}

void pac_man::teleport_right()
{
	pacman.move(1120, 0);
	currentColumn = 28;
}

void pac_man::rotate(char direction)
{
	if (direction == 'U')
		pacman.setRotation(-90);
	if (direction == 'D')
		pacman.setRotation(90);
	if (direction == 'R')
		pacman.setRotation(0);
	if (direction == 'L')
		pacman.setRotation(-180);
}

void pac_man::restart()
{
	pacman.setPosition(40 * 14 + 20, 40 * 17 + 20);
	currentColumn = 14;
	currentRow = 17;

}




void pac_man::move(char direction, int arr[][29])
{
	if (direction == 'U' || direction == 'u')
	{
		if (arr[currentRow - 1][currentColumn] != -11 && arr[currentRow - 1][currentColumn] != 122
			&& arr[currentRow - 1][currentColumn] != 135 && arr[currentRow - 1][currentColumn] != 136
			&& arr[currentRow - 1][currentColumn] != 137 && arr[currentRow - 1][currentColumn] != 138
			&& arr[currentRow - 1][currentColumn] != 139 && arr[currentRow - 1][currentColumn] != 140
			&& arr[currentRow - 1][currentColumn] != 141)
		{
			currentRow--;
			pacman.move(0, -40);
		}
	}
	else if (direction == 'D' || direction == 'd')
	{
		if (arr[currentRow + 1][currentColumn] != -11 && arr[currentRow + 1][currentColumn] != 122
			&& arr[currentRow + 1][currentColumn] != 135 && arr[currentRow + 1][currentColumn] != 136
			&& arr[currentRow + 1][currentColumn] != 137 && arr[currentRow + 1][currentColumn] != 138
			&& arr[currentRow + 1][currentColumn] != 139 && arr[currentRow + 1][currentColumn] != 140
			&& arr[currentRow + 1][currentColumn] != 141)
		{
			currentRow++;
			pacman.move(0, 40);
		}
	}
	else if (direction == 'R' || direction == 'r')
	{
		if (arr[currentRow][currentColumn + 1] != -11 && arr[currentRow][currentColumn + 1] != 122
			&& arr[currentRow][currentColumn + 1] != 135 && arr[currentRow][currentColumn + 1] != 136
			&& arr[currentRow][currentColumn + 1] != 137 && arr[currentRow][currentColumn + 1] != 138
			&& arr[currentRow][currentColumn + 1] != 139 && arr[currentRow][currentColumn + 1] != 140
			&& arr[currentRow][currentColumn + 1] != 141)
		{
			currentColumn++;
			pacman.move(40, 0);

		};
	}
	else if (direction == 'L' || direction == 'l')
	{

		if (arr[currentRow][currentColumn - 1] != -11 && arr[currentRow][currentColumn - 1] != 122
			&& arr[currentRow][currentColumn - 1] != 135 && arr[currentRow][currentColumn - 1] != 136
			&& arr[currentRow][currentColumn - 1] != 137 && arr[currentRow][currentColumn - 1] != 138
			&& arr[currentRow][currentColumn - 1] != 139 && arr[currentRow][currentColumn - 1] != 140
			&& arr[currentRow][currentColumn - 1] != 141)
		{
			currentColumn--;
			pacman.move(-40, 0);
		}
	}
};

void pac_man::drawonWindow(RenderWindow& window)
{
	window.draw(pacman);
};

void pac_man::alternate()
{
	if (current == &texture)
	{
		current = &texture2;
		pacman.setTexture(current);
	}
	else
	{
		current = &texture;
		pacman.setTexture(current);
	}

};
