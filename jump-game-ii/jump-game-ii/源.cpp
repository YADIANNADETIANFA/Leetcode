/*Given an array of non - negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
For example :
Given array A = [2, 3, 1, 1, 4]
The minimum number of jumps to reach the last index is2. (Jump1step from index 0 to 1, then3steps to the last index.)*/
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

class Solution //和jump-game完全一样的思路
{
public:
	int jump(int A[], int n) 
	{
		if (n == 0 || n == 1)
			return 0;
		vector<int> res(n, n);//初始值设为n，代表不可能到达数组底部
		res.back() = 0;
		for (int i = n - 2; i >= 0; --i)
		{
			int temp = A[i];
			if (i + temp >= n - 1)
			{
				res[i] = 1;
				continue;
			}
			while (temp > 0)
			{
				if (res[i + temp] != n)
				{
					res[i] = min(res[i], res[i + temp] + 1);
				}
				--temp;
			}
		}
		return res[0];
	}
};

int main()
{
	int A[] = { 2,3,1,1,4 };
	Solution Res;
	int res = Res.jump(A, sizeof(A)/sizeof(int));//求数组大小方法
	return 0;
}