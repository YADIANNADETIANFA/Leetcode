/*Merge k sorted linked lists and return it as one sorted list.Analyze and describe its complexity.*/
#include<cstdio>
#include<iostream>
#include<queue>
#include"ListNode.h"
using namespace std;

class Solution1//优先级队列 
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
		for (auto l : lists)//范围for函数，l为lists中一个个的成员
		{
			if(l)//先判断非空在加入！！
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
			if (p->next)//精妙，即首先取含有最大头的List，然后把该List后面的剩余链表当做一个新元素，重新放入到q中
				q.push(p->next);
		}
		return Assist->next;
	}
};

class Solution2//分治算法，基于两个排序链表的合并，两两合并后继续合并，每一轮复杂度o(n), n为总节点个数，T(n) = 2T(n / 2) + o(n), 迭代次数为lg(k), 因此复杂度为o(nlgk)
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
			lists.push_back(mergeTwoSortedLists(lists[0], lists[1]));//合并后重新放入lists中
			lists.erase(lists.begin());//根据迭代器删除
			lists.erase(lists.begin());
		}
		return lists.front();
	}
};