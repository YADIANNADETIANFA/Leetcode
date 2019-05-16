/*Given a set of candidate numbers(C) and a target number(T), find all unique combinations in C where the candidate numbers sums to T .
The same repeated number may be chosen from C unlimited number of times.
Note:
All numbers(including target) will be positive integers.
Elements in a combination(a 1, a 2, …, a k) must be in non - descending order. (ie, a 1 ≤ a 2 ≤ … ≤ a k).
The solution set must not contain duplicate combinations.

For example, given candidate set2, 3, 6, 7 and target7,
A solution set is :
[7]
[2, 2, 3]*/
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
	vector<vector<int> > combinationSum(vector<int> &candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		vector<int> temp;
		int start = 0;
		int current_sum = 0;
		dfs(start, candidates, target, temp, current_sum);
		vector<vector<int>> res;
		set<vector<int>>::iterator iter;
		for (iter = st.begin(); iter != st.end(); ++iter)
			res.push_back(*iter);
		return res;
	}
	void dfs(int start, vector<int> &candidates, int target, vector<int> temp, int current_sum)
	{
		if (current_sum == target)
		{
			st.insert(temp);
			return;
		}
		int len = candidates.size();
		for (int i = start; i < len; ++i)
		{
			if (current_sum + candidates[i] <= target)
			{
				temp.push_back(candidates[i]);
				dfs(i + 1, candidates, target, temp, current_sum + candidates[i]);
				dfs(i, candidates, target, temp, current_sum + candidates[i]);//一个值可以重复使用,唯一的区别在这里
				temp.pop_back();

			}
		}
	}
};

int main()
{
	vector<int> candidates;
	candidates.push_back(2);
	candidates.push_back(3);
	candidates.push_back(6);
	candidates.push_back(7);

	Solution Res;
	vector<vector<int>> res = Res.combinationSum(candidates, 7);
	return 0;
}