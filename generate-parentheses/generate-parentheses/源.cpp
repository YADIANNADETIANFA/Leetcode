/*Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
For example, given n = 3, a solution set is :
"((()))", "(()())", "(())()", "()(())", "()()()"*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution//简单的递归，记住原则，注意引用
{
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> res;
		int left_remain = n;
		int right_remain = n;//原则就是，余右数要永远大于余左数
		string temp;
		Get_in(res, left_remain, right_remain, temp);
		return res;
	}
	void Get_in(vector<string>& res, int left_remain, int right_remain, string temp)//引用是必须的，不然res永远都是空的
	{
		if (right_remain < left_remain)
			return;
		if (right_remain == 0 && left_remain == 0)
		{
			res.push_back(temp);
			return;
		}
		if (left_remain > 0)
		{
			temp.push_back('(');
			Get_in(res, left_remain - 1, right_remain, temp);
			temp.pop_back();
		}
		if (right_remain > 0)
		{
			temp.push_back(')');
			Get_in(res, left_remain, right_remain - 1, temp);
			temp.pop_back();
		}
		return;
	}
};

int main()
{
	int n;
	while (cin >> n)
	{
		Solution Res;
		vector<string> res = Res.generateParenthesis(n);
	}
	return 0;
}
