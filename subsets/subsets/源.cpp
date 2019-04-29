#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int> &S)
	{
		sort(S.begin(), S.end());
		for (int i = 0; i <= S.size(); ++i)
		{
			dfs(S, 0, i);
		}
		return result;
	}
	void dfs(vector<int> S, int start, int k)
	{
		if (k < 0)
			return;
		else if (k == 0)
			result.push_back(tmp);
		else
		{
			for (int i = start; i < S.size(); ++i)
			{
				tmp.push_back(S[i]);
				dfs(S, i + 1, k - 1);//此题是另一种输出顺序，很重要都要背下来
				tmp.pop_back();//[1 2 3]的话输出： [] [1] [2] [3] [1,2] [1,3] [2,3] [1,2,3]
			}
		}
	}
private:
	vector<vector<int>> result;
	vector<int> tmp;
};

int main()
{
	vector<int> num;
	char c;
	int temp;
	while ((cin >> temp).get(c))
	{
		num.push_back(temp);
		if (c == '\n')
			break;
	}
	Solution Res;
	vector<vector<int>> res = Res.subsets(num);
	return 0;
}