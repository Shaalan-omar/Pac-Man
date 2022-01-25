# Pac-Man
## The classic retro game, pac-man remastered by a group of 3 as a project for our c++ course.
### contributers: Ali Khattab - Salma 
- The game constructs a board using a text file provided and is stored in a 2D array 23 rows and 29 columns to represent the board of the game
- The game uses sfml for the graphics, it is a simple library that helps in understanding the basics of GUI and game design
- DijKstra's algorithim is implemented using a matrix that is generated containing all the possible points 
- The DijKstra's algorithim is implmented for the ghosts to chase the PACMAN
- Walls are represented as a -11 in the text file, and the rest of the numbers start from the 000 to 275
- The flow of the game is that you have the score and the number of lives on the creen at the bottom, you move using the 4 arrrows.
- Virtualization is used in the project for future and current need of inheritance in a pure virtualization form since the class of Moving_Character has no objects created from it
