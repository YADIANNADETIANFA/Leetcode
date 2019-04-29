#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution1//�ݹ飬�Զ��׼����Ӷȹ���
{
public:
	int minCut(string s)
	{
		int len = s.size();
		string s2 = s;
		reverse(s2.begin(), s2.end());//reverse��void����
		if (s == s2)//���ֱ�Ӿ��ǻ����ַ����ˣ����õ�
			return 0;
		int res= minCut(s.substr(0, 1)) + minCut(s.substr(1, len)) + 1;//����Ļ�������λ�õ���ȡ��Сֵ
		for (int i = 2; i < len; ++i)
		{
			int temp = minCut(s.substr(0, i)) + minCut(s.substr(i, len)) + 1;
			if (res > temp)
				res = temp;  
		}
		return res;
	}
};

class Solution2//���������¶��ϣ�����  aabbc��   a,a,b,b,c,aa,ab,bb,bc,aab,abb,bbc,aabb,abbc,aabbc�������,ֵ���μ���res�������ظ�����
{
public:
	int minCut(string s)
	{
		int len = s.size();
		vector<vector<int>> res (len, vector<int>(len, 0));//res[i][j]��ʾ�ַ�i���ַ�j֮�䣨����i��j�����ַ��������赶��
		for (int i = 0; i < len; ++i)
			res[i][i] = 0;//�����ַ����õ�
		for (int last = 1; last <= len; ++last)//i~j�ַ����ĳ���
		{
			for (int start = 0; start + last < len; ++start)//i~j�ַ�������ʼλ��
			{
				string s1 = s.substr(start, last+1);
				string s2 = s1;
				reverse(s2.begin(), s2.end());
				if (s1 == s2)//���ֱ�ӻ��ģ����õ�
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
		return res[0][len-1];//ԭʼs��Ҫ�ĵ���
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