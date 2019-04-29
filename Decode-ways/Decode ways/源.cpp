#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

/*class Solution//�������Ϊ���Ӻ���ǰ���������ף�����ȴ�ҵ�һ����Ϳ
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
		if (s[len - 2] == '1' && s[len - 1] > '0' && s[len - 1] <= '9')//�Ǵ���0�����Ǵ��ڵ���0����
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
			if (s[i] =='1' && s[i+1]!='0')//�������Ǽ�''���Եú�low
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

class Solution2//��ǰ����ĵ����㷨
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
		{//��ǰλ��ֵ����������ɣ������ߺ͸�ǰ������ߣ��������
			now_num = 0;//����Ҫ��ÿ�ζ�Ҫ��ʼ����������
			if (s[i] >= '1' && s[i] <= '9')//�����ǰλ���Ե��ߣ��Ǿͼ��ϵ��ߵ�ֵ
				now_num += left;
			if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6'))//������Ժ�ǰ������ߣ��Ǿͼ�������ߵ�ֵ
				now_num += left_left;

			left_left = left;
			left = now_num;
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