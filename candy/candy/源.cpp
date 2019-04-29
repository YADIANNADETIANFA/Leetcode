#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

class Solution
{
public:
	int candy(vector<int> &ratings)
	{
		int size = ratings.size();
		vector<int> candy(size,1);//ÿ�˳�ʼһ����
		for (int i = 1; i < size; ++i)//��������ɨ��
		{
			if (ratings[i - 1] < ratings[i])
				candy[i] = candy[i-1] + 1;
		}
		for (int i = size - 2; i >= 0; i--)//��������ɨ��
		{
			if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1])//����Ҫ�еڶ���ɨ�����������
				candy[i] = candy[i + 1] + 1;
		}
		int Sum = 0;
		for (int i = 0; i < size; ++i)
			Sum += candy[i];
		return Sum;
	}
};