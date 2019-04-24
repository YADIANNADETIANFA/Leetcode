#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution//���Ӷȹ���,�����п�����substrŪ��
{
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();

		if (len2 == 0)
		{
			if (s3 == s1)
				return true;
			else
				return false;
		}
		if (len1 == 0)
		{
			if (s3 == s2)
				return true;
			else
				return false;
		}

		else if (len3 == 0)
		{
			if (len1 != 0 || len2 != 0)
				return false;
		}

		if (s3[0] != s1[0] && s3[0] != s2[0])
			return false;

		if (s1[0] == s3[0] && s2[0] != s3[0])
			return isInterleave(s1.substr(1, len1), s2, s3.substr(1, len3));
		if (s2[0] == s3[0] && s1[0] != s3[0])
			return isInterleave(s1, s2.substr(1, len2), s3.substr(1, len3));
		
		return (isInterleave(s1.substr(1, len1), s2, s3.substr(1, len3)) || isInterleave(s1, s2.substr(1, len2), s3.substr(1, len3)));
	}
};

class Solution2//�������з�
{
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();

		if ((len1 + len2) != len3)//��֤�����߳��ȱ������Ҫ�󣬲�������򳤶���������ֵ��쳣������ܾ���
			return false;
		if (len1 == 0 && len2 == 0 && len3 == 0)
			return true;

		return helper(s1, s2, s3, len1,len2);
	}
private:
	bool helper(string s1, string s2, string s3, int len1, int len2)//�����ַ��������޸ģ�ֻ�����ַ����ķ�Χ�仯������Ӻ���ǰ�ȶ�ÿһ���ַ���ֻ�Ƿ���д���룬�븴�Ӷ��޹أ�
	{
		if (len1 <= 0 && len2 > 0)
		{
			for (int i = 0; i < len2; ++i)
			{
				if (s2[i] != s3[i])
					return false;
			}
			return true;
		}

		if (len2 <= 0 && len1 > 0)
		{
			for (int i = 0; i < len1; ++i)
			{
				if (s1[i] != s3[i])
					return false;
			}
			return true;
		}

		if (s1[len1 - 1] == s3[len1 + len2 - 1] && s2[len2 - 1] == s3[len1 + len2 - 1])
			return helper(s1, s2, s3, len1 - 1, len2) || helper(s1, s2, s3, len1, len2 - 1);

		if (s1[len1 - 1] != s3[len1 + len2 - 1] && s2[len2 - 1] == s3[len1 + len2 - 1])
			return helper(s1, s2, s3, len1, len2-1);

		if (s1[len1 - 1] == s3[len1 + len2 - 1] && s2[len2 - 1] != s3[len1 + len2 - 1])
			return helper(s1, s2, s3, len1 - 1, len2);
		return false;//���s3ָ����Χ�ڵ�ĩβ��s1��s2ָ����Χ�ڵ�ĩβ����һ�����Ǿͽ�֯����ȥ�ˣ�����false
	}
};

class Solution3//���������Ͷ�ά���鷨
{
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		int len1 = s1.size();
		int len2 = s2.size();
		int len3 = s3.size();

		if ((len1 + len2) != len3)
			return false;

		vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
		dp[0][0] = true;

		for (int i = 1; i <= len1; ++i)//����s1������s3���
			dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
		for (int i = 1; i <= len2; ++i)//����s2������s3���
			dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];

		for (int i = 1; i <= len1; ++i)
		{
			for (int j = 1; j <= len2; ++j)
			{
				dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}
		return dp[len1][len2];
	}
};

int main()
{
	string s1, s2, s3;
	while (cin >> s1 >> s2 >> s3)
	{
		Solution2 Res;
		bool res = Res.isInterleave(s1, s2, s3);
		cout << res << endl;
	}
	return 0;
}