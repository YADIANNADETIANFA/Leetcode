/*Given a singly linked list L : L 0��L 1������L n - 1��L n,
reorder it to : L 0��L n ��L 1��L n - 1��L 2��L n - 2����
You must do this in - place without altering the nodes' values.
For example,
Given{ 1,2,3,4 }, reorder it to{ 1,4,2,3 }.*/
#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;


class Solution1//�����ⷨ���ظ��������� 
{
public:
	void reorderList(ListNode *head) {
		if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
			return;

		ListNode* temp;
		ListNode* cur = head;
		while (cur->next != nullptr && cur->next->next != nullptr)//ֻʣ���������ʱ��˳���������
		{
			ListNode* cur_next = cur->next;
			temp = cur;
			while (temp->next != nullptr &&temp->next->next != nullptr)
				temp = temp->next;
			cur->next = temp->next;
			temp->next = nullptr;
			cur->next->next = cur_next;
			cur = cur_next;
		}
		return;
	}
};

class Solution2 //��֣���ת���ϲ�����
{
public:
	ListNode* Reorder(ListNode* pright)
	{
		ListNode* pright_reorder = nullptr;
		ListNode* pre = nullptr;
		ListNode* pNode = pright;

		while (pNode != nullptr)
		{
			ListNode* pNext = pNode->next;

			if (pNext == nullptr)
				pright_reorder = pNode;

			pNode->next = pre;
			pre = pNode;
			pNode = pNext;
		}
		return pright_reorder;
	}
	void Merge_two(ListNode* pleft, ListNode* pright_reorder)
	{
		while (pright_reorder != nullptr)
		{
			ListNode* pright_reorder_next = pright_reorder->next;
			pright_reorder->next = pleft->next;
			pleft->next = pright_reorder;
			pleft = pleft->next->next;
			pright_reorder = pright_reorder_next;
		}
		return;
	}
	void reorderList(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
			return;

		ListNode* slow = head;
		ListNode* quick = head->next;
		while (quick != nullptr && quick->next != nullptr)
		{
			slow = slow->next;
			quick = quick->next->next;
		}

		ListNode* pleft = head;//�������,�õ����������ȴ��ڵ���������
		ListNode* pright = slow->next;
		slow->next = nullptr;

		ListNode* pright_reorder = Reorder(pright);//��ת����
		Merge_two(pleft, pright_reorder);//�ϲ�����
		return;
	}
};