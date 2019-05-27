/*Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
For example,
Given1->2->3->3->4->4->5, return1->2->5.
Given1->1->1->2->3, return2->3.*/
#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution 
{
public:
	ListNode *deleteDuplicates(ListNode *head) 
	{
		if (head == nullptr || head->next == nullptr)//保证最起码有两个点
			return head;

		ListNode* assist = new ListNode(0);//新开启一个链表，但不占内存

		ListNode* q = assist;//用q操纵链表

		ListNode* pre = nullptr;
		ListNode* p = head;//用p遍历链表
		ListNode* pback = p->next;
		while (p != nullptr)
		{
			if (pre == nullptr)
			{
				if (p->val != pback->val)
				{
					q->next = p;
					q = q->next;
				}
			}
			else if (pback == nullptr)
			{
				if (pre->val != p->val)
				{
					q->next = p;
					q = q->next;
				}
			}
			else
			{
				if (pre->val != p->val && p->val != pback->val)
				{
					q->next = p;
					q = q->next;
				}
			}
			pre = p;
			p = p->next;
			if(p!=nullptr)
				pback = p->next;
		}
		q->next = nullptr;//还是之前的问题，q->next = p;  p后面会有垃圾值，要在最终结果输出之前把这些不符合条件的垃圾值给去除掉！
		                  //因为我们只是想要p这一个点而已，然而q->next = p;却把p后面的东西全给带来了！所以要去除！
		return assist->next;
	}
};

int main()
{
	ListNode* pNode1 = new ListNode(1);
	ListNode* pNode2 = new ListNode(2);
	ListNode* pNode3 = new ListNode(2);
	pNode1->next = pNode2;
	pNode2->next = pNode3;
	Solution Res;
	ListNode* res = Res.deleteDuplicates(pNode1);
	return 0;
}