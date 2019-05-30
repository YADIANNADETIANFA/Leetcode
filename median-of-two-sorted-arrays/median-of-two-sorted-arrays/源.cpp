/*There are two sorted arrays A and B of size m and n respectively.Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).*/
/*Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is(2 + 3) / 2 = 2.5  */
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;


class Solution2//为了适应牛客[] [2,3]输出 2.500000的形式   //此题细节Hard
{
	double find_k(int A[], int B[], int A_Start, int B_Start, int m, int n, int val)
	{
		if (A_Start == m)//A无点可取了
			return B[B_Start + val - 1];
		if (B_Start == n)//B无点可取了
			return A[A_Start + val - 1];
		if (val == 1)//A，B均有点可取，且求第一小的值
			return min(A[A_Start], B[B_Start]);

		int temp = val / 2;//正常思路是一次除掉一半的点，即除掉temp个点
		int A_index = min(m - 1, A_Start + temp - 1);//要考虑的是定位点很有可能会超过A或B的总长。如果发生这种情况，那此次除去的点数，只能是从A_Start到m-1,或者B_Start到n-1，势必要少于temp个点
		int B_index = min(n - 1, B_Start + temp - 1);
		if ((A[A_index] < B[B_index]) || (A[A_index] == B[B_index] && m - 1 < A_Start + temp - 1))//从A中除掉点     ||后面表示，在正常情况下如果A[A_Start + temp - 1] == B[B_Start + temp - 1]应该直接返回要求值，然而如果
		{                                                                                                           //是因为A定位点超了总长而不得不定位到m-1位置的话，此时除掉的点数并不够（因为A定位点超了总长而不得不定位到m-1位置，这个距离就是少的点数，虽然没有用这个距离，但是其一定说明了除掉的点数并不够这一事实）。仍需继续递归处理
			if(A_Start+temp-1>m-1)//定位点插在A外面了
				return find_k(A, B, A_index + 1, B_Start, m, n, val - m - A_Start);
			else//定位点插在A里面了（包括m-1的边界位置，也算A的里面）
				return find_k(A, B, A_index + 1, B_Start, m, n, val - temp);
		}
		if ((B[B_index] < A[A_index]) || (A[A_index] == B[B_index] && n - 1 < B_Start + temp - 1))//从B中除掉点
		{
			if(B_Start+temp-1>n-1)//插在B外面了
				return find_k(A, B, A_Start, B_index + 1, m, n, val - n - B_Start);
			else
				return find_k(A, B, A_Start, B_index + 1, m, n, val - temp);
		}
		//余下的两个情况就是，A[A_index]=B[B_index]，且定位点处于A，B内部的情况，不懂可以看照片
		if (val % 2 == 0)
			return A[A_Start + temp - 1];
		else if (val % 2 == 1)
			return min(A[A_Start + temp], B[B_Start + temp]);

		return 0;//没有它牛客网容易报错，虽然没什么意义，还是加上吧
	}
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n)//我们设计的是，默认A,B为升序，求得第k小的值
	{                                                            //递归思路
		//改动如下
		if ((m + n) % 2 == 1)//总数为奇数，返回一个值就可以
		{
			int k = (m + n)/2+1;
			int A_Start = 0;
			int B_Start = 0;
			int val = k;
			if (val > m + n)//k比总数都多，返回异常
				return -1;
			else
				return find_k(A, B, A_Start, B_Start, m, n, val);//A,B为原数组，A_Start,B_Start为该次搜索的A中和B中的第一个可取点，val是求第val小的值（和k一样的意思）
		}
		else//总数为偶数，返回中间两个值的平均数
		{
			int k1 = (m + n) / 2;
			int k2 = (m + n) / 2 + 1;
			if (k2 > m + n)////k比总数都多，返回异常
				return -1;
			int A_Start = 0;
			int B_Start = 0;
			double res1 = find_k(A, B, A_Start, B_Start, m, n, k1);
			double res2 = find_k(A, B, A_Start, B_Start, m, n, k2);
			return (res1+ res2)/2;//别忘记除以2！！或者2.0？  都可以，最好写2.0
		}
		return 0;
	}
};

int main()
{
	int A[] = {3};
	int B[] = {1,2,4,5,6};
	Solution2 Res;
	double res = Res.findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int));
	return 0;
}
