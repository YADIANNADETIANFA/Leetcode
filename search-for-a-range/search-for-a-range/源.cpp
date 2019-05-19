/*Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return[-1, -1].
For example,
Given[5, 7, 7, 8, 8, 10] and target value 8,
return[3, 4].*/  //���Ǹ���һ���������һ��������������������ֵ���ʼλ�ã�������ȷ������������������Ұ������ķ�Χ
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution//STL�Ľⷨ 
{
public:
	vector<int> searchRange(int A[], int n, int target) 
	{
		vector<int> res(2, -1);
		if (A == nullptr || n <= 0)
			return res;
		int low = lower_bound(A, A + n, target) - A;
		if (low == n || A[low] != target)
			return res;//�Ѿ��Ѳ������ų��ˣ���upper_bound�Ͳ��ÿ��ǲ����ڽ��������
		else
			res[0] = low;
		int high = upper_bound(A, A + n, target) - A - 1;
		res[1] = high;
		return res;
	}
};

class Solution//������ַ��б� 
{
public:
	vector<int> searchRange(int A[], int n, int target) 
	{
		vector<int> res(2, -1);
		if (A == nullptr || n <= 0)
			return res;

		int low_1 = 0; int high_1 = n - 1;
		while (low_1 <= high_1)
		{
			int Mid_1 = (low_1 + high_1) >> 1;
			if (A[Mid_1] < target)//����бƣ�����߽�
				low_1 = Mid_1 + 1;
			else
				high_1 = Mid_1 - 1;
		}

		int low_2 = 0; int high_2 = n - 1;
		while (low_2 <= high_2)
		{
			int Mid_2 = (low_2 + high_2) >> 1;
			if (A[Mid_2] <= target)//���Ҽбƣ����ұ߽�
				low_2 = Mid_2 + 1;
			else
				high_2 = Mid_2 - 1;
		}

		if (low_1 <= high_2)
		{
			res[0] = low_1;
			res[1] = high_2;
		}
		return res;
	}
};