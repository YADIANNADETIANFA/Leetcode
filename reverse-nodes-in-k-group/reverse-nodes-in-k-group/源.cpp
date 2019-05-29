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

class Solution//思路类似于reverse-linked-list-ii  其Start与End思路一样
{
	ListNode* reverse(ListNode* Start,ListNode* End)//返回reverse后的该部分链表的尾节点，即End之前的那个节点   
	{
		ListNode* pre = nullptr;
		ListNode* pNode = Start->next;
		while (pNode != End)//反转链表
		{
			ListNode* pNext = pNode->next;
			pNode->next = pre;
			pre = pNode;
			pNode = pNext;
		}
		Start->next = pre;//前面连接Start
		ListNode* p = Start;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = End;//后面连接End
		return p;
	}
public:
	ListNode *reverseKGroup(ListNode *head, int k) 
	{
		if (head == nullptr || head->next == nullptr || k == 0 || k == 1)
			return head;

		int len = 0;//获取总长度
		ListNode* p = head;
		while (p != nullptr)
		{
			p = p->next;
			++len;
		}

		ListNode* Assist = new ListNode(0);//辅助头结点
		Assist->next = head;

		ListNode* Start = Assist;//初始化Start和End
		ListNode* End = head;

		if (k > len)//本题默认此情况输出原链表即可
		{
			//ListNode* res=reverse(Assist, nullptr);
			return Assist->next;
		}

		int nums = len / k;
		while (nums != 0)//一共操作几次
		{
			int get_end = 0;
			while (get_end != k)
			{
				End = End->next;
				++get_end;
			}
			ListNode* res = reverse(Start, End);
			Start = res;//定义新的Start和End
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