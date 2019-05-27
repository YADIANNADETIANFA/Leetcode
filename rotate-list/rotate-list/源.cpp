/*Given a list, rotate the list to the right by k places, where k is non - negative.
For example :
Given1->2->3->4->5->NULLand k = 2,
return4->5->1->2->3->NULL.*/
#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution
{
public:
	ListNode *rotateRight(ListNode *head, int k)//˫ָ����⣬�����ص����ڣ�k�п��ܴ��������ȣ��� �������������Ӧk������kȥ��Ӧ������򵥣�
	{
		if (head == nullptr || head->next == nullptr || k==0)
			return head;

		int len = 0;
		ListNode* p = head;
		while (p != nullptr)
		{
			p = p->next;
			++len;
		}
		k = k % len;
		if (k == 0)//����k�п��ܶ��ε�0�������ˣ����鲻������������ǡ���
			return head;

		ListNode* forward = head;
		ListNode* behind = head;
		while (k != 0)
		{
			behind = behind->next;
			--k;
		}
		while (behind->next != nullptr)
		{
			forward = forward->next;
			behind = behind->next;
		}
		ListNode* before = forward->next;
		forward->next = nullptr;
		behind->next = head;

		return before;
	}
};

int main()
{
	ListNode* pNode1 = new ListNode(1);
	ListNode* pNode2 = new ListNode(2);
	ListNode* pNode3 = new ListNode(3);
	ListNode* pNode4 = new ListNode(4);
	ListNode* pNode5 = new ListNode(5);

	pNode1->next = pNode2;
	pNode2->next = pNode3;
	pNode3->next = pNode4;
	pNode4->next = pNode5;

	Solution Res;
	ListNode* res = Res.rotateRight(pNode1, 2);
	return 0;
}