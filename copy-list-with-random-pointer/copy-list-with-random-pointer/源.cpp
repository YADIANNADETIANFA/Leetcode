/*A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.*/
#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution 
{
public:
	RandomListNode *copyRandomList(RandomListNode *head)//逐个节点尾后复制，处理随机指针，分离新旧链表 
	{
		if (head == nullptr)
			return nullptr;

		RandomListNode* p = head;
		for (; p != nullptr; p = p->next)//逐个节点尾后复制
		{
			RandomListNode* copy = new RandomListNode(p->label);//创建新的节点，深复制
			copy->next = p->next;
			p->next = copy;
			p = p->next;//到达copy节点，再配合for循环的p = p->next，正好到下一个节点
		}
		for (p = head; p != nullptr; p = p->next)//处理随机指针
		{
			RandomListNode* copy = p->next;
			copy->random = (p->random ? p->random->next : nullptr);//图片解释为什么p->random->next
			p = p->next;
		}
		p = head;//第三部分要理清：目标是使head变为原链表，copy_list成为复制的链表。  其中head和copy_list分别是这两个链表的开头，保留之。 分别利用p和copy来分别建立这两个链表
		RandomListNode* copy = head->next;
		RandomListNode* copy_list = head->next;
		for (; p != nullptr; p = p->next)
		{
			p->next = p->next->next;
			copy->next = (p->next ? p->next->next : nullptr);//最末尾只有一个nullptr，可不是nullptr--nullptr
			copy = copy->next;
		}
		return copy_list;
	}
};
