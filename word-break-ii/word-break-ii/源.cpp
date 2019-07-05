/*Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]

Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]*/


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
			string word = s.substr(i);//word是s从s[i]到s末尾的那那个字符串 //word是先长的，后短的！
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
