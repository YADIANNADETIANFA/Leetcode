/*You are given two linked lists representing two non - negative numbers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output : 7 -> 0 -> 8*/
/*我先梳理一下题的意思。
Input : (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output : 7 -> 0 -> 8
	1、342 + 465 = 807.*/
#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution//两个链表不见得一样长 
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
	{
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;

		ListNode* phead = new ListNode(0);
		ListNode* p = phead;
		int temp = 0;

		while (l1!=nullptr || l2!=nullptr || temp != 0)
		{
			if (l1 != nullptr)
			{
				p->val += l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr)
			{
				p->val += l2->val;
				l2 = l2->next;
			}
			p->val += temp;
			temp = p->val / 10;
			p->val = p->val % 10;
			if (l1 != nullptr || l2 != nullptr || temp != 0)
			{
				ListNode* q = new ListNode(0);
				p->next = q;
				p = p->next;
			}
		}
		return phead;
	}
};