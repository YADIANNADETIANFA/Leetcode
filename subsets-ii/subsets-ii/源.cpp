/*Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]*/


#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

class Solution//结果正确，但复杂度高，内存占用大，排序还不准确
{
public:
	vector<vector<int>> subsetsWithDup(vector<int>& S)
	{
		sort(S.begin(), S.end(),less<int>());
		vector<vector<int>> Res;

		vector<int>::iterator iter1 = S.begin();
		for (;iter1 != S.end(); ++iter1)//条件可以省，但是；必须要两个都有
		{
			int len = Res.size();
			vector<vector<int>>::iterator iter2 = Res.begin();
 			for (;iter2 != Res.begin()+len; ++iter2)
			{
				vector<int> temp=*iter2;
				temp.push_back(*iter1);
				bool GetIn = true;
				for (vector<vector<int>>::iterator iter2 = Res.begin(); iter2 != Res.end(); ++iter2)//iter2 != Res.begin()+len;不对，否则1 2 2会不断被加进Res里面的，死循环
				{
					if (*iter2 == temp)
					{
						GetIn = false;
						break;
					}
				}
				if (GetIn)
				{
					Res.push_back(temp);//迭代器失效，要重新定义
					//vector<vector<int>>::iterator iter2 = Res.begin();//重定义，不对！
					iter2 = Res.begin();
				}
			}
			bool GetIn = true;
			vector<int> temp(1, *iter1);
			vector<vector<int>>::iterator iter3 = Res.begin();
			for (; iter3 != Res.begin() + len; ++iter3)
			{
				if (*iter3 == temp)
				{
					GetIn = false;
					break;
				}
			}
			if (GetIn)
			{
				Res.push_back(temp);
			}
		}
		vector<int> res1;//空数组
        Res.insert(Res.begin(),res1);
		return Res;
	}
};

class Solution2//回溯/深度优先遍历
{
public:
	vector<vector<int>> subsetsWithDup(vector<int> &S)
	{
		sort(S.begin(), S.end());
		dfs(S, 0);
		return result;
	}
	void dfs(vector<int> set, int start)
	{
		result.push_back(temp);
		for (int i = start; i < set.size(); ++i)
		{
			temp.push_back(set[i]);
			dfs(set, i + 1);//i+1表示，从S后面剩余的那些数开始操作
			while (i < set.size() - 1 && set[i] == set[i + 1])//在S的范围内，并且S中两数相等，则只用第一个就够了，后续的掠过
				++i;//看好了，for中的i可以进行操作！！！！！！！
			temp.pop_back();//[1 2 3]  的输出为：[] [1] [1,2] [1,2,3] [1,3] [2] [2,3] [3]
		}
	}
private:
	vector<vector<int>> result;
	vector<int> temp;//啥也不处理，本身就是[]
};

int main()
{
	while (true)
	{
		vector<int> num;
		int n;
		char c;
		while ((cin>>n).get(c))
		{
			num.push_back(n);
			if (c == '\n')
				break;
		}
		Solution RES;
		vector<vector<int>> shuzu;
		shuzu=RES.subsetsWithDup(num);
	}
	return 0;
}
