/*There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?

Example 1:

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.*/


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
		vector<int> candy(size,1);//每人初始一颗糖
		for (int i = 1; i < size; ++i)//从左至右扫描
		{
			if (ratings[i - 1] < ratings[i])
				candy[i] = candy[i-1] + 1;
		}
		for (int i = size - 2; i >= 0; i--)//从右至左扫描
		{
			if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1])//这里要有第二遍扫描的限制条件
				candy[i] = candy[i + 1] + 1;
		}
		int Sum = 0;
		for (int i = 0; i < size; ++i)
			Sum += candy[i];
		return Sum;
	}
};
