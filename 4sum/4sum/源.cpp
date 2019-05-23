/*Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target ? Find all unique quadruplets in the array which gives the sum of target.
Note :
	Elements in a quadruplet(a, b, c, d) must be in non - descending order. (ie, a ≤ b ≤ c ≤ d)
	The solution set must not contain duplicate quadruplets.

	For example, given array S = { 1 0 - 1 0 - 2 2 }, and target = 0.

	A solution set is :
(-1, 0, 0, 1)
(-2, -1, 1, 2)
(-2, 0, 0, 2)*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution1//dfs结果正确，但是超时 
{
	set<vector<int>>res_set;//去重加排序
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) 
	{
		sort(num.begin(), num.end());//别忘了
		vector<vector<int>>res_vec;
		vector<int> temp;
		int last = 4;
		int cur_pos = 0;
		int cur_sum = 0;
		dfs(num, target, temp, cur_pos, cur_sum, last);
		//for (int i = 1; i <= res_set.size(); ++i)
		//	res_vec.push_back(res_set[i]);//map支持下标，但是set不支持下标！！！
		set<vector<int>>::iterator iter;
		for (iter = res_set.begin(); iter != res_set.end(); ++iter)
			res_vec.push_back(*iter);
		return res_vec;
	}
	void dfs(vector<int>& num, int target, vector<int>& temp, int cur_pos, int cur_sum, int last)
	{
		if (last == 0 && cur_sum == target)
		{
			res_set.insert(temp);
			return;
		}

		for(;cur_pos<num.size();++cur_pos)
		{
			temp.push_back(num[cur_pos]);
			dfs(num, target, temp, cur_pos + 1, cur_sum + num[cur_pos], last - 1);
			temp.pop_back();//别忘记
		}
		return;
	}
};

class Solution2//固定解的内部的元素个数，就可这样做
{              //与3sum思路类似，只不过这次需要先固定两个数，然后双指针找，用set去除重复组合
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) 
	{
		vector<vector<int>> res_vec;
		set<vector<int>> res_set;
		vector<int> temp(4, 0);//肯定4个元素
		sort(num.begin(), num.end());
		int n = num.size();
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				int left = j + 1;
				int right = n - 1;
				while (left < right)
				{
					int sum = num[i] + num[j] + num[left] + num[right];
					if (sum == target)
					{
						temp[0] = num[i];
						temp[1] = num[j];
						temp[2] = num[left];
						temp[3] = num[right];
						res_set.insert(temp);
					}
					if (sum < target)
						left++;
					else
						right--;
				}
			}
		}
		set<vector<int>>::iterator iter;
		for (iter = res_set.begin(); iter != res_set.end(); ++iter)
			res_vec.push_back(*iter);
		return res_vec;
	}
};

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(0);
	num.push_back(-1);
	num.push_back(0);
	num.push_back(-2);
	num.push_back(2);

	Solution1 Res;
	vector<vector<int>> res = Res.fourSum(num, 0);
	return 0;
}

