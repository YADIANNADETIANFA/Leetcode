#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

class Solution//���Ӷȹ���
{
public:
	bool isPalindrome(string s)
	{
		if (s.size()==0)
			return true;
		string::iterator iter1 = s.begin();
		string::iterator iter2 = s.end()-1;
		while (iter1 < iter2)
		{
			//while (!('A' < (*iter1) < 'Z' || 'a' < (*iter1) < 'z'))
			while (!(('A'<=(*iter1) && (*iter1)<='Z') || ('a' <= (*iter1) && (*iter1) <= 'z')))
			{
				if (iter1 != iter2)
					++iter1;
				
			}

			while (!(('A' <= (*iter2) && (*iter2) <= 'Z') || ('a' <= (*iter2) && (*iter2) <= 'z')))//�����Ƚϲ���ʹ��ȷʵ����ʹ
			{
				if (iter2 != iter1)
					--iter2;
				
			}

			if (*iter1 != *iter2 && *iter1!=(*iter2-32) && *iter1!=(*iter2+32))//ע�⣬�������ǲ�������ĸ��Сд�ģ�
				return false;
			else
			{
				++iter1;
				--iter2;
			}
		}
		return true;
	}
};


class Solution2
{
public:
	bool isPalindrome(string s)
	{
		int i, j;
		for (i = 0, j = s.size() - 1; i < j; ++i, --j)//�����ܰ�д�� int i = 0   ���ǲ��Եģ������Ѿ�������int i��j�ˣ���������
		{
			while (i < j && !isalnum(s[i]))
				++i;
			while (i < j && !isalnum(s[j]))
				--j;
			if (tolower(s[i]) != tolower(s[j]))
				return false;
		}
		return true;
	}
};


/*int main()
{
	char c;
	string s;
	while ((c=cin.get())!='\n')//����s���пո�ᱻʶ��Ϊ���string�����ô���ʽ������ʹ��getline����
	{
		s = s + c;
	}
	Solution2 Res;
	bool res = Res.isPalindrome(s);
	cout << res << endl;
	return 0;
}*/


int main()
{
	string s;
	getline(cin, s);
	Solution2 Res;
	bool res = Res.isPalindrome(s);
	cout << res << endl;
	return 0;
}
