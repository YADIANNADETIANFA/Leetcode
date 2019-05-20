/*Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters(just like on the telephone buttons) is given below.

Input:Digit string "23" Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
using namespace std;

class Solution //��������ʹ����map
{
	map<char, string> stos;
	//stos.insert(pair<string, string>("1", "abc"));//д��������������Ϊ������������û�д洢���������˵������

	void Insert_value(map<char, string>& stos)
	{
		stos.insert(pair<char, string>('2', "abc"));//ɵ��һ��д��stos.insert(pair<string, string>('1', 'abc'));Ȼ��һֱ����������ô������char�����ܶ�ô������
		stos.insert(pair<char, string>('3', "def"));
		stos.insert(pair<char, string>('4', "ghi"));
		stos.insert(pair<char, string>('5', "jkl"));
		stos.insert(pair<char, string>('6', "mno"));
		stos.insert(pair<char, string>('7', "pqrs"));
		stos.insert(pair<char, string>('8', "tuv"));
		stos.insert(pair<char, string>('9', "wxyz"));
		return;
	}

public:
	vector<string> letterCombinations(string digits) 
	{
		vector<string> res;
		int len = digits.size(); 
		//if (len == 0)    //����  """"  Ҫ����[""""],���Ƿ���[]�������ﲻ����
			//return res;

		Insert_value(stos);
		string temp;
		dfs(res, digits, temp, len);
		return res;
	}
	void dfs(vector<string>& res, string digits, string temp, int len)
	{
		int len_temp = temp.size();
		if (len_temp == len)
		{
			res.push_back(temp);
			return;
		}
		string current_used = stos[digits[len_temp]];//string[i]��ʾ����char������string
		for (int i = 0; i < current_used.size(); ++i)
		{
			temp.push_back(current_used[i]);
			dfs(res, digits, temp, len);
			temp.pop_back();
		}
		return;
	}
};