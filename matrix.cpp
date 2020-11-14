#include "matrix.h"


vector<vector<int>> Matrix::dijkstra(int board[23][29], int ghost_x, int ghost_y, int pac_x, int pac_y)
{
	int start;
	int end;
	const int COUNT = 276;
	const int INFINITE = 9999;
	start = board[ghost_y][ghost_x];
	end = board[pac_y][pac_x];
	int temp[COUNT][COUNT], costs[COUNT], previous[COUNT];
	bool visited[COUNT];
	// temp
	for (int i = 0; i < COUNT; i++)
		for (int j = 0; j < COUNT; j++)
			if (matrix[i][j] == 0)
				temp[i][j] = INFINITE;
			else
				temp[i][j] = matrix[i][j];
	// costs, previous, and visited
	for (int i = 0; i < COUNT; i++)
	{
		costs[i] = temp[start][i];
		previous[i] = start;
		visited[i] = false;
	}
	// startNode
	costs[start] = 0;
	visited[start] = true;

	int count = 1, nextNode = end, minimumCost;
	while (count < COUNT)
	{
		// Find the minimum cost in order to visit a node.
		minimumCost = INFINITE;
		for (int i = 0; i < COUNT; i++)
			if ((costs[i] < minimumCost) && (visited[i] == false))
			{
				minimumCost = costs[i];
				nextNode = i;
			}
		// Visit the node.
		visited[nextNode] = true;
		// Update the costs of the children of the visited node.
		for (int i = 0; i < COUNT; i++)
			if ((minimumCost + temp[nextNode][i] < costs[i]) && (visited[i] == false))
			{
				costs[i] = minimumCost + temp[nextNode][i];
				previous[i] = nextNode;
			}
		count++;
	}
	// Fill the paths.
	int j;
	vector<vector<int>> paths;
	paths.resize(COUNT);
	for (int i = 0; i < COUNT; i++)
	{
		paths[i].push_back(i);
		if (i != start)
		{
			j = i;
			do
			{
				j = previous[j];
				paths[i].push_back(j);
			} while (j != start);
		}
	}
	return paths;
}



Matrix::Matrix(int board[23][29])
{
	for (int matrix_row = 0; matrix_row < 276; matrix_row++) //matrix row
	{
		for (int board_row = 0; board_row < 23; board_row++) // board row
		{
			for (int board_column = 0; board_column < 29; board_column++) //board column
			{
				if (board[board_row][board_column] == matrix_row) //finds matrix row and array of board
				{
					for (int matrix_column = 0; matrix_column < 276; matrix_column++) //matrix column
					{
						if (board[board_row + 1][board_column] == matrix_column)
							matrix[matrix_row][matrix_column] = 1;
						else if (board[board_row - 1][board_column] == matrix_column)
							matrix[matrix_row][matrix_column] = 1;
						else if (board[board_row][board_column + 1] == matrix_column)
							matrix[matrix_row][matrix_column] = 1;
						else if (board[board_row][board_column + 1] == matrix_column)
							matrix[matrix_row][matrix_column] = 1;
						else if (board[board_row][board_column - 1] == matrix_column)
							matrix[matrix_row][matrix_column] = 1;
						else
							matrix[matrix_row][matrix_column] = 0;


					}


				}
			}
		}

	}
}
