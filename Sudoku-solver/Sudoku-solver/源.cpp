/*Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules :

Each of the digits 1 - 9 must occur exactly once in each row.
Each of the digits 1 - 9 must occur exactly once in each column.
Each of the the digits 1 - 9 must occur exactly once in each of the 9 3x3 sub - boxes of the grid.

Empty cells are indicated by the character '.'.


A sudoku puzzle...


...and its solution numbers marked in red.

Note:

The given board contain only digits 1 - 9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.*/
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class Solution//跟八皇后一个思路，进行深度递归
{
public:
	void solveSudoku(vector<vector<char> > &board)             
	{
		int n = board.size();
		if (board.empty() || n == 0)
			return;
		solve(board);
	}
	bool solve(vector<vector<char>> &board)
	{
		int n = board.size();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] == '.')
				{
					for (char c = '1'; c <= '9'; ++c)//要输入char！！不是int！！！
					{
						if (isValid(board, i, j, c))
						{
							board[i][j] = c;
							if (solve(board))//这里设计的极其巧妙！！我们同样思路就是得不到结果，就差在了这里的设计
								return true;
							else
								board[i][j] = '.';
						}
					}
					return false;
				}
			}
		}
		return true;
	}
	bool isValid(vector<vector<char>> &board, int row, int col,char num)
	{
		int m = 0;//判断行是否满足
		while (m < 9)
		{
			if ( board[row][m] == num)
				return false;
			++m;
		}

		int n = 0;//判断列是否满足
		while (n < 9)
		{
			if (board[n][col] == num)
				return false;
			++n;
		}

		int tm = row / 3;      //判断该九宫格是否满足,该定位方法要记住
		int tn = col / 3;      //先取除法整，后*3，定位九宫格位置
		int mbegin = tm * 3;
		int nbegin = tn * 3;
		for (int square_j = 0; square_j < 3; ++square_j)
		{
			for (int square_i = 0; square_i < 3; ++square_i)
			{
				if (board[mbegin+square_i][nbegin+square_j] == num)
					return false;
			}
		}
		return true;
	}
};
int main()
{
	vector<vector<char>> board(9,vector<char>(9,'.'));
	board[0][0] = '5';
	board[0][1] = '3';
	board[0][4] = '7';
	board[1][0] = '6';
	board[1][3] = '1';
	board[1][4] = '9';
	board[1][5] = '5';
	board[2][1] = '9';
	board[2][2] = '8';
	board[2][7] = '6';

	board[3][0] = '8';
	board[3][4] = '6';
	board[3][8] = '3';
	board[4][0] = '4';
	board[4][3] = '8';
	board[4][5] = '3';
	board[4][8] = '1';
	board[5][0] = '7';
	board[5][4] = '2';
	board[5][8] = '6';

	board[6][1] = '6';
	board[6][6] = '2';
	board[6][7] = '8';
	board[7][3] = '4';
	board[7][4] = '1';
	board[7][5] = '9';
	board[7][8] = '5';
	board[8][4] = '8';
	board[8][7] = '7';
	board[8][8] = '9';

	Solution Res;
	Res.solveSudoku(board);
	return 0;
}
