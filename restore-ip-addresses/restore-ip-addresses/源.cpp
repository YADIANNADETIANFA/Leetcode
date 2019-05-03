/*Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
	Output : ["255.255.11.135", "255.255.111.35"]*/

#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Solution //分而治之，深度优化
{
public:
	vector<string> restoreIpAddresses(string s) 
	{
		vector<string> result;
		string t;
		dfs(result, t, s, 0);
		return result;
	}

	void dfs(vector<string> &result, string t, string s, int count)
	{
		if (count == 3)
		{
			if (s.size() != 0 && isValid(s))
			{
				result.push_back(t + s);//t+s很好
				return;
			}
			else
				return;

		}
		for (int i = 1; i <= 3 && i<s.size(); ++i)//要加上i<s.size()
		{
			string sub = s.substr(0, i);
			if (isValid(sub))
			{
				dfs(result, t + sub + '.', s.substr(i), count + 1);// t + sub + '.'很好
			}
		}
	}

	bool isValid(string s)
	{
		istringstream ss(s);//将string转换为int
		int n = 0;
		ss >> n;
		if (s.size() > 1)
			return (s[0] != '0' && n > 0 && n <= 255);
		return (n >= 0 && n <= 255);
	}
};

int main()
{
	string s;
	while (cin >> s)
	{
		Solution Res;
		vector<string> res = Res.restoreIpAddresses(s);
	}
	return 0;
}
