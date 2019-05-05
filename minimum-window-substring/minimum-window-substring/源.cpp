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
		map<char, int>Tmap;//ѧϰmapӳ��
		int Begin = 0;
		int End = 0;

		int d = S.size();//ά��һ�����ڣ���ʼ����
		string res;//�����������

		if (S.size()<T.size())
		{
			return res;
		}

		for (int i = 0; i < T.size(); ++i)
			Tmap[T[i]]++;//T����ÿ����ĸ�������ٸ�
		for (; End < S.size(); ++End)
		{
			if (Tmap.find(S[End]) != Tmap.end())//���ַ���T֮�У�����Tmap֮��
			{
				if (Tmap[S[End]] > 0)//������ĸ���������Ƿ񻹴���
					count++;//�Ѵﵽ��T����������һ
				Tmap[S[End]]--;//��һ��ʼ�ն���Ҫ���еģ�������
			}
			while (count == T.size())//�����Ѿ�����һ��T��
			{
				if (Tmap.find(S[Begin]) != Tmap.end())//��ʼ������ı߽磬����Ŀǰ���µ�Begin��ĸ��Tmap�е�һ��
				{
					if (d >= End - Begin + 1)//ʼ��ȡ���ŵĴ���
					{
						d = End - Begin + 1;
						res = S.substr(Begin, d);
					}
					Tmap[S[Begin]]++;//һ���Ҫ�Ƴ���Begin��ĸ�ˣ��Ǹ���ĸ���������ͻ��һ
					if (Tmap[S[Begin]] > 0)//�������ĸ��������Ϊ��ֵ�ˣ����Ѵﵽ��T�����������ͻ����һ
						count--;
				}
				++Begin;//����ÿ��ǰ��һ����ĸ
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