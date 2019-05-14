/*Given a collection of numbers that might contain duplicates, return all possible unique permutations.
For example,
[1, 1, 2]have the following unique permutations :
[1, 1, 2], [1, 2, 1], and[2, 1, 1].*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution1 
{
public:
	vector<vector<int> > permuteUnique(vector<int> &num) 
	{
		sort(num.begin(), num.end());//先排序
		int len = num.size();
		vector<vector<int>> res;
		vector<int> temp;//倒手使用
		vector<bool> is_used(len, false);//存放num中哪些位置已经被用过了
		dfs(num, res, temp, is_used);//引用说的就是这里！！
		return res;
	}
	void dfs(vector<int> num, vector<vector<int>> &res, vector<int> temp, vector<bool> is_used)//必须要用引用，不然返回的是原始未改变结果，毫无卵用！
	{
		if (temp.size() == num.size())
		{
			res.push_back(temp);
			return;
		}
		for (int i = 0; i < num.size(); ++i)
		{
			if (!is_used[i])//如果没被使用过
			{
				temp.push_back(num[i]);
				is_used[i] = true;
				dfs(num, res, temp, is_used);//交给后面处理
				temp.pop_back();
				is_used[i] = false;//这两步别忘了，用完了给人家还原！
				while ((i + 1) < num.size() && num[i] == num[i + 1])//确保相同元素只使用一次！！
					++i;
			}
		}
	}
};

class Solution2//有重复数字，意味着有重复的组合，去重首先想到的方法是用set处理 //C++ STL中的set是有序的，迭代器输出的时候是按照字典顺序的，这样省去了排序操作
{
private:
	set<vector<int>> st;//精妙！！但是会慢一些，毕竟重复的步骤会被正常运算
public:
	vector<vector<int> > permuteUnique(vector<int> &num) 
	{
		vector<vector<int>> res;
		if (num.size() == 0)
			return res;
		int start = 0;
		dfs(num, start);
		set<vector<int>>::iterator iter;
		for (iter = st.begin(); iter != st.end(); ++iter)
			res.push_back(*iter);//把结果从set转换回vector
		return res;
	}
	void dfs(vector<int> num, int start)
	{
		if (start == num.size())
			st.insert(num);//set没有push_back,只有insert！！
		for (int i = start; i < num.size(); ++i)
		{
			swap(num[i], num[start]);
			dfs(num, start + 1);
			swap(num[start], num[i]);
		}
	}
};

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(1);
	num.push_back(2);
	Solution1 Res;
	vector<vector<int>> res = Res.permuteUnique(num);
	return 0;
}