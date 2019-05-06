/*The set[1, 2, 3, ��, n]contains a total of n!unique permutations.
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
�����򵥡���Ч���㷨��
��n = 3ʱ����6��������ϣ�3 * 2 * 1 ��
123   132
213   231
312   321
���ǿ���ÿ��ֻ�ҿ�ͷ�����֣�n = 3ʱ��1��ͷ��������2��ͷ��������3��ͷ����������6 / 3 = 2��
��k = 3ʱ��Ϊ213�����ڶ��е�һ�У���2��ͷ
��������ʱ��Ϳ���ʣ����������1��3��������ϣ�
��ʱn = 2��ʣ��2�����֣��� k = (k-1)%2 + 1 = 1������2��ͷ�ĵ�1�����֣�
��ô��һ������ n = 2,  k = 1
13
31
������һ������boolean flag[] = new boolean[n+1]��ʶ�ĸ����ֱ��ù�����*/
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
			return "";//β������""�����൱��stringɶҲû��
		total = total / n;
		int count = (k - 1) / total + 1;//���˼��У���������ȡ��
		int next_k = (k - 1) % total + 1;//k�����¶��ٲ�
		int i = 1;
		while (count > 0)
		{
			if (!num[i])//Ҫ����֮ǰ������û�б��ù�
			{
				count--;
			}
			i++;
		}
		i--;
		num[i] = true;
		return to_string(i) + getResult(num, total, n - 1, next_k);//ֱ��+��ƴ��
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