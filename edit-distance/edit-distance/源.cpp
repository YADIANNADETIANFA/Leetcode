/*Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')*/


#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution
{
public:
	int minDistance(string word1, string word2)
	{//string好像没有什么指针类的操作，string比较特殊，别用nullptr比较好
		if (word1 == word2)
			return 0;
		else if (word1 == "")
			return word2.size();
		else if (word2 == "")
			return word1.size();

		int len1 = word1.size();
		int len2 = word2.size();
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

		dp[0][0] = 0;
		for (int i = 1; i <= len1; ++i)
			dp[i][0] = i;
		for (int i = 1; i <= len2; ++i)
			dp[0][i] = i;

		for (int i = 1; i <= len1; ++i)
		{
			for (int j = 1; j <= len2; ++j)
			{
				if (word1[i-1] == word2[j-1])//记得减一
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) ,dp[i-1][j-1])+ 1;//三个都要比较
			}
		}
		return dp[len1][len2];
	}
};
int main()
{
	string s1;
	string s2;
	while (cin >> s1 >> s2)
	{
		Solution Res;
		int res = Res.minDistance(s1, s2);
		cout << res << endl;
	}
	return 0;
}
