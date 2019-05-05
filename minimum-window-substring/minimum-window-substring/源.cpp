/*Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is"BANC".
Note:
If there is no such window in S that covers all characters in T, return the emtpy string"".
If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.*/
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution 
{
public:
	string minWindow(string S, string T) 
	{
		int count = 0;
		map<char, int>Tmap;//学习map映射
		int Begin = 0;
		int End = 0;

		int d = S.size();//维持一个窗口，初始化它
		string res;//结果放在这里

		if (S.size()<T.size())
		{
			return res;
		}

		for (int i = 0; i < T.size(); ++i)
			Tmap[T[i]]++;//T里面每个字母，都多少个
		for (; End < S.size(); ++End)
		{
			if (Tmap.find(S[End]) != Tmap.end())//该字符在T之中，即在Tmap之中
			{
				if (Tmap[S[End]] > 0)//看该字母的需求量是否还存在
					count++;//已达到的T的需求量加一
				Tmap[S[End]]--;//这一步始终都是要进行的！！！！
			}
			while (count == T.size())//窗口已经包含一个T了
			{
				if (Tmap.find(S[Begin]) != Tmap.end())//开始移左面的边界，并且目前最新的Begin字母是Tmap中的一种
				{
					if (d >= End - Begin + 1)//始终取最优的窗口
					{
						d = End - Begin + 1;
						res = S.substr(Begin, d);
					}
					Tmap[S[Begin]]++;//一会就要移出该Begin字母了，那该字母的需求量就会加一
					if (Tmap[S[Begin]] > 0)//如果该字母需求量变为正值了，那已达到的T的需求量，就会减少一
						count--;
				}
				++Begin;//正常每次前移一个字母
			}
		}
		return res;
	}
};

int main()
{
	string S, T;
	while (cin >> S >> T)
	{
		Solution Res;
		string res = Res.minWindow(S, T);
		cout << res << endl;
	}
	return 0;
}