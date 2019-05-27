/*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
For example,
Given1->4->3->2->5->2 and x = 3,
return1->2->2->4->3->5.*/
#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution//创建小于指定点的新链表，裁剪原链表得到旧链表，新旧链表连接  //其中"裁剪原链表得到旧链表"让我们吃了大苦头，不会啊。。。
{
public:
	ListNode *partition(ListNode *head, int x) 
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode* New_list = new ListNode(0);
		ListNode* New_head = New_list;//保留新链表的头
		ListNode* Old_head = new ListNode(0);//新建一个节点，为了保留旧链表头的方便
		Old_head->next = head;
		ListNode* p = head;//用p去遍历原始链表
		ListNode* q = Old_head;//！！！！！！！！！！！！！！！用q去连接得到旧链表！！！！！！！！
		while (p != nullptr)
		{
			ListNode* pNext = p->next;
			if (p->val < x)
			{
				New_list->next = p;
				New_list = New_list->next;
				p->next = nullptr;
			}
			else//！！！！！！！！想了很久才想明白该这么做
			{
				q->next = p;
				q = q->next;
			}
			p = pNext;
		}
		q->next = nullptr;//q->next = p，  p后面还有不符合旧链表的点，记得删掉！！！！

		if(Old_head->next!=nullptr)//连接新旧链表
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