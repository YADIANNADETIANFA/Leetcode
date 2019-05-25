/*Sort a linked list in O(n log n) time using constant space complexity.*/
#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution//归并排序，时间复杂度O(n log n)；空间O(n)。迭代方法也要遍历链表，还不如直接把链表值拿出来放vector里面排序呢，辅存空间都一样大。
{
public:
	ListNode* Merge(ListNode* pleft, ListNode* pright)
	{
		ListNode dummy(0);
		ListNode* p = &dummy;
		while (pleft != nullptr && pright != nullptr)
		{
			if ((pleft->val) < (pright->val))
			{
				p->next = pleft;
				pleft = pleft->next;
			}
			else
			{
				p->next = pright;
				pright = pright->next;
			}
			p = p->next;
		}
		if (pleft == nullptr)
			p->next = pright;
		if (pright == nullptr)
			p->next = pleft;

		return dummy.next;//这里不能用p，因为p早已不在最初始位置了，要用dummy，但是注意要用 "."而不是"->" ！
	}

	ListNode *sortList(ListNode *head) 
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* p = head;
		ListNode* q = head->next;
		while (q != nullptr && q->next != nullptr)
		{
			p = p->next;
			q = q->next->next;
		}
		ListNode* pright = sortList(p->next);
		p->next = nullptr;//断开前后两个链表，分成两段
		ListNode* pleft = sortList(head);
		return Merge(pleft, pright);
	}
};

int main()
{
	ListNode dummoy1(1);
	ListNode* pNode1=&dummoy1;

	ListNode dummoy2(2);
	ListNode* pNode2 = &dummoy2;

	pNode1->next = pNode2;

	Solution Res;
	ListNode* res = Res.sortList(pNode1);
	return 0;
}