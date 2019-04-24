#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

class Solution//�����ȷ�������Ӷȸߣ��ڴ�ռ�ô����򻹲�׼ȷ
{
public:
	vector<vector<int>> subsetsWithDup(vector<int>& S)
	{
		sort(S.begin(), S.end(),less<int>());
		vector<vector<int>> Res;

		vector<int>::iterator iter1 = S.begin();
		for (;iter1 != S.end(); ++iter1)//��������ʡ�����ǣ�����Ҫ��������
		{
			int len = Res.size();
			vector<vector<int>>::iterator iter2 = Res.begin();
 			for (;iter2 != Res.begin()+len; ++iter2)
			{
				vector<int> temp=*iter2;
				temp.push_back(*iter1);
				bool GetIn = true;
				for (vector<vector<int>>::iterator iter2 = Res.begin(); iter2 != Res.end(); ++iter2)//iter2 != Res.begin()+len;���ԣ�����1 2 2�᲻�ϱ��ӽ�Res����ģ���ѭ��
				{
					if (*iter2 == temp)
					{
						GetIn = false;
						break;
					}
				}
				if (GetIn)
				{
					Res.push_back(temp);//������ʧЧ��Ҫ���¶���
					//vector<vector<int>>::iterator iter2 = Res.begin();//�ض��壬���ԣ�
					iter2 = Res.begin();
				}
			}
			bool GetIn = true;
			vector<int> temp(1, *iter1);
			vector<vector<int>>::iterator iter3 = Res.begin();
			for (; iter3 != Res.begin() + len; ++iter3)
			{
				if (*iter3 == temp)
				{
					GetIn = false;
					break;
				}
			}
			if (GetIn)
			{
				Res.push_back(temp);
			}
		}
		vector<int> res1;//������
        Res.insert(Res.begin(),res1);
		return Res;
	}
};

class Solution2//����/������ȱ���
{
public:
	vector<vector<int>> subsetsWithDup(vector<int> &S)
	{
		sort(S.begin(), S.end());
		dfs(S, 0);
		return result;
	}
	void dfs(vector<int> set, int start)
	{
		result.push_back(temp);
		for (int i = start; i < set.size(); ++i)
		{
			temp.push_back(set[i]);
			dfs(set, i + 1);//i+1��ʾ����S����ʣ�����Щ����ʼ����
			while (i < set.size() - 1 && set[i] == set[i + 1])//��S�ķ�Χ�ڣ�����S��������ȣ���ֻ�õ�һ���͹��ˣ��������ӹ�
				++i;//�����ˣ�for�е�i���Խ��в�����������������
			temp.pop_back();//[1 2 3]  �����Ϊ��[] [1] [1,2] [1,2,3] [1,3] [2] [2,3] [3]
		}
	}
private:
	vector<vector<int>> result;
	vector<int> temp;//ɶҲ�������������[]
};

int main()
{
	while (true)
	{
		vector<int> num;
		int n;
		char c;
		while ((cin>>n).get(c))
		{
			num.push_back(n);
			if (c == '\n')
				break;
		}
		Solution RES;
		vector<vector<int>> shuzu;
		shuzu=RES.subsetsWithDup(num);
	}
	return 0;
}