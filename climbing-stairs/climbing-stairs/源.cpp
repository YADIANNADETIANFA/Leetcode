/*You are climbing a stair case.It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?

Note : Given n will be a positive integer.

	Example 1 :

	Input : 2
	Output : 2
	Explanation : There are two ways to climb to the top.
	1. 1 step + 1 step
	2. 2 steps

	Example 2 :

	Input : 3
	Output : 3
	Explanation : There are three ways to climb to the top.
	1. 1 step + 1 step + 1 step
	2. 1 step + 2 steps
	3. 2 steps + 1 step*/
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

class Solution
{
public:
	int climbStairs(int n)
	{
		if (n == 0 || n==1)
			return 1;
		int res = climbStairs(n - 1) + climbStairs(n - 2);
		return res;
	}
	int climbStairs2(int n)
	{
		if (n == 0 || n == 1)
			return 1;
		int reduce2 = 1;
		int reduce1 = 1;
		for (int i = n - 1; i >= 1; --i)
		{
			int temp = reduce1 + reduce2;
			reduce2 = reduce1;
			reduce1 = temp;
		}
		return reduce1;
	}
};

int main()
{
	int n;
	while (cin >> n)
	{
		Solution Res;
		int res = Res.climbStairs2(n);
		cout << res << endl;
	}
	return 0;
}