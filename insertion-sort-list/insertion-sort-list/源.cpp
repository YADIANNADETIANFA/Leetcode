/*Sort a linked list using insertion sort.*/
//注意使用插入排序，不是选择排序
#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution1//创建一个新的链表,只是不断移动指针指向，没有占用新的内存空间
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
				p = p->next;//只改p，不会改变dummy的
			cur->next = p->next;//把cur插入到p和p->next之间，所以cur的后面要写为p->next   //举例：首次调用时，head也会跟着cur一起变内容
			p->next = cur;
			cur = cur_next;//前面保存的东西用上了
		}
		return dummy->next;
	}
};


int main()
{
	Solution1 Res;

	ListNode* pNode1 = new ListNode(3);
	ListNode* pNode2 = new ListNode(4);
	ListNode* pNode3 = new ListNode(5);
	ListNode* pNode4 = new ListNode(2);
	ListNode* pNode5 = new ListNode(1);

	pNode1->next = pNode2;
	pNode2->next = pNode3;
	pNode3->next = pNode4;
	pNode4->next = pNode5;

	ListNode* res = Res.insertionSortList(pNode1);

	return 0;
}
