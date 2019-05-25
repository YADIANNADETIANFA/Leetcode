/*Sort a linked list in O(n log n) time using constant space complexity.*/
#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution//�鲢����ʱ�临�Ӷ�O(n log n)���ռ�O(n)����������ҲҪ��������������ֱ�Ӱ�����ֵ�ó�����vector���������أ�����ռ䶼һ����
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

		return dummy.next;//���ﲻ����p����Ϊp���Ѳ������ʼλ���ˣ�Ҫ��dummy������ע��Ҫ�� "."������"->" ��
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
		p->next = nullptr;//�Ͽ�ǰ�����������ֳ�����
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