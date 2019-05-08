/*Given an integer array nums, find the contiguous subarray(containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4],
	Output : 6
	Explanation : [4, -1, 2, 1] has the largest sum = 6.*/

	/*
	 *从头开始累加，直到和为负。此时前面这段不能给后面的串带来正收益，应舍弃，sum清零
	 *然后在开始统计最大的sum.
	 */
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution //仔细看，背一下
{
public:
	int maxSubArray(int A[], int n) 
	{
		int Max = A[0];
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			sum += A[i];
			if (Max < sum)
				Max = sum;
			if (sum < 0)
				sum = 0;
		}
		return Max;
	}
};