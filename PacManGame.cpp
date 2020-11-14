#include "ghosts.h"
#include "pac_man.h"
#include "pellets.h"
#include <fstream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

const int r = 23, c = 29;

int main()
{
	/*int Graph[16][16] =
	{


	};*/

	RenderWindow window; //creation of window
	window.create(VideoMode(1160, 1020), "Pacman");
	window.setFramerateLimit(5); //setting speed of window
	
	Clock clock;
	Font font;
	if (!font.loadFromFile("font.ttf"))
	{
		cout << "Error in font file";
	};

	//drawing ready text on sfml
	Text text;
	text.setFont(font);
	text.setString("READY!");
	text.setFillColor(Color::Yellow);
	text.setPosition(Vector2f(500, 525));

	// drawing lives text
	Text text_lives;
	text_lives.setFont(font);
	text_lives.setString("Lives:");
	text_lives.setFillColor(Color::White);
	text_lives.setPosition(Vector2f(800, 920));
	Text number;
	number.setFont(font);
	number.setFillColor(Color::White);
	number.setPosition(Vector2f(1000, 920));

	//drawing score text
	Text score_text;
	Text score_number;
	score_text.setFont(font);
	score_number.setFont(font);
	score_text.setString("Score:");
	score_text.setFillColor(Color::White);
	score_number.setFillColor(Color::White);
	score_text.setPosition(Vector2f(100, 920));
	score_number.setPosition(Vector2f(300, 920));

	int lives = 3; //max lives of pacman
	int eaten = 0; //to count eaten pellets
	int score = -10; //to get score (starting with -10 since there is a pellet drawn at the initial position of pacman)
	//small pellets 10 points, large pellets 50 points
	Clock fright;
	int arr[r][c]; //array of board
	int pell_arr[r][c]; //array of pellets
	int pellet_count = 0;
	int count; //used in drawing pellet
	bool is_fright_on = false; 
	char dir = '/'; //direction of pacman

	ifstream inputFile;
	inputFile.open("Board.txt");
	if (inputFile.fail()) // if file fails
	{
		cout << "Error with board file" << endl;
		exit(0);
	}
	
	if (inputFile.is_open()) //input of file
	{
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
			{
				inputFile >> arr[i][j];
				if (arr[i][j] != -11 && arr[i][j] != -22 &&
					arr[i][j] != 032 && arr[i][j] != 037 &&
					arr[i][j] != 238 && arr[i][j] != 243
					&& arr[i][j] != 122 && arr[i][j] != 135
					&& arr[i][j] != 136 && arr[i][j] != 137 && arr[i][j] != 138 && arr[i][j] != 139
					&& arr[i][j] != 140 && arr[i][j] != 141)
				{
					pell_arr[i][j] = 1; //setting array of pellets
					pellet_count++;

				}
				else if (arr[i][j] == 032 || arr[i][j] == 037 || arr[i][j] == 238 || arr[i][j] == 243)
				{
					pell_arr[i][j] = 2;
					pellet_count++;
				}
				else
					pell_arr[i][j] = 0;
			};
	};
	inputFile.close();

	//intitializations
	pac_man pac(17, 14, "pacman.png", "pacman2.png");

	ghosts blinky(9, 14, "blinky.png");
	ghosts inky(11, 13, "inky.png");
	ghosts pinky(11, 14, "pinky.png");
	ghosts clyde(11, 15, "clyde.png");

	pellets* pelletsptr = new pellets[pellet_count];
	pellets power;

	//constructing board SFML
	RectangleShape board[r][c];
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			board[i][j].setPosition(40 * j, 40 * i);
			board[i][j].setSize(Vector2f(40, 40));
			if (arr[i][j] == -11)
			{
				board[i][j].setFillColor(Color::Blue);
			}
			else
			{
				board[i][j].setFillColor(Color::Black);
			}
		}

	Event e;
	while (window.isOpen())
	{

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();


			else if (e.type == Event::KeyPressed)

			{ 
				switch (e.key.code)  //input from user to change direction of pacman
				{
				case Keyboard::Up:
					pac.rotate('U');
					dir = 'U';
					break;

				case Keyboard::Down:
					pac.rotate('D');
					dir = 'D';
					break;

				case Keyboard::Right:
					pac.rotate('R');
					dir = 'R';
					break;

				case Keyboard::Left:
					pac.rotate('L');
					dir = 'L';
					break;
				};

			};

		};

		//incase of collision with ghosts
		if (!is_fright_on)
			if ((pac.getColumn() == pinky.getColumn() && pac.getRow() == pinky.getRow())
				|| (pac.getColumn() == blinky.getColumn() && pac.getRow() == blinky.getRow())
				|| (pac.getColumn() == inky.getColumn() && pac.getRow() == inky.getRow()) ||
				(pac.getColumn() == clyde.getColumn() && pac.getRow() == clyde.getRow()))
			{
				lives--;
				dir = '/';
				pac.restart();
				blinky.home(9, 14);
				inky.home(11, 13);
				pinky.home(11, 14);
				clyde.home(11, 15);

			}

		//incase fright mode is on
		if (is_fright_on)
		{
			if ((pac.getColumn() == pinky.getColumn() && pac.getRow() == pinky.getRow()))
			{
				score = score + 200;
				pinky.home(11, 14);
				
			}
			if ((pac.getColumn() == blinky.getColumn() && pac.getRow() == blinky.getRow()))
			{
				blinky.home(9, 14);
				score = score + 200;
			}
			if ((pac.getColumn() == inky.getColumn() && pac.getRow() == inky.getRow()))
			{
				inky.home(11, 13);
				score = score + 200;
			}
			if ((pac.getColumn() == clyde.getColumn() && pac.getRow() == clyde.getRow()))
			{
				clyde.home(11, 15);
				score = score + 200;
			}
		}
	

		//case of all lives are lost
		if (lives == 0)
		{
			cout << "You lost!";
			cout << endl;
			cout << "Duration of game " << clock.getElapsedTime().asSeconds() << "s";
			cout << endl;
			cout << "Your score is " << score;
			window.close();
		};

		//rotates pacman based on direction
		if ((pac.getRow() == 11) && (pac.getColumn() == 28) && (dir == 'R'))
			pac.teleport_left(); //handles if pacman is on the far left and teleports on the other side of board
		else
			if ((pac.getRow() == 11) && (pac.getColumn() == 0) && (dir == 'L'))
				pac.teleport_right(); //handles if pacman is on the far right and teleports on the other side of board
			else
				pac.move(dir, arr);

		if (dir != '/')
		{
			pac.alternate();
		
			pinky.moveOnWindow(arr);
			blinky.moveOnWindow(arr);

			if(clock.getElapsedTime().asSeconds() >5) //moves after 5 seconds
			inky.moveOnWindow(arr);

			if (clock.getElapsedTime().asSeconds() > 8) //moves after 8 seconds
			clyde.moveOnWindow(arr);
		}
		window.clear();



		if (pell_arr[pac.getRow()][pac.getColumn()] == 1) //handles if pacman eats a normal pellet
		{
			pell_arr[pac.getRow()][pac.getColumn()] = 0;
			eaten++;
			score = score + 10;
		}

		if (pell_arr[pac.getRow()][pac.getColumn()] == 2) //handle if pacman eats a power pellet
		{
			score = score + 50;
			eaten++;
			is_fright_on = true;
			fright.restart();
		}
		
		if (fright.getElapsedTime().asSeconds() < 9 && is_fright_on) //it takes 9 seconds for the ghosts to get back to their normal routine
		{
			pell_arr[pac.getRow()][pac.getColumn()] = 0;
			inky.Fright_Mode("fright.png");
			pinky.Fright_Mode("fright.png");
			blinky.Fright_Mode("fright.png");
			clyde.Fright_Mode("fright.png");

			//Reversing the dijkstra


			if (pac.getColumn() == inky.getColumn() && pac.getRow() == inky.getRow())
			{
				score = score + 200;
				inky.Fright_Mode("eyes.png");
			}
			else if (pac.getColumn() == pinky.getColumn() && pac.getRow() == pinky.getRow())
			{
				score = score + 200;
				pinky.Fright_Mode("eyes.png");
			}
			else if (pac.getColumn() == clyde.getColumn() && pac.getRow() == clyde.getRow())
			{
				score = score + 200;
				clyde.Fright_Mode("eyes.png");
			}
			else if (pac.getColumn() == blinky.getColumn() && pac.getRow() == blinky.getRow())
			{
				score = score + 200;
				blinky.Fright_Mode("eyes.png");
			}
		}
		else
		{
			is_fright_on = false;
			blinky.Fright_Mode("blinky.png");
			pinky.Fright_Mode("pinky.png");
			inky.Fright_Mode("inky.png");
			clyde.Fright_Mode("clyde.png");

		}
		// The Dijkstra's works normally


		if (eaten == pellet_count) //winning condition
		{
			cout << "You win!";
			cout << endl;
			cout << "Duration of game " << clock.getElapsedTime().asSeconds() << "s";
			cout << endl;
			cout << "Your score is " << score;
			window.close();
		}

		// Drawing:
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				window.draw(board[i][j]); //draws board

		count = 0; //drawing pellets
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
			{
				if (pell_arr[i][j] == 1)
				{
					pelletsptr[count].setposition(40 * j + 10, 40 * i + 10);
					pelletsptr[count].drawOnWindow(window);
					count++;
				};
				if (pell_arr[i][j] == 2)
				{
					power.setposition(40 * j + 10, 40 * i + 10);
					power.load("power.png");
					power.drawOnWindow(window);

				};
			};

		if (dir == '/')
			window.draw(text);
		window.draw(text_lives);
		number.setString(to_string(lives));
		window.draw(number);
		window.draw(score_text);
		score_number.setString(to_string(score));
		window.draw(score_number);
		pac.drawonWindow(window);
		pinky.drawOnWindow(window);
		inky.drawOnWindow(window);
		blinky.drawOnWindow(window);
		clyde.drawOnWindow(window);

		window.display();
	};

	return 0;

};


