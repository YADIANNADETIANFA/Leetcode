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
		if (Sum < Cost)//�ܵĲ�����ֱ��-1
			return -1;

		int start = gas_size - 1;
		int end = 0;
		Sum = gas[start];
		Cost = cost[start];

		while (start > end)//��start������ ��������㹻�� ����һֱ����� end++��  ����������ʱ��
		{                  //start�����  ���� start == end��ʱ������н�һ���ǵ�ǰ start����λ��
			if (Sum >= Cost)//���˷ѵ�ǰ�Ѿ�ѭ������վ�����ݣ��ܾ������
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
		return Sum >= 0 ? start : -1;
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