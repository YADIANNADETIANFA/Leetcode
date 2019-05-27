/*Reverse a linked list from position m to n.Do it in - place and in one - pass.
For example :
Given1->2->3->4->5->NULL, m = 2 and n = 4,
return1->4->3->2->5->NULL.
Note :
	Given m, n satisfy the following condition :
1 �� m �� n �� length of list.*/
#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution//��ҪС�����⣬ϸ�ںܶ�
{
	ListNode* Reverse(ListNode* head, ListNode* Start, ListNode* End)//���ܷ���head����Ϊԭͷ���headҲ���ܻᱻ�Ƶ��м�
	{
		ListNode* pre = nullptr;
		ListNode* pHead;//����ȷ����ת�����ͷ
		ListNode* pNode;
		if (Start == nullptr)
		{
			pHead = head;
			pNode = head;
		}
		else
		{
			pHead = Start->next;
			pNode = Start->next;
		}
		while (pNode != End)//��ת����
		{
			ListNode* pNext = pNode->next;
			pNode->next = pre;
			pre = pNode;
			pHead = pNode;
			pNode = pNext;
		}
		if(Start!=nullptr)//Start���ڵĻ�������Start
			Start->next = pHead;
		ListNode* pTail = pHead;
		while (pTail->next != nullptr)
			pTail = pTail->next;
		pTail->next = End;//����End

		if (Start == nullptr)
			return pHead;//ԭͷ����ƶ���
		else
			return head;//ԭͷ���δ�ƶ�
	}
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) //������1->2->3->4->5->null��m=2��n=4����ôStart=1��End=5�����м���з�ת��Ȼ��ֱ�����Start��End
	{
		if (m == n)
			return head;

		ListNode* Start = nullptr;
		ListNode* End = head;
		if (m > 1)
			Start = head;
		while (m > 2)
		{
			Start = Start->next;
			--m;
		}
		while (n > 0)
		{
			End = End->next;
			--n;
		}
		ListNode* res=Reverse(head, Start, End);
		return res;
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
	ListNode* res = Res.reverseBetween(pNode1, 4, 5);
	return 0;
}