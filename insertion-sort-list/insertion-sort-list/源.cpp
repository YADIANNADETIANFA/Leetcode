/*Sort a linked list using insertion sort.*/
//ע��ʹ�ò������򣬲���ѡ������
#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution1//����һ���µ�����,ò��ֻ�ǲ����ƶ�ָ��ָ��û��ռ���µ��ڴ�ռ��
{
public:
	ListNode *insertionSortList(ListNode *head) 
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode* dummy = new ListNode(0);//����һ��������ע�ⴴ������
		ListNode* cur = head;
		while (cur != nullptr)
		{
			ListNode* cur_next = cur->next;//����һ�£�һ��ô����￪ʼ��һ�ε�ѭ��
			ListNode* p = dummy;//ÿ�ζ���ͷ��ʼ��������������˵�����
			while (p->next != nullptr && p->next->val <= cur->val)
				p = p->next;
			cur->next = p->next;//��cur���뵽p��p->next֮�䣬����cur�ĺ���ҪдΪp->next
			p->next = cur;
			cur = cur_next;//ǰ�汣��Ķ���������
		}
		return dummy->next;
	}
};
