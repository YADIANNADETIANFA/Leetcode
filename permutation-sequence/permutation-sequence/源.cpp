/*The set[1, 2, 3, …, n]contains a total of n!unique permutations.
By listing and labeling all of the permutations in order,
We get the following sequence(ie, for n = 3) :
	"123"
	"132"
	"213"
	"231"
	"312"
	"321"

	Given n and k, return the k th permutation sequence.
	Note: Given n will be between 1 and 9 inclusive.*/
/*
来个简单、高效的算法。
当n = 3时，有6种排列组合（3 * 2 * 1 ）
123   132
213   231
312   321
我们可以每次只找开头的数字，n = 3时，1开头有两个，2开头有两个，3开头有两个，即6 / 3 = 2；
当k = 3时，为213，即第二行第一列，即2开头
接下来这时候就考虑剩下两个数字1、3的排列组合，
这时n = 2（剩下2个数字）， k = (k-1)%2 + 1 = 1，即是2开头的第1个数字，
那么下一步就是 n = 2,  k = 1
13
31
可以用一个数字boolean flag[] = new boolean[n+1]标识哪个数字被用过就行*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution 
{
public:
	string getPermutation(int n, int k) 
	{
		vector<bool> num(n + 1, false);
		int total = 1;
		for (int i = 1; i <= n; ++i)
			total *= i;
		return getResult(num, total, n, k);
	}
	string getResult(vector<bool> num, int total, int n, int k)
	{
		if (n == 0)
			return "";//尾部加上""，就相当于string啥也没加
		total = total / n;
		int count = (k - 1) / total + 1;//走了几行，或者向下取整
		int next_k = (k - 1) % total + 1;//k还余下多少步
		int i = 1;
		while (count > 0)
		{
			if (!num[i])//要考虑之前的数有没有被用过
			{
				count--;
			}
			i++;
		}
		i--;
		num[i] = true;
		return to_string(i) + getResult(num, total, n - 1, next_k);//直接+来拼接
	}
};

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		Solution Res;
		string res = Res.getPermutation(n, k);
		cout << res << endl;
	}
	return 0;
}