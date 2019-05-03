/*Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return
[
	    [1],
	   [1, 1],
	  [1, 2, 1],
	 [1, 3, 3, 1],
	[1, 4, 6, 4, 1]
]*/
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int>> res;
		for (int i = 1; i <= numRows; ++i)
		{
			vector<int> num(i,0);
			num[0] = 1;
			num[i - 1] = 1;
			if (i >= 3)
			{
				for (int j = 1; j <= i - 2; ++j)
					num[j] = res[i - 2][j - 1] + res[i - 2][j];
			}
			res.push_back(num);
		}
		return res;
	}
};

int main()
{
	int n;
	while (cin >> n)
	{
		Solution Res;
		vector<vector<int>> res = Res.generate(n);
	}
	return 0;
}