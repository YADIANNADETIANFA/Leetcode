#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {

		if (s1 == s2)
			return true;
		if (s1.size() != s2.size())
			return false;

		int len = s1.size();
		int c[26] = { 0 };//c[25]表示该数组大小为25！！！要从c[26]才对！！！
		for (int i = 0; i < len; ++i)
		{
			c[s1[i] - 'a']++;
			c[s2[i] - 'a']--;
		}

		for (int i = 0; i <= 25; ++i)
		{
			if (c[i] != 0)
				return false;
		}

		for (int i = 1; i < len; ++i)
		{
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
				return true;
			if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i)))
				return true;
		}
		return false;
	}
};