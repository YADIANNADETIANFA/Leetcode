/*Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.*/
//递增链表改为平衡二叉搜索树么？
#include<cstdio>
#include<iostream>
#include"ListNode.h"
#include"TreeNode.h"
using namespace std;

class Solution 
{
	TreeNode* Get_BST(ListNode* head, ListNode* tail)//设计的很精妙，尤其是tail的利用，要自己动手画画才能理解奥义
	{
		if (head == tail)
			return nullptr;
		ListNode* fast = head;//快慢指针找中间节点
		ListNode* slow = head;
		while (fast != tail && fast->next != tail)//和tail比较，不是和nullptr比较,总爱写成fast != nullptr && fast->next != nullptr,这是错的   //另外，偶数点的话，中间节点取后面那个
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		TreeNode* pRoot = new TreeNode(slow->val);
		pRoot->left = Get_BST(head, slow);
		pRoot->right = Get_BST(slow->next, tail);
		return pRoot;
	}
	
	void Get_List(TreeNode* pRoot,ListNode* &pNode)//Get_List和BST_To_List用于二叉树转链表，其实就特么的中序遍历！！
	{
		if (pRoot == nullptr)
			return;
		Get_List(pRoot->left,pNode);
		ListNode* pNew = new ListNode(pRoot->val);
		pNode->next = pNew;
		pNode = pNode->next;
		Get_List(pRoot->right,pNode);
		return;
	}
public:
	TreeNode *sortedListToBST(ListNode *head) 
	{
		return Get_BST(head, nullptr);
	}
	
	ListNode* BST_To_List(TreeNode* pRoot)
	{
		ListNode* pHead = new ListNode(0);
		ListNode* pNode = pHead;
		Get_List(pRoot,pNode);
		return pHead->next;
	}
};
