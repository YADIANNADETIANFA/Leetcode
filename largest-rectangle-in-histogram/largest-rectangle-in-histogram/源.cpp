/*Given n non - negative integers representing the histogram's 
bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

For example,
Given height =[2,1,5,6,2,3],
return10.

Ŀ�ģ���height[]����һ������ջ,��������м��������
�����ǰheight[i]����ջ��Ԫ�أ�����ջ��
��С��ջ��Ԫ�أ���ջ��Ԫ�ص���������¼�������Σ��������Ե���Ԫ����Ϊ�߶ȵ����������
���ֵret��ֱ������height[i]����ջ��Ԫ�أ��ٽ�������Ԫ����height[i]������ջ��
	����Ϊ ��
	1��2��ջ��ĿǰջΪ{2}
	2��1��2�Ƚϣ�������������2��������¼count=1��ret=2*1��
	   1����2�ٴ���ջ��Ȼ��ǰ1��ջ��ĿǰջΪ{1,1}
	3��5��ջ����������6��ջ��������ĿǰջΪ{1,1,5,6,}
	4��height[4]=2��������ջ������2С��ջ��Ԫ��6����6������count=1��ret=max��2,6��=6��
	   2С��5,5������count=2,ret=max(6,2*5)=10;
	   6��5 ������2��ջ��Ȼ��height[4]=2��ջ��
	   ĿǰջΪ{1,1,2,2,2}
	5��height[5]=3��ջ���γ�����ջ{1,1,2,2,2,3}
	6�����������ջ����ά��retֱ��ջΪ�գ�max(ret,3*1,2*2,2*3,2*4*,1*5,1*6)=10;
*/

#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
#include<iostream>
using namespace std;

class Solution
{
public:
	int largestRectangleArea(vector<int> &height) 
	{
		stack<int> stk;
		int ret = 0;
		for (int i = 0; i < height.size(); ++i)
		{
			if (stk.empty() || height[i] >= stk.top())
				stk.push(height[i]);
			else
			{
				int count = 0;
				while (!stk.empty() && stk.top() >= height[i])
				{
					count++;
					ret = max(ret, stk.top()*count);
					stk.pop();
				}
				while (count--)
				{
					stk.push(height[i]);
				}
				stk.push(height[i]);
			}
		}
		int count = 1;
		while (!stk.empty())
		{
			ret = max(ret, stk.top()*count);
			++count;
			stk.pop();
		}
		return ret;
	}
};