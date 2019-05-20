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

class Solution //不熟练的使用着map
{
	map<char, string> stos;
	//stos.insert(pair<string, string>("1", "abc"));//写在这里是弱智行为，报错“此声明没有存储类或者类型说明符”

	void Insert_value(map<char, string>& stos)
	{
		stos.insert(pair<char, string>('2', "abc"));//傻子一样写成stos.insert(pair<string, string>('1', 'abc'));然后一直报错！！！特么单引号char类型能对么？！！
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
		//if (len == 0)    //用例  """"  要返回[""""],不是返回[]，故这里不能有
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
		string current_used = stos[digits[len_temp]];//string[i]表示的是char，不是string
		for (int i = 0; i < current_used.size(); ++i)
		{
			temp.push_back(current_used[i]);
			dfs(res, digits, temp, len);
			temp.pop_back();
		}
		return;
	}
};