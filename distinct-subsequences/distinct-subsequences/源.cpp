#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution1//递归，复杂度过大
{
public:
	int numDistinct(string S, string T)
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
	}
};

class Solution2//迭代,要用二维数组去解决
{
public:
	int numDistinct(string S, string T)
	{
		int len_s = S.size();
		int len_t = T.size();
		vector<int> num(len_s, 0);
		for (int i = len_s - 1; i >= 0; --i)
		{

		}
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