#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

/*��n = 1ʱ��Ϊ[0, 1]
��n = 2ʱ��Ϊ[00, 01, 11, 10]
��n = 3ʱ��Ϊ[000, 001, 011, 010, 110, 111, 101, 100]
�ɴ˿��Կ����µ�������ʵ����ǰ�����л����ϲ����µ�ֵ
����ǰ�벿�ֵ���ֵ���䣬��벿�ֵ���ֵΪ�ϸ�������ÿ��Ԫ�ص�n��λ��1���������*/
class Solution
{
public:
	vector<int> grayCode(int n)
	{
		vector<int> res;
		if (n == 0)
		{
			res.push_back(0);
			return res;
		}
		res.push_back(0);
		res.push_back(1);
		for (int i = 2; i <= n; ++i)
		{
			for (int j = (1 << (i - 1))-1; j >= 0; --j)
			{
				res.push_back(res[j] + (1 << (i - 1)));
			}
		}
		return res;
	}
};

int main()
{
	int n;
	while (cin >> n)
	{
		Solution Res;
		vector<int> res = Res.grayCode(n);
		for (int i = 0; i < res.size(); ++i)
			cout << res[i] << endl;
	}
	return 0;
}