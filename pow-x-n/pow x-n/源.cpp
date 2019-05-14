/*Implement pow(x, n), which calculates x raised to the power n(xn).

Example 1:

Input: 2.00000, 10
	Output : 1024.00000

	Example 2 :

	Input : 2.10000, 3
	Output : 9.26100

	Example 3 :

	Input : 2.00000, -2
	Output : 0.25000

	Note :

	-100.0 < x < 100.0
	n is a 32 - bit signed integer, within the range[−2^31, 2^31 − 1]*/
#include<cstdio>
#include<iostream>
using namespace std;

class Solution1//递归
{
public:
	double pow(double x, int n)
	{
		if (n < 0)
			return 1.0/pow(x, -n);
		return power(x, n);
	}
	double power(double x, int n)
	{
		if (n == 0)
			return 1;
		double tmp = power(x, n / 2);
		if (n % 2 == 0)
			return tmp * tmp;
		else
			return tmp * tmp*x;
	}
};
class Solution2//迭代，实在参不透，背下来得了
{
public:
	double pow(double x, int n)//用n=正负15，n=正负5想一下
	{
	    if (n == 0)
			return 1;
		if (x == 0)
			return 0;
		double res = 1.0;
		double tmp = x;
	    for (int i = n; i != 0; i /= 2)//将O(n)复杂度，通过对半处理，降为O(log n);  注意是i!=0  ,不是 i>=0 !!因为你n可以是负的
	    {
	        if (i % 2 != 0)
				res *= tmp;
		    tmp *= tmp;
	    }
	    //res *= tmp;
	    return n > 0 ? res : 1 / res;
	}
};