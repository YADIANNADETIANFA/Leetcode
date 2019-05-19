/*Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7might become4 5 6 7 0 1 2).
You are given a target value to search.If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.*/

//�ͽ�ָoffer����11������
//�ⷨһ�����ý�ָoffer��˼·�����ҳ���С��λ�ã��ٶ���ȷ�������ʹ�ö��ַ���Ŀ�⸴�Ӷ��Ը�,����Ȼ��ACӦ��
//�ⷨ����ȡ�У��ж��������������򣬣�1��
//        һ��target��������֮�У��ڸ������е��ö��ַ����ң�2��
//        ��target����������֮�У��ͼ�����1���Ķ���������

class Solution//�ⷨ��
{
	int search_2(int A[],int num1, int num2, int target)//��2��
	{
		int first = num1;
		int last = num2;
		int middle=num1;
		while (first <= last)
		{
			middle = (first + last) >> 1;//1,����2��ע��
			if (A[middle] == target)
				return middle;
			else if (A[middle] > target)
				last = middle - 1;
			else
				first = middle + 1;
		}
		return -1;
	}
public:
	int search(int A[], int n, int target) //��1��
	{
		if (A == nullptr || n <= 0)
			return -1;

		int first = 0;
		int last = n - 1;
		if (A[first] <= A[last] && A[first] <= target && A[last] >= target)//��ʼ����������
			return search_2(A, first, last, target);

		int middle = first;
		while (first <= last)
		{
			middle = (first + last) >> 1;
			if (A[middle] == target)
				return middle;

			if (A[first] <= A[middle])
			{
				if (A[first] <= target && target <= A[middle])//��������target����������
					return search_2(A, first, middle, target);
				else
					first = middle + 1;
			}
			else if (A[middle] <= A[last])
			{
				if (A[middle] <= target && target <= A[last])//��������target����������
					return search_2(A, middle, last, target);
				else
					last = middle - 1;
			}
		}
		return -1;
	}
};