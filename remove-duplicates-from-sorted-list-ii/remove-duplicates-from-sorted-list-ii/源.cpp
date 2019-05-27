/*Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
For example,
Given1->2->3->3->4->4->5, return1->2->5.
Given1->1->1->2->3, return2->3.*/
#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution 
{
public:
	ListNode *deleteDuplicates(ListNode *head) 
	{
		if (head == nullptr || head->next == nullptr)//��֤��������������
			return head;

		ListNode* assist = new ListNode(0);//�¿���һ����������ռ�ڴ�

		ListNode* q = assist;//��q��������

		ListNode* pre = nullptr;
		ListNode* p = head;//��p��������
		ListNode* pback = p->next;
		while (p != nullptr)
		{
			if (pre == nullptr)
			{
				if (p->val != pback->val)
				{
					q->next = p;
					q = q->next;
				}
			}
			else if (pback == nullptr)
			{
				if (pre->val != p->val)
				{
					q->next = p;
					q = q->next;
				}
			}
			else
			{
				if (pre->val != p->val && p->val != pback->val)
				{
					q->next = p;
					q = q->next;
				}
			}
			pre = p;
			p = p->next;
			if(p!=nullptr)
				pback = p->next;
		}
		q->next = nullptr;//����֮ǰ�����⣬q->next = p;  p�����������ֵ��Ҫ�����ս�����֮ǰ����Щ����������������ֵ��ȥ������
		                  //��Ϊ����ֻ����Ҫp��һ������ѣ�Ȼ��q->next = p;ȴ��p����Ķ���ȫ�������ˣ�����Ҫȥ����
		return assist->next;
	}
};

int main()
{
	ListNode* pNode1 = new ListNode(1);
	ListNode* pNode2 = new ListNode(2);
	ListNode* pNode3 = new ListNode(2);
	pNode1->next = pNode2;
	pNode2->next = pNode3;
	Solution Res;
	ListNode* res = Res.deleteDuplicates(pNode1);
	return 0;
}