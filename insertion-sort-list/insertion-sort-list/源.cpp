/*Sort a linked list using insertion sort.*/
//注意使用插入排序，不是选择排序
#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution1//创建一个新的链表,貌似只是不断移动指针指向，没有占用新的内存空间吧
{
public:
	ListNode *insertionSortList(ListNode *head) 
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode* dummy = new ListNode(0);//创建一个新链表，注意创建方法
		ListNode* cur = head;
		while (cur != nullptr)
		{
			ListNode* cur_next = cur->next;//保存一下，一会好从这里开始下一次的循环
			ListNode* p = dummy;//每次都从头开始，遍历已排序好了的链表
			while (p->next != nullptr && p->next->val <= cur->val)
				p = p->next;
			cur->next = p->next;//把cur插入到p和p->next之间，所以cur的后面要写为p->next
			p->next = cur;
			cur = cur_next;//前面保存的东西用上了
		}
		return dummy->next;
	}
};
