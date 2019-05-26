/*Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.*/
//���������Ϊƽ�����������ô��
#include<cstdio>
#include<iostream>
#include"ListNode.h"
#include"TreeNode.h"
using namespace std;

class Solution 
{
	TreeNode* Get_BST(ListNode* head, ListNode* tail)//��Ƶĺܾ��������tail�����ã�Ҫ�Լ����ֻ�������������
	{
		if (head == tail)
			return nullptr;
		ListNode* fast = head;//����ָ�����м�ڵ�
		ListNode* slow = head;
		while (fast != tail && fast->next != tail)//��tail�Ƚϣ����Ǻ�nullptr�Ƚ�,�ܰ�д��fast != nullptr && fast->next != nullptr,���Ǵ��   //���⣬ż����Ļ����м�ڵ�ȡ�����Ǹ�
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		TreeNode* pRoot = new TreeNode(slow->val);
		pRoot->left = Get_BST(head, slow);
		pRoot->right = Get_BST(slow->next, tail);
		return pRoot;
	}
public:
	TreeNode *sortedListToBST(ListNode *head) 
	{
		return Get_BST(head, nullptr);
	}
};