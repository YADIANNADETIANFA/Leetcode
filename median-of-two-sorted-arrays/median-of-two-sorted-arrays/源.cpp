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


class Solution2//Ϊ����Ӧţ��[] [2,3]��� 2.500000����ʽ   //����ϸ��Hard
{
	double find_k(int A[], int B[], int A_Start, int B_Start, int m, int n, int val)
	{
		if (A_Start == m)//A�޵��ȡ��
			return B[B_Start + val - 1];
		if (B_Start == n)//B�޵��ȡ��
			return A[A_Start + val - 1];
		if (val == 1)//A��B���е��ȡ�������һС��ֵ
			return min(A[A_Start], B[B_Start]);

		int temp = val / 2;//����˼·��һ�γ���һ��ĵ㣬������temp����
		int A_index = min(m - 1, A_Start + temp - 1);//Ҫ���ǵ��Ƕ�λ����п��ܻᳬ��A��B���ܳ��������������������Ǵ˴γ�ȥ�ĵ�����ֻ���Ǵ�A_Start��m-1,����B_Start��n-1���Ʊ�Ҫ����temp����
		int B_index = min(n - 1, B_Start + temp - 1);
		if ((A[A_index] < B[B_index]) || (A[A_index] == B[B_index] && m - 1 < A_Start + temp - 1))//��A�г�����     ||�����ʾ����������������A[A_Start + temp - 1] == B[B_Start + temp - 1]Ӧ��ֱ�ӷ���Ҫ��ֵ��Ȼ�����
		{                                                                                                           //����ΪA��λ�㳬���ܳ������ò���λ��m-1λ�õĻ�����ʱ�����ĵ�������������ΪA��λ�㳬���ܳ������ò���λ��m-1λ�ã������������ٵĵ�������Ȼû����������룬������һ��˵���˳����ĵ�����������һ��ʵ������������ݹ鴦��
			if(A_Start+temp-1>m-1)//��λ�����A������
				return find_k(A, B, A_index + 1, B_Start, m, n, val - m - A_Start);
			else//��λ�����A�����ˣ�����m-1�ı߽�λ�ã�Ҳ��A�����棩
				return find_k(A, B, A_index + 1, B_Start, m, n, val - temp);
		}
		if ((B[B_index] < A[A_index]) || (A[A_index] == B[B_index] && n - 1 < B_Start + temp - 1))//��B�г�����
		{
			if(B_Start+temp-1>n-1)//����B������
				return find_k(A, B, A_Start, B_index + 1, m, n, val - n - B_Start);
			else
				return find_k(A, B, A_Start, B_index + 1, m, n, val - temp);
		}
		//���µ�����������ǣ�A[A_index]=B[B_index]���Ҷ�λ�㴦��A��B�ڲ���������������Կ���Ƭ
		if (val % 2 == 0)
			return A[A_Start + temp - 1];
		else if (val % 2 == 1)
			return min(A[A_Start + temp], B[B_Start + temp]);

		return 0;//û����ţ�������ױ�����Ȼûʲô���壬���Ǽ��ϰ�
	}
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n)//������Ƶ��ǣ�Ĭ��A,BΪ������õ�kС��ֵ
	{                                                            //�ݹ�˼·
		//�Ķ�����
		if ((m + n) % 2 == 1)//����Ϊ����������һ��ֵ�Ϳ���
		{
			int k = (m + n)/2+1;
			int A_Start = 0;
			int B_Start = 0;
			int val = k;
			if (val > m + n)//k���������࣬�����쳣
				return -1;
			else
				return find_k(A, B, A_Start, B_Start, m, n, val);//A,BΪԭ���飬A_Start,B_StartΪ�ô�������A�к�B�еĵ�һ����ȡ�㣬val�����valС��ֵ����kһ������˼��
		}
		else//����Ϊż���������м�����ֵ��ƽ����
		{
			int k1 = (m + n) / 2;
			int k2 = (m + n) / 2 + 1;
			if (k2 > m + n)////k���������࣬�����쳣
				return -1;
			int A_Start = 0;
			int B_Start = 0;
			double res1 = find_k(A, B, A_Start, B_Start, m, n, k1);
			double res2 = find_k(A, B, A_Start, B_Start, m, n, k2);
			return (res1+ res2)/2;//�����ǳ���2��������2.0��  �����ԣ����д2.0
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
