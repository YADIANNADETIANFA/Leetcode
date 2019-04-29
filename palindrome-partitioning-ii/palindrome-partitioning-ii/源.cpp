#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution1//递归，显而易见复杂度过高
{
public:
	int minCut(string s)
	{
		int len = s.size();
		string s2 = s;
		reverse(s2.begin(), s2.end());//reverse是void函数
		if (s == s2)//如果直接就是回文字符串了，不用刀
			return 0;
		int res= minCut(s.substr(0, 1)) + minCut(s.substr(1, len)) + 1;//否则的话，挨个位置刀，取最小值
		for (int i = 2; i < len; ++i)
		{
			int temp = minCut(s.substr(0, i)) + minCut(s.substr(i, len)) + 1;
			if (res > temp)
				res = temp;  
		}
		return res;
	}
};

class Solution2//迭代，自下而上，举例  aabbc：   a,a,b,b,c,aa,ab,bb,bc,aab,abb,bbc,aabb,abbc,aabbc逐个考虑,值依次计入res，以免重复计算
{
public:
	int minCut(string s)
	{
		int len = s.size();
		vector<vector<int>> res (len, vector<int>(len, 0));//res[i][j]表示字符i和字符j之间（包括i、j）的字符串，所需刀数
		for (int i = 0; i < len; ++i)
			res[i][i] = 0;//单个字符不用刀
		for (int last = 1; last <= len; ++last)//i~j字符串的长度
		{
			for (int start = 0; start + last < len; ++start)//i~j字符串的起始位置
			{
				string s1 = s.substr(start, last+1);
				string s2 = s1;
				reverse(s2.begin(), s2.end());
				if (s1 == s2)//如果直接回文，不用刀
					res[start][start + last] = 0;
				else
				{
					int min_value = res[start][start] + res[start+1][start + last] + 1;
					for (int i = 1; i < last; ++i)
					{
						int temp = res[start][start + i] + res[start + i + 1][start + last] + 1;
						if (temp < min_value)
							min_value = temp;
					}
					res[start][start + last] = min_value;
				}
			}
		}
		return res[0][len-1];//原始s需要的刀数
	}
};


int main()
{
	string s;
	while (cin>>s)
	{
		Solution2 Result;
		int num = Result.minCut(s);
		cout << num << endl;
	}
	return 0;
}