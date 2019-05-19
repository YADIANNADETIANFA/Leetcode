/*Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7might become4 5 6 7 0 1 2).
You are given a target value to search.If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.*/

//和剑指offer面试11很类似
//解法一，运用剑指offer的思路，先找出最小点位置，再对正确区域二次使用二分法，目测复杂度略高,但依然可AC应该
//解法二：取中，判断左有序还是右有序，（1）
//        一旦target处于有序之中，在该有序中调用二分法查找（2）
//        若target不处于有序之中，就继续（1）的二分找有序

class Solution//解法二
{
	int search_2(int A[],int num1, int num2, int target)//（2）
	{
		int first = num1;
		int last = num2;
		int middle=num1;
		while (first <= last)
		{
			middle = (first + last) >> 1;//1,不是2，注意
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
	int search(int A[], int n, int target) //（1）
	{
		if (A == nullptr || n <= 0)
			return -1;

		int first = 0;
		int last = n - 1;
		if (A[first] <= A[last] && A[first] <= target && A[last] >= target)//起始即整体有序
			return search_2(A, first, last, target);

		int middle = first;
		while (first <= last)
		{
			middle = (first + last) >> 1;
			if (A[middle] == target)
				return middle;

			if (A[first] <= A[middle])
			{
				if (A[first] <= target && target <= A[middle])//左有序，且target在左有序当中
					return search_2(A, first, middle, target);
				else
					first = middle + 1;
			}
			else if (A[middle] <= A[last])
			{
				if (A[middle] <= target && target <= A[last])//右有序，且target在右有序当中
					return search_2(A, middle, last, target);
				else
					last = middle - 1;
			}
		}
		return -1;
	}
};