#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

/*class Solution//�ϲ㵽�²�ֻ��ȡ�ٽ��ڵ㣬����ÿ������ȡ������������в�ͨ��
{
public:
	int minimumTotal(vector<vector<int>> &triangle)
	{
		int len = triangle.size();
		int res = 0;
		for (int i = 0; i < len; ++i)
		{
			int select = triangle[i][0];
			int len_every = triangle[i].size();
			for (int j = 0; j < len_every; ++j)
			{
				if (select > triangle[i][j])
					select = triangle[i][j];
			}
			res += select;
		}
		return res;
	}
};*/

/*class Solution1//�ݹ��㷨�����϶���,������Ҫ��Ϊ˫�˶���,�����ǣ����Һ��鷳��pop����push_back��ɾ��size=0ʱ��
{                       //�ᱣ��һ��size=0�Ŀ�ָ��ռλ������򵥰�����������������������ɾû��Ȼ��2�������Լ���Ϊ1�����飬
public:                 //�������1������ֻ��һ��Ԫ�أ�ɾ��֮��һ�����黹�Ǵ��ڣ���sizeΪ0��nullptrռλ���ڣ���2�����鲻���Զ���Ϊ1������
	int minimumTotal(deque<deque<int>> &triangle)
	{
		int len = triangle.size();
		int i = 0;
		while (triangle[i].size() == 0)
		{
			i++;
		}
		if (i == len-1 && triangle[i].size()==1)
			return triangle[i][0];

		deque<deque<int>> left = triangle;
		for (int i = 0; i < len; ++i)
		{
			if(left[i].size()!=0)
				left[i].pop_back();
		}

		deque<deque<int>> right = triangle;
		for (int i = 0; i < len; ++i)
		{
			if(right[i].size()!=0)
				right[i].pop_front();
		}
		int res = min(minimumTotal(left), minimumTotal(right)) + triangle[0][0];
	}
};*/

//������������޸�ԭvector�ܼ򵥣�ֱ�Ӵ�����ӵ���������ˣ�
//�ݹ�Ļ������ⲻ���ж������㣬������ջ����Ŀ���
/*
        1    2    3
      1   2    3    4    �Դ˾�������һ���1λ�ô����һ��1��2����Сֵ����һ���2λ�ô����һ��2��3����Сֵ����һ���3λ�ô����һ��3��4����Сֵ��
*/
class Solution2//�����㷨�����¶��ϣ����踨���ڴ��СΪ�����һ��Ԫ�صĸ�����������n
{
public:
	int minimumTotal(vector<vector<int>> &triangle)
	{
		int len = triangle.size();
		int max_length = triangle[len - 1].size();
		vector<int> part_sum(max_length, 0);
		for (int i = 0; i < max_length; ++i)
			part_sum[i] = triangle[len - 1][i];
		for (int i = len - 2; i >= 0; --i)
		{
			for (int j = 0; j < triangle[i].size(); ++j)
			{
				part_sum[j] = min(part_sum[j], part_sum[j + 1]) + triangle[i][j];
			}
		}
		return part_sum[0];
	}
};

int main()
{
	int n;//n��
	while (cin >> n)
	{
		vector<vector<int>> triangle;
		for (int i = 0; i < n; ++i)
		{
			vector<int> num(i+1,0);//ÿ�и�һ��vector
			triangle.push_back(num);
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= i; ++j)
			{
				cin >> triangle[i - 1][j - 1];//��������triangle
			}
		}
		Solution2 RES;
		int res = RES.minimumTotal(triangle);
		cout << res << endl;
	}
	return 0;
}