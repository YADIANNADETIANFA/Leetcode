/*Given a m x n grid filled with non - negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

	Example :

	Input :
	[
		[1, 3, 1],
		[1, 5, 1],
		[4, 2, 1]
	]
Output : 7
	Explanation : Because the path 1→3→1→1→1 minimizes the sum.*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int minPathSum(vector<vector<int>> &grid)
	{
		if (grid.size() == 0 || grid[0].size() == 0)
			return 0;

		int row = grid.size();
		int column = grid[0].size();

		vector<vector<int>> dp(row+1, vector<int>(column+1, 0));
		dp[row][column] = grid[row - 1][column - 1];//最右下点

		for (int i = row-1; i >= 1; --i)
		{
			dp[i][column] = grid[i - 1][column-1] + dp[i+1][column];//最右列初始化
		}
		for (int i = column - 1; i >= 1; --i)
		{
			dp[row][i] = grid[row - 1][i - 1] + dp[row][i+1];//最下行初始化
		}

		for (int i = row - 1; i >= 1; --i)//从右下到左上
		{
			for (int j = column - 1; j >= 1; --j)
			{
				dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) + grid[i - 1][j - 1];
			}
		}
		return dp[1][1];
	}
};
