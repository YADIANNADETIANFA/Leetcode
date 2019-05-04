/*Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
	["1", "0", "1", "0", "0"],
	["1", "0", "1", "1", "1"],
	["1", "1", "1", "1", "1"],
	["1", "0", "0", "1", "0"]
]
Output: 6

	 * 本体解法基于84. Largest Rectangle in Histogram
	 * 把每一行看成求直方图中最大矩形面积问题
*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution 
{
public:
	int maximalRectangle(vector<vector<char>>& matrix)
	{
		if (matrix.size() == 0)
			return 0;

		int m = matrix.size();
		int n = matrix[0].size();
		vector<int> h(n, 0);//存储从某一行起向上，每一列的连续1的个数
		int maxS = 0;
		stack<int> st;
		
		for (int i = 0; i < m; ++i)//求当前第i行往上连续1的个数，不连续就置为0，
		{
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == '1')
					h[j]++;
				else
					h[j] = 0;
			}
			for (int j = 0; j < n; ++j)
			{
				if (st.empty() || h[j]>=st.top())
					st.push(h[j]);
				else
				{
					int count = 0;
					while (!st.empty() && h[j] < st.top())
					{
						count++;
						maxS = max(maxS, st.top()*count);
						st.pop();
					}
					while (count--)
					{
						st.push(h[j]);
					}
					st.push(h[j]);
				}
			}
			int count = 1;
			while (!st.empty())
			{
				maxS = max(maxS, st.top()*count);
				count++;
				st.pop();
			}
		}
		return maxS;
	}
};
