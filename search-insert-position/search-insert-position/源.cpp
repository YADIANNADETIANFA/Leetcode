/*Given a sorted array and a target value, return the index if the target is found.If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
Here are few examples.
[1, 3, 5, 6], 5 → 2
[1, 3, 5, 6], 2 → 1
[1, 3, 5, 6], 7 → 4
[1, 3, 5, 6], 0 → 0*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

/*class Solution1//二分法，惯性的错误思维！！
{
public:
	int searchInsert(int A[], int n, int target) 
	{
		//int len = sizeof(A) / sizeof(int);
		if (n == 0)
			return 0;

		bool jixu = true;
		int Start = 0;
		int End = n - 1;
		while (jixu)
		{
			int Middle = (Start + End) / 2;
			if (End - Start == 1 && target > A[Start] && target < A[End])//防中间值循环
				return End;

			if (target == A[Middle])
				return Middle;
			else if (target > A[Middle])
			{
				if (Middle == n - 1)
					return n;
				else
					Start = Middle+1;//(Start + End) / 2向上取整
			}
			else if (target < A[Middle])
			{
				if (Middle == 0)
					return 0;
				else
					End = Middle-1;//(Start + End) / 2向上取整
			}
		}
		return -1;
	}
};*/

class Solution2//正确的二分法
{
public:
	int searchInsert(int A[], int n, int target)
	{
		int Start = 0;
		int End = n - 1;
		while (Start<=End)//很重要的判断思路！！！！
		{
			int Middle = (Start + End) / 2;

			if (target == A[Middle])
				return Middle;
			else if (target > A[Middle])
			{
				Start = Middle + 1;
			}
			else if (target < A[Middle])
			{
				End = Middle - 1;//(Start + End) / 2向上取整
			}
		}
		return Start;
	}
};



int main()
{
	int A[] = { 1,3,5 };
	Solution2 Res;
	int res = Res.searchInsert(A, 3, 4);
	cout << res << endl;
	return 0;
}