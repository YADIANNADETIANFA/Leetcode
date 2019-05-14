/*Given a collection of numbers that might contain duplicates, return all possible unique permutations.
For example,
[1, 1, 2]have the following unique permutations :
[1, 1, 2], [1, 2, 1], and[2, 1, 1].*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution1 
{
public:
	vector<vector<int> > permuteUnique(vector<int> &num) 
	{
		sort(num.begin(), num.end());//������
		int len = num.size();
		vector<vector<int>> res;
		vector<int> temp;//����ʹ��
		vector<bool> is_used(len, false);//���num����Щλ���Ѿ����ù���
		dfs(num, res, temp, is_used);//����˵�ľ��������
		return res;
	}
	void dfs(vector<int> num, vector<vector<int>> &res, vector<int> temp, vector<bool> is_used)//����Ҫ�����ã���Ȼ���ص���ԭʼδ�ı������������ã�
	{
		if (temp.size() == num.size())
		{
			res.push_back(temp);
			return;
		}
		for (int i = 0; i < num.size(); ++i)
		{
			if (!is_used[i])//���û��ʹ�ù�
			{
				temp.push_back(num[i]);
				is_used[i] = true;
				dfs(num, res, temp, is_used);//�������洦��
				temp.pop_back();
				is_used[i] = false;//�����������ˣ������˸��˼һ�ԭ��
				while ((i + 1) < num.size() && num[i] == num[i + 1])//ȷ����ͬԪ��ֻʹ��һ�Σ���
					++i;
			}
		}
	}
};

class Solution2//���ظ����֣���ζ�����ظ�����ϣ�ȥ�������뵽�ķ�������set���� //C++ STL�е�set������ģ������������ʱ���ǰ����ֵ�˳��ģ�����ʡȥ���������
{
private:
	set<vector<int>> st;//��������ǻ���һЩ���Ͼ��ظ��Ĳ���ᱻ��������
public:
	vector<vector<int> > permuteUnique(vector<int> &num) 
	{
		vector<vector<int>> res;
		if (num.size() == 0)
			return res;
		int start = 0;
		dfs(num, start);
		set<vector<int>>::iterator iter;
		for (iter = st.begin(); iter != st.end(); ++iter)
			res.push_back(*iter);//�ѽ����setת����vector
		return res;
	}
	void dfs(vector<int> num, int start)
	{
		if (start == num.size())
			st.insert(num);//setû��push_back,ֻ��insert����
		for (int i = start; i < num.size(); ++i)
		{
			swap(num[i], num[start]);
			dfs(num, start + 1);
			swap(num[start], num[i]);
		}
	}
};

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(1);
	num.push_back(2);
	Solution1 Res;
	vector<vector<int>> res = Res.permuteUnique(num);
	return 0;
}