/*Given a collection of candidate numbers(C) and a target number(T), find all unique combinations in C where the candidate numbers sums to T .
Each number in C may only be used once in the combination.
Note:
All numbers(including target) will be positive integers.
Elements in a combination(a 1, a 2, …, a k) must be in non - descending order. (ie, a 1 ≤ a 2 ≤ … ≤ a k).
The solution set must not contain duplicate combinations.

For example, given candidate set10, 1, 2, 7, 6, 1, 5 and target8,
A solution set is :
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution //无脑深度优先遍历dfs
{
	set<vector<int>> st;
public:
	vector<vector<int> > combinationSum2(vector<int> &num, int target) 
	{
		sort(num.begin(), num.end());
		vector<int> temp;
		int start = 0;
		int current_sum = 0;
		dfs(start, num, target, temp, current_sum);
		vector<vector<int>> res;
		set<vector<int>>::iterator iter;
		for (iter = st.begin(); iter != st.end(); ++iter)
			res.push_back(*iter);
		return res;
	}
	void dfs(int start, vector<int> &num, int target, vector<int> temp, int current_sum)
	{
		if (current_sum == target)
		{
			st.insert(temp);
			return;
		}
		int len = num.size();
		for (int i = start; i < len; ++i)
		{
			if (current_sum + num[i] <= target)
			{
				temp.push_back(num[i]);
				dfs(i + 1, num, target, temp, current_sum + num[i]);
				temp.pop_back();
			}
		}
	}
};

int main()
{
	vector<int> num;
	num.push_back(10);
	num.push_back(1);
	num.push_back(2);
	num.push_back(7);
	num.push_back(6);
	num.push_back(1);
	num.push_back(5);
	Solution Res;
	vector<vector<int>> res = Res.combinationSum2(num, 8);
	return 0;
}