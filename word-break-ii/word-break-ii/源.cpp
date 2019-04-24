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
		if (dict.find(s) != dict.end())//s�Ѿ���dict�е�ĳһ����
			res.push_back(s);

		int len = s.size();
		for (int i = 1; i < len; ++i)
		{
			string word = s.substr(i);//word��s��s[i]��sĩβ�����Ǹ��ַ���
			if (dict.find(word) == dict.end())//word����dict�е��κ�һ��
				continue;
			vector<string> tempRes = wordBreak(s.substr(0, i), dict);
			Combine(tempRes, word);
			res.insert(res.begin(), tempRes.begin(), tempRes.end());//���ݴ𰸵ı�ʾ��ʽ����������Ӧ��res���˳�����
		}
		return res;
	}
	void Combine(vector<string>& v, const string& str)//��v�ı䣬���ص�v����������v
	{
		for (vector<string>::iterator iter = v.begin(); iter != v.end(); ++iter)
			*iter +=( " " + str);//stringֱ�ӾͿ�����+ +=��ƴ���ַ���
	}
};