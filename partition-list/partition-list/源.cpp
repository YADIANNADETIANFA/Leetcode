/*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
For example,
Given1->4->3->2->5->2 and x = 3,
return1->2->2->4->3->5.*/
#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution//����С��ָ������������ü�ԭ����õ��������¾���������  //����"�ü�ԭ����õ�������"�����ǳ��˴��ͷ�����ᰡ������
{
public:
	ListNode *partition(ListNode *head, int x) 
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode* New_list = new ListNode(0);
		ListNode* New_head = New_list;//�����������ͷ
		ListNode* Old_head = new ListNode(0);//�½�һ���ڵ㣬Ϊ�˱���������ͷ�ķ���
		Old_head->next = head;
		ListNode* p = head;//��pȥ����ԭʼ����
		ListNode* q = Old_head;//��������������������������������qȥ���ӵõ���������������������
		while (p != nullptr)
		{
			ListNode* pNext = p->next;
			if (p->val < x)
			{
				New_list->next = p;
				New_list = New_list->next;
				p->next = nullptr;
			}
			else//�������������������˺ܾò������׸���ô��
			{
				q->next = p;
				q = q->next;
			}
			p = pNext;
		}
		q->next = nullptr;//q->next = p��  p���滹�в����Ͼ�����ĵ㣬�ǵ�ɾ����������

		if(Old_head->next!=nullptr)//�����¾�����
			New_list->next = Old_head->next;
		return New_head->next;
	}
};

int main()
{
	ListNode* pNode1 = new ListNode(1);
	ListNode* pNode2 = new ListNode(4);
	ListNode* pNode3 = new ListNode(3);
	ListNode* pNode4 = new ListNode(2);
	ListNode* pNode5 = new ListNode(5);
	ListNode* pNode6 = new ListNode(2);

	pNode1->next = pNode2;
	pNode2->next = pNode3;
	pNode3->next = pNode4;
	pNode4->next = pNode5;
	pNode5->next = pNode6;

	Solution Res;
	ListNode* res = Res.partition(pNode1, 3);
	return 0;
}