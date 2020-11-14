#pragma once
#include <vector>
using namespace std;


class Matrix
{
private:
	int matrix[276][276];
	
	
public:
	Matrix(int board[23][29]);
	vector<vector<int>> dijkstra(int board[23][29], int ghost_x, int ghost_y, int pac_x, int pac_y);
	
	
};

