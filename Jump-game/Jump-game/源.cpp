/*Given an array of non - negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2, 3, 1, 1, 4]
	Output : true
	Explanation : Jump 1 step from index 0 to 1, then 3 steps to the last index.

	Example 2 :

	Input : [3, 2, 1, 0, 4]
	Output : false
	Explanation : You will always arrive at index 3 no matter what.Its maximum
	jump length is 0, which makes it impossible to reach the last index.*/
/*递归：从前向后，任意一点看是否可达终点，有一种可能就返回true，不能就继续递归下去，但是肯定堆栈溢出加超时*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution//迭代,创建数组，重后到前存状态即可
{
public:
	bool canJump(int A[], int n) 
	{
		vector<bool> res(n, false);
		res.back() = true;
		for (int i = n-2; i >= 0; --i)
		{
			int temp = A[i];
			while (temp > 0)
			{
				if (i + temp >= n - 1)
				{
					res[i] = true;
					break;
				}
				else if (res[i+temp] == true)
				{
					res[i] = true;
					break;
				}
				temp--;
			}
		}
		return res[0];
	}
};
