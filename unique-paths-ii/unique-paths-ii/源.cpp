#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
	int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
	{
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (m == 0 || n == 0 || obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0]==1)
			return 0;
		//单行出现的情况单独列出，注意单行列也可能有障碍

		vector<vector<long long>> res(m, vector<long long>(n, 0));//res命名为dp

		int obs_bottom_down = n-2;//最后一行,最后出现障碍物的位置！！不是考虑首次，要考虑最后一次出现障碍物的位置
		while (obs_bottom_down >= 0 && obstacleGrid[m-1][obs_bottom_down]!=1)
		{
			--obs_bottom_down;
		}
		if (obs_bottom_down == -1)
		{
			for (int i = 0; i < n; ++i)
				res[m - 1][i] = 1;
		}
		else
		{
			for (int i = 0; i <= obs_bottom_down; ++i)
				res[m - 1][i] = 0;
			for (int i = obs_bottom_down + 1; i < n; ++i)
				res[m - 1][i] = 1;
		}

		int obs_bottom_right = m-2;//最后一列,最后出现障碍物的位置！！不是考虑首次，要考虑最后一次出现障碍物的位置
		while (obs_bottom_right >= 0 && obstacleGrid[obs_bottom_right][n-1] != 1)
		{
			--obs_bottom_right;
		}
		if (obs_bottom_right == -1)
		{
			for (int i = 0; i < m; ++i)
				res[i][n-1] = 1;
		}
		else
		{
			for (int i = 0; i <= obs_bottom_right; ++i)
				res[i][n-1] = 0;
			for (int i = obs_bottom_right + 1; i < m; ++i)
				res[i][n-1] = 1;
		}

		for (int i = m-2; i >= 0; --i)
		{
			for (int j = n-2; j >= 0; --j)
			{
				if (obstacleGrid[i][j] == 1)
					res[i][j] = 0;
				else
					res[i][j] = res[i + 1][j] + res[i][j + 1];
			}
		}
		return res[0][0];
	}
};

int main()
{
	vector<vector<int>> obstacleGrid(3, vector<int>(3, 0));
	obstacleGrid[0][0] = 0;
	obstacleGrid[0][1] = 0;
	obstacleGrid[0][2] = 0;
	obstacleGrid[1][0] = 0;
	obstacleGrid[1][1] = 1;
	obstacleGrid[1][2] = 0;
	obstacleGrid[2][0] = 0;
	obstacleGrid[2][1] = 0;
	obstacleGrid[2][2] = 0;
	Solution Res;
	int res = Res.uniquePathsWithObstacles(obstacleGrid);
	cout << res << endl;
	return 0;
}