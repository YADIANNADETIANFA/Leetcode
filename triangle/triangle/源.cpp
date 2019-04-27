/*Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

/*class Solution//上层到下层只能取临近节点，不是每层任意取，所以这个是行不通的
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

/*class Solution1//递归算法，自上而下,但是需要改为双端队列,不考虑，而且很麻烦，pop或者push_back当删至size=0时，
{                       //会保留一个size=0的空指针占位，不会简单把这行数组像想象中那样给删没，然后2号数组自己变为1号数组，
public:                 //比如如果1号数组只有一个元素，删了之后一号数组还是存在，以size为0的nullptr占位存在，即2号数组不会自动升为1号数组
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

//此题如果可以修改原vector很简单，直接从上面加到下面就行了；
//递归的话，此题不会有多余运算，但是有栈溢出的可能
/*
        1    2    3
      1   2    3    4    以此举例，上一层的1位置存放下一层1、2的最小值；上一层的2位置存放下一层2、3的最小值；上一层的3位置存放下一层3、4的最小值；
*/
class Solution2//迭代算法，自下而上，所需辅助内存大小为，最后一行元素的个数即总行数n
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
	int n;//n行
	while (cin >> n)
	{
		vector<vector<int>> triangle;
		for (int i = 0; i < n; ++i)
		{
			vector<int> num(i+1,0);//每行给一个vector
			triangle.push_back(num);
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= i; ++j)
			{
				cin >> triangle[i - 1][j - 1];//输入生成triangle
			}
		}
		Solution2 RES;
		int res = RES.minimumTotal(triangle);
		cout << res << endl;
	}
	return 0;
}
