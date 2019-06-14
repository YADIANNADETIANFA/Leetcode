/*A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).*/


#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

/*class Solution//天真的认为，从后往前迭代很容易，但是却惨的一塌糊涂
{
public:
	int numDecodings(string s)
	{
		int len = s.size();
		if (len == 0 || s[0]=='0')//"0"  "00"
			return 0;
		else if (len == 1)
			return 1;
		
		if (len == 2)
		{
			if (s[0] =='1' && s[1] > '0' && s[1] <='9')
				return 2;
			else if (s[0] =='2' && s[1] >= '0' && s[1] <= '6')
				return 2;
			else
				return 1;
		}

		int temp1, temp2;
		if (s[len - 2] == '1' && s[len - 1] > '0' && s[len - 1] <= '9')//是大于0，不是大于等于0！！
			temp1 = 2;
		else if (s[len - 2] == '2' && s[len - 1] > '0' && s[len - 1] <= '6')
			temp1 = 2;
		else if (s[len - 2] == '0' && s[len - 1] == '0')
			return 0;
		else
			temp1 = 1;

		if (s[len - 1] == '0')
			temp2 = 0;
		else
			temp2 = 1;
		

		int i = len - 3;
		while (i >= 0)
		{
			if (s[i] == '0' && s[i + 1] == '0')//"100"
				return 0;
			int current_num = 0;
			if (s[i] =='1' && s[i+1]!='0')//容易忘记加''，显得很low
				current_num = temp2+temp1;
			else if (s[i] == '2' && s[i + 1] > '0' && s[i + 1] <= '6')
				current_num = temp2 + temp1;
			else
				current_num = temp1;
			temp2 = temp1;
			temp1 = current_num;
			i--;
		}
		return temp1;
	}
};*/

class Solution2//从前往后的迭代算法
{
public:
	int numDecodings(string s)
	{
		int len = s.size();
		if (len == 0 || s[0] == '0')//"0"  "00"
			return 0;
		else if (len == 1)
			return 1;

		int left_left = 1;
		int left = 1;
		int now_num = 0;

		for (int i = 1; i <= len - 1; ++i)
		{//当前位的值由两部分组成，即单走和跟前面组合走，两种情况
			now_num = 0;//很重要，每次都要初始化！！！！
			if (s[i] >= '1' && s[i] <= '9')//如果当前位可以单走，那就加上单走的值
				now_num += left;
			if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6'))//如果可以和前面组合走，那就加上组合走的值
				now_num += left_left;

			left_left = left;//使得left_left存储上上次的now_num
			left = now_num;//使得left存储上次的now_num
		}
		return now_num;
	}
};


int main()
{
	string s;
	while (cin >> s)
	{
		Solution2 Res;
		int res = Res.numDecodings(s);
		cout << res << endl;
	}
	return 0;
}
