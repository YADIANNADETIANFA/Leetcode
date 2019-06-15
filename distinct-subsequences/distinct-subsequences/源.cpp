/*Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Example 1:

Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:

As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^

Example 2:

Input: S = "babgbag", T = "bag"
Output: 5
Explanation:

As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^*/


#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution1//递归，复杂度过大
{
public:
	/*int numDistinct(string S, string T)
	{
		int len_S = S.size();
		int len_T = T.size();
		if (S == T)
			return 1;
		if (len_S <= len_T)
			return 0;
		int res = 0;
		for (int i = 0; i < len_S; ++i)
		{
			if (S[i] == T[0] && len_T > 1)
				res += numDistinct(S.substr(i + 1, len_S), T.substr(1, len_T));
			else if (S[i] == T[0] && len_T == 1)
				res += 1;
		}
		return res;
	}*/
	void dfs(string S, string T, int len_s, int len_t, int start_s, int start_t, int &num)
	{
		if (len_s - start_s < len_t - start_t)
			return;
		if (start_t == len_t)
		{
			num += 1;
			return;
		}
		for (int i = start_s; i < len_s; ++i)
		{
			if (S[i] == T[start_t])
			{
				dfs(S, T, len_s, len_t, i + 1, start_t + 1, num);
			}
		}
		return;
	}
	int numDistinct(string S, string T)//无论是否substr，就算只用index也是照样复杂度过大，主要是这题的测试用例很变态
	{                                  //所以最好的解决此类问题就是，二维数组法
		int len_s = S.size();
		int len_t = T.size();
		if (len_s < len_t)
			return 0;

		int start_s = 0;
		int start_t = 0;
		int num = 0;
		dfs(S, T, len_s, len_t, start_s, start_t, num);
		return num;
	}
};

class Solution2//迭代,要用二维数组去解决
{
public:
	int numDistinct(string S, string T)
	{
		int len_s = S.size();
		int len_t = T.size();
		vector<vector<int>> num(len_t+1, vector<int>(len_s+1, 0));//此处的二维数组用法是，每个格子里存放当前的匹配成功次数
		for (int i = 0; i <= len_s; ++i)
			num[0][i] = 1;//T一个字母都没出，初始化1
		for (int j = 1; j <= len_t; ++j)
			num[j][0] = 0;//S一个字母都没出，初始化0，注意一下，斜对角线左下方都是0，num初始化后是全0的！

		for (int i = 1; i <= len_t; ++i)
		{
			for (int j = i; j <= len_s; ++j)//j从i开始就可以，因为两个s值不可能匹配出三个t值类似这样
			{
				if (S[j - 1] != T[i - 1])
					num[i][j] = num[i][j - 1];//新的值不匹配，那等于不用S的新值时匹配的结果
				else
					num[i][j] = num[i][j - 1] + num[i - 1][j - 1];//新值匹配，那等于不用S的新值时匹配的结果，和用S的新值时匹配的结果，加和
			}
		}
		return num[len_t][len_s];//只要T触底即可，即T全匹配出来了即可
	}
};
int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		Solution1 RES;
		int num=RES.numDistinct(s, t);
		cout << num << endl;
	}
	return 0;
}
