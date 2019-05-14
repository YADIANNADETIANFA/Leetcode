/*The n - queens puzzle is the problem of placing n queens on an n��n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n - queens puzzle.

Each solution contains a distinct board configuration of the n - queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
	Output : [
				 [".Q..",  // Solution 1
					 "...Q",
					 "Q...",
					 "..Q."],

					 ["..Q.",  // Solution 2
					 "Q...",
					 "...Q",
					 ".Q.."]
			 ]
	Explanation: There exist two distinct solutions to the 4 - queens puzzle as shown above.
	�ʺ���Ժ����ߣ������ߣ�б����*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution//�ݹ�ⷨ 
{
public:
	vector<vector<string>> solveNQueens(int n) 
	{
		vector<vector<string>> res;
		vector<string> cur(n, string(n, '.'));//ע���ʼ��д����
		int row = 0;
		dfs(res, cur, n, row);
		return res;
	}
	void dfs(vector<vector<string>> &res, vector<string> &cur, int n, int row)
	{
		if (row == n)
		{
			res.push_back(cur);
			return;
		}

		for (int j = 0; j < n; ++j)
		{
			cur[row][j] = 'Q';
			if (is_appropriate(cur, row, j, n))
			{
				dfs(res, cur, n, row + 1);
			}
			cur[row][j] = '.';
		}

	}
	bool is_appropriate(vector<string> &cur,int &row,int &column,int n)
	{
		for (int i = 0; i < row; ++i)//�ж����Ƿ�������
			if (cur[i][column] == 'Q')
				return false;
		for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--)//�ж����Ϸ��Խ���//�м�i >= 0 , j >= 0���ԣ�����Ҫ��&&
			if (cur[i][j] == 'Q')
				return false;
		for (int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++)//�ж����Ϸ��Խ���
			if (cur[i][j] == 'Q')
				return false;
		
		return true;
	}
};

int main()
{
	int n;
	while (cin >> n)
	{
		Solution Res;
		vector<vector<string>> res;
		res=Res.solveNQueens(n);
		res;
	}
	return 0;
}