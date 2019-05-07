/*Given a set of non - overlapping intervals, insert a new interval into the intervals(merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1, 3], [6, 9]], newInterval = [2, 5]
	Output : [[1, 5], [6, 9]]

	Example 2 :

	Input : intervals = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]], newInterval = [4, 8]
	Output : [[1, 2], [3, 10], [12, 16]]
	Explanation : Because the new interval[4, 8] overlaps with[3, 5], [6, 7], [8, 10].

	NOTE : input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	
};

class Solution1//自测毫无问题，但是牛客显示段错误，不知为何 
{
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
	{
		int Begin = newInterval.start;
		int Begin_in = 0;//Begin插入到原始的哪一个区间
		if (Begin < intervals[0].start)
			Begin_in = -1;
		else if (Begin > intervals[intervals.size() - 1].end)
			Begin_in = intervals.size();

		for (int i = 0; i < intervals.size(); ++i)
		{
			if (Begin >= intervals[i].start && Begin <= intervals[i].end)
			{
				Begin_in = i;
				break;
			}
		}


		int End = newInterval.end;
		int End_in = 0;//End插入到原始的哪一个区间
		if (End < intervals[0].start)
			End_in = -1;
		else if (End > intervals[intervals.size() - 1].end)
			End_in = intervals.size();

		for (int i = 0; i < intervals.size(); ++i)
		{
			if (End >= intervals[i].start && End <= intervals[i].end)
			{
				End_in = i;
				break;
			}
		}

		vector<Interval> res;
		Interval new_in;
		if (Begin_in == -1 && End_in == -1)
		{
			new_in.start = Begin;
			new_in.end = End;
			res.push_back(new_in);
			res.insert(res.end(), intervals.begin(), intervals.end());//end用减一么，考察一下。。。。不用减一。。。。。//在指定位置loc前插入区间[start, end)的所有元素 
		}
		else if (Begin_in == -1 && End_in != -1 && End_in != intervals.size())
		{
			new_in.start = Begin;
			new_in.end = intervals[End_in].end;
			res.push_back(new_in);
			if(End_in!=intervals.size()-1)//考虑边界值问题
				res.insert(res.end(), intervals.begin() + End_in + 1, intervals.end());
		}
		else if (Begin_in == intervals.size() && End_in == intervals.size())
		{
			new_in.start = Begin;
			new_in.end = End;
			res = intervals;
			res.push_back(new_in);
		}
		else if (Begin_in != -1 && Begin_in != intervals.size() && End_in == intervals.size())
		{
			new_in.start = intervals[Begin_in].start;
			new_in.end = End;
			if(Begin_in != 0)//考虑边界值问题
				res.insert(res.begin(), intervals.begin(), intervals.begin() + Begin_in);
			res.push_back(new_in);
		}
		else if (Begin_in != -1 && Begin_in != intervals.size() && End_in != -1 && End_in != intervals.size())
		{
			new_in.start = intervals[Begin_in].start;
			new_in.end = intervals[End_in].end;
			if (Begin_in == 0 && End_in == intervals.size() - 1)
				res.push_back(new_in);
			else if (Begin_in == 0 && End_in != intervals.size() - 1)
			{
				res.push_back(new_in);
				res.insert(res.end(), intervals.begin() + End_in + 1, intervals.end());
			}
			else if (Begin_in != 0 && End_in == intervals.size() - 1)
			{
				res.insert(res.begin(), intervals.begin(), intervals.begin() + Begin_in);
				res.push_back(new_in);
			}
			else//修改这个环节        //在指定位置loc前插入区间[start, end)的所有元素 
			{
				res.insert(res.begin(), intervals.begin(), intervals.begin() + Begin_in);
				res.push_back(new_in);
				res.insert(res.end(), intervals.begin() + End_in + 1, intervals.end());
			}
		}
		else
		{
			new_in.start = Begin;
			new_in.end = End;
			res.push_back(new_in);
		}
		return res;
	}
};

class Solution2//高手解法！！！！
{
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
	{
		vector<Interval> res;
		int i = 0;//这个i出了第一个for循环之后还要使用，所以单拿出来!!!!
		for (; i < intervals.size(); ++i)
		{
			if (newInterval.end < intervals[i].start)//处理后面不受干扰的
				break;
			else if (newInterval.start > intervals[i].end)//处理前面不受干扰的
				res.push_back(intervals[i]);
			else//处理受干扰的
			{
				newInterval.start = min(newInterval.start, intervals[i].start);
				newInterval.end = max(newInterval.end, intervals[i].end);
			}
		}

		res.push_back(newInterval);
		for (; i < intervals.size(); ++i)
			res.push_back(intervals[i]);
		return res;
	}
};

int main()
{
	Interval s1, s2, s3, s4, s5, s6;
	s1.start = 1;
	s1.end = 2;
	s2.start = 3;
	s2.end = 5;
	s3.start = 6;
	s3.end = 7;
	s4.start = 8;
	s4.end = 10;
	s5.start = 12;
	s5.end = 16;

	s6.start = 3;
	s6.end = 13;

	vector<Interval> intervals;
	intervals.push_back(s1);
	intervals.push_back(s2);
	intervals.push_back(s3);
	intervals.push_back(s4);
	intervals.push_back(s5);
	Solution1 Res;
	vector<Interval> res;
	res = Res.insert(intervals, s6);
	return 0;
}
