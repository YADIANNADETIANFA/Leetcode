//和word Break2一个道理
#include<string>
#include<vector>
#include<cstdio>
#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution 
{
public:
	bool wordBreak(string s, unordered_set<string> &dict)
	{
		if (dict.find(s) != dict.end())
			return true;
		int len = s.size();
		for (int i = 1; i < len; ++i)
		{
			if (dict.find(s.substr(i)) == dict.end())
				continue;
			else
				string word = s.substr(i);
			bool Is_segmented = false;
			Is_segmented = wordBreak(s.substr(0, i), dict);
			if (Is_segmented)
			{
				return true;
			}
			else
			{
				continue;
			}
		}
		return false;
	}
};