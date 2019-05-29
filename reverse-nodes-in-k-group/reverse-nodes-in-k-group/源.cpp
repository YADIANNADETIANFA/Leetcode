/*Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left - out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.
For example,
Given this linked list : 1->2->3->4->5
For k = 2, you should return : 2->1->4->3->5
For k = 3, you should return : 3->2->1->4->5*/
#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution//˼·������reverse-linked-list-ii  ��Start��End˼·һ��
{
	ListNode* reverse(ListNode* Start,ListNode* End)//����reverse��ĸò��������β�ڵ㣬��End֮ǰ���Ǹ��ڵ�   
	{
		ListNode* pre = nullptr;
		ListNode* pNode = Start->next;
		while (pNode != End)//��ת����
		{
			ListNode* pNext = pNode->next;
			pNode->next = pre;
			pre = pNode;
			pNode = pNext;
		}
		Start->next = pre;//ǰ������Start
		ListNode* p = Start;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = End;//��������End
		return p;
	}
public:
	ListNode *reverseKGroup(ListNode *head, int k) 
	{
		if (head == nullptr || head->next == nullptr || k == 0 || k == 1)
			return head;

		int len = 0;//��ȡ�ܳ���
		ListNode* p = head;
		while (p != nullptr)
		{
			p = p->next;
			++len;
		}

		ListNode* Assist = new ListNode(0);//����ͷ���
		Assist->next = head;

		ListNode* Start = Assist;//��ʼ��Start��End
		ListNode* End = head;

		if (k > len)//����Ĭ�ϴ�������ԭ������
		{
			//ListNode* res=reverse(Assist, nullptr);
			return Assist->next;
		}

		int nums = len / k;
		while (nums != 0)//һ����������
		{
			int get_end = 0;
			while (get_end != k)
			{
				End = End->next;
				++get_end;
			}
			ListNode* res = reverse(Start, End);
			Start = res;//�����µ�Start��End
			nums--;
		}
		return Assist->next;
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
	ListNode* res = Res.reverseKGroup(pNode1, 2);
	return 0;
}