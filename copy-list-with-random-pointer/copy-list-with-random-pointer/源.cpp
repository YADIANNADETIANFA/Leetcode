/*A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.*/
#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution 
{
public:
	RandomListNode *copyRandomList(RandomListNode *head)//����ڵ�β���ƣ��������ָ�룬�����¾����� 
	{
		if (head == nullptr)
			return nullptr;

		RandomListNode* p = head;
		for (; p != nullptr; p = p->next)//����ڵ�β����
		{
			RandomListNode* copy = new RandomListNode(p->label);//�����µĽڵ㣬���
			copy->next = p->next;
			p->next = copy;
			p = p->next;//����copy�ڵ㣬�����forѭ����p = p->next�����õ���һ���ڵ�
		}
		for (p = head; p != nullptr; p = p->next)//�������ָ��
		{
			RandomListNode* copy = p->next;
			copy->random = (p->random ? p->random->next : nullptr);//ͼƬ����Ϊʲôp->random->next
			p = p->next;
		}
		p = head;//��������Ҫ���壺Ŀ����ʹhead��Ϊԭ����copy_list��Ϊ���Ƶ�����  ����head��copy_list�ֱ�������������Ŀ�ͷ������֮�� �ֱ�����p��copy���ֱ�������������
		RandomListNode* copy = head->next;
		RandomListNode* copy_list = head->next;
		for (; p != nullptr; p = p->next)
		{
			p->next = p->next->next;
			copy->next = (p->next ? p->next->next : nullptr);//��ĩβֻ��һ��nullptr���ɲ���nullptr--nullptr
			copy = copy->next;
		}
		return copy_list;
	}
};
