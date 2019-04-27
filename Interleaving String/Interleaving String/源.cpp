/*Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false*/


#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution//复杂度过大,怀疑有可能是substr弄的
{
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();

		if (len2 == 0)
		{
			if (s3 == s1)
				return true;
			else
				return false;
		}
		if (len1 == 0)
		{
			if (s3 == s2)
				return true;
			else
				return false;
		}

		else if (len3 == 0)
		{
			if (len1 != 0 || len2 != 0)
				return false;
		}

		if (s3[0] != s1[0] && s3[0] != s2[0])
			return false;

		if (s1[0] == s3[0] && s2[0] != s3[0])
			return isInterleave(s1.substr(1, len1), s2, s3.substr(1, len3));
		if (s2[0] == s3[0] && s1[0] != s3[0])
			return isInterleave(s1, s2.substr(1, len2), s3.substr(1, len3));
		
		return (isInterleave(s1.substr(1, len1), s2, s3.substr(1, len3)) || isInterleave(s1, s2.substr(1, len2), s3.substr(1, len3)));
	}
};

class Solution2//迭代可行法
{
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();

		if ((len1 + len2) != len3)//保证了三者长度必须符合要求，不会出现因长度问题而出现的异常情况，很精妙
			return false;
		if (len1 == 0 && len2 == 0 && len3 == 0)
			return true;

		return helper(s1, s2, s3, len1,len2);
	}
private:
	bool helper(string s1, string s2, string s3, int len1, int len2)//不对字符串进行修改，只讨论字符串的范围变化，另外从后向前比对每一个字符（只是方便写代码，与复杂度无关）
	{
		if (len1 <= 0 && len2 > 0)
		{
			for (int i = 0; i < len2; ++i)
			{
				if (s2[i] != s3[i])
					return false;
			}
			return true;
		}

		if (len2 <= 0 && len1 > 0)
		{
			for (int i = 0; i < len1; ++i)
			{
				if (s1[i] != s3[i])
					return false;
			}
			return true;
		}

		if (s1[len1 - 1] == s3[len1 + len2 - 1] && s2[len2 - 1] == s3[len1 + len2 - 1])
			return helper(s1, s2, s3, len1 - 1, len2) || helper(s1, s2, s3, len1, len2 - 1);

		if (s1[len1 - 1] != s3[len1 + len2 - 1] && s2[len2 - 1] == s3[len1 + len2 - 1])
			return helper(s1, s2, s3, len1, len2-1);

		if (s1[len1 - 1] == s3[len1 + len2 - 1] && s2[len2 - 1] != s3[len1 + len2 - 1])
			return helper(s1, s2, s3, len1 - 1, len2);
		return false;//如果s3指定范围内的末尾和s1、s2指定范围内的末尾都不一样，那就交织不下去了，返回false
	}
};

class Solution3//迭代，典型二维数组法
{
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();

		if ((len1 + len2) != len3)
			return false;

		vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
		dp[0][0] = true;

		for (int i = 1; i <= len1; ++i)//单独s1能适配s3多久
			dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
		for (int i = 1; i <= len2; ++i)//单独s2能适配s3多久
			dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];

		for (int i = 1; i <= len1; ++i)
		{
			for (int j = 1; j <= len2; ++j)
			{
				dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}
		return dp[len1][len2];
	}
};

int main()
{
	string s1, s2, s3;
	while (cin >> s1 >> s2 >> s3)
	{
		Solution2 Res;
		bool res = Res.isInterleave(s1, s2, s3);
		cout << res << endl;
	}
	return 0;
}
