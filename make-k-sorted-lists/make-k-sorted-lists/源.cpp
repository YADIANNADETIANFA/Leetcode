/*Merge k sorted linked lists and return it as one sorted list.Analyze and describe its complexity.*/
#include<cstdio>
#include<iostream>
#include<queue>
#include"ListNode.h"
using namespace std;

class Solution1//���ȼ����� 
{
public:
	struct compare
	{
		bool operator()(const ListNode* a, const ListNode* b) const
		{
			return a->val > b->val;
		}
	};
	ListNode *mergeKLists(vector<ListNode *> &lists) 
	{
		priority_queue<ListNode*, vector<ListNode*>, compare> q;
		for (auto l : lists)//��Χfor������lΪlists��һ�����ĳ�Ա
		{
			if(l)//���жϷǿ��ڼ��룡��
				q.push(l);
		}
		if (q.empty())
			return nullptr;
		ListNode* Assist = new ListNode(0);
		ListNode* p = Assist;
		while (!q.empty())
		{
			p->next = q.top();
			q.pop();
			p = p->next;
			if (p->next)//���������ȡ�������ͷ��List��Ȼ��Ѹ�List�����ʣ��������һ����Ԫ�أ����·��뵽q��
				q.push(p->next);
		}
		return Assist->next;
	}
};

class Solution2//�����㷨������������������ĺϲ��������ϲ�������ϲ���ÿһ�ָ��Ӷ�o(n), nΪ�ܽڵ������T(n) = 2T(n / 2) + o(n), ��������Ϊlg(k), ��˸��Ӷ�Ϊo(nlgk)
{
public:
	ListNode* mergeTwoSortedLists(ListNode* L1, ListNode* L2)
	{
		if (L1 == nullptr)
			return L2;
		if (L2 == nullptr)
			return L1;
		if (L1->val <= L2->val)
		{
			L1->next = mergeTwoSortedLists(L1->next, L2);
			return L1;
		}
		else
		{
			L2->next = mergeTwoSortedLists(L1, L2->next);
			return L2;
		}
	}
	ListNode *mergeKLists(vector<ListNode *> &lists) 
	{
		if (lists.empty())
			return nullptr;
		while (lists.size() > 1)
		{
			lists.push_back(mergeTwoSortedLists(lists[0], lists[1]));//�ϲ������·���lists��
			lists.erase(lists.begin());//���ݵ�����ɾ��
			lists.erase(lists.begin());
		}
		return lists.front();
	}
};