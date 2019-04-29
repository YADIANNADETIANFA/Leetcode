/*Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false*/


#include<string>
#include<vector>
#include<cstdio>
#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution 
{
public:
	bool wordBreak(string s, unordered_set<string> &dict)
	{
		if (dict.find(s) != dict.end())
			return true;
		int len = s.size();
		for (int i = 1; i < len; ++i)
		{
			if (dict.find(s.substr(i)) == dict.end())
				continue;
			else
				string word = s.substr(i);
			bool Is_segmented = false;
			Is_segmented = wordBreak(s.substr(0, i), dict);
			if (Is_segmented)
			{
				return true;
			}
			else
			{
				continue;
			}
		}
		return false;
	}
};
