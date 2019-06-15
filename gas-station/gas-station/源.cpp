#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int Sum = 0;
		int Cost = 0;
		int gas_size = gas.size();
		int cost_size = cost.size();

		for (int i = 0; i < gas_size; ++i)
			Sum += gas[i];
		for (int i = 0; i < cost_size; ++i)
			Cost += cost[i];
		if (Sum < Cost)//总的不够，直接-1
			return -1;

		int start = gas_size - 1;
		int end = 0;
		Sum = gas[start];
		Cost = cost[start];

		while (start > end)//从start出发， 如果油量足够， 可以一直向后走 end++；  油量不够的时候，
		{                  //start向后退  最终 start == end的时候，如果有解一定是当前 start所在位置
			if (Sum >= Cost)//不浪费当前已经循环过的站的数据，很精妙！！！
			{
				Sum += gas[end];
				Cost += cost[end];
				++end;
			}
			else
			{
				--start;
				Sum += gas[start];
				Cost += cost[start];
			}
		}
		return Sum >= 0 ? start : -1;//没发现Sum哪里有减的操作，直接返回start应该没问题
	}
};

int main()
{
	vector<int> gas;
	gas.push_back(1);
	gas.push_back(2);
	gas.push_back(3);
	gas.push_back(4);
	gas.push_back(5);
	vector<int> cost;
	cost.push_back(3);
	cost.push_back(4);
	cost.push_back(5);
	cost.push_back(1);
	cost.push_back(2);
	Solution Res;
	int res = Res.canCompleteCircuit(gas, cost);
	cout << res << endl;
	return 0;
}
