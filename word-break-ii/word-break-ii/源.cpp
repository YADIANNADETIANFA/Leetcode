#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstdio>
#include<set>
#include<unordered_set>
using namespace std;

class Solution
{
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict)
	{
		vector<string> res;
		if (dict.find(s) != dict.end())//s已经是dict中的某一个了
			res.push_back(s);

		int len = s.size();
		for (int i = 1; i < len; ++i)
		{
			string word = s.substr(i);//word是s从s[i]到s末尾的那那个字符串
			if (dict.find(word) == dict.end())//word不是dict中的任何一个
				continue;
			vector<string> tempRes = wordBreak(s.substr(0, i), dict);
			Combine(tempRes, word);
			res.insert(res.begin(), tempRes.begin(), tempRes.end());//根据答案的表示形式，我们做相应的res输出顺序调整
		}
		return res;
	}
	void Combine(vector<string>& v, const string& str)//对v改变，返回的v，所以引用v
	{
		for (vector<string>::iterator iter = v.begin(); iter != v.end(); ++iter)
			*iter +=( " " + str);//string直接就可以用+ +=来拼接字符串
	}
};