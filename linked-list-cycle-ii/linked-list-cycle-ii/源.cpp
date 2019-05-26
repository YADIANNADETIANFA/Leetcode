/*Given a linked list, return the node where the cycle begins.If there is no cycle, returnnull.
Follow up :
Can you solve it without using extra space ?*/
#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution
{
	ListNode* Meeting(ListNode* head)
	{
		if (head == nullptr)
			return nullptr;
		ListNode* slow = head;
		ListNode* quick = head->next;
		if (quick == nullptr)
			return nullptr;
		while (quick != nullptr)
		{
			if (slow == quick)
				return quick;
			slow = slow->next;
			quick = quick->next;
			if (slow == quick)
				return quick;
			if (quick == nullptr)
				return nullptr;
			else
				quick = quick->next;
		}
		return nullptr;
	}
public:
	ListNode *detectCycle(ListNode *head) 
	{
		ListNode* meeting_pos = Meeting(head);//找到环中一点
		if (meeting_pos == nullptr)
			return nullptr;
		ListNode* p = meeting_pos->next;
		int num = 1;
		while (p != meeting_pos)//计算环的大小
		{
			++num;
			p = p->next;
		}
		ListNode* pfirst = head;//找环的起始点
		ListNode* psecond = head;
		while (num != 0)
		{
			psecond = psecond->next;
			--num;
		}
		while (psecond != pfirst)
		{
			psecond = psecond->next;
			pfirst = pfirst->next;
		}
		return pfirst;
	}
};
