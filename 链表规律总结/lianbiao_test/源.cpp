#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;

int main()
{
	int a = 1;
	int b = a;
	ListNode* pNode1 = new ListNode(1);//0x00895708{val=1 next=0x00000000<NULL>}，0x....是pNode1这个指针的值（指针的值就是地址）,{}中为指向的内容的值
	ListNode* pNode2 = new ListNode(2);
	ListNode* pNode3 = new ListNode(3);
	ListNode* pNode4 = new ListNode(4);
	ListNode* pNode5 = new ListNode(5);
	ListNode* pNode6 = new ListNode(6);

	pNode1->next = pNode2;
	pNode2->next = pNode3;
	pNode3->next = pNode4;
	pNode4->next = pNode5;
	pNode5->next = pNode6;

	ListNode* pNode10 = new ListNode(10);

	ListNode* pHead = pNode1;//将pNode1的值拷贝一份给pHead，而pHead和pNode1各自的位置是不同的，因此，在拷贝完成后，两者是值相同但互不相关的两个独立个体
	pHead = pHead->next;//1：pHead = pHead->next不会影响pNode1的内容，只是pHead指针换指向位置了，不影响原来的pNode1
	                    //  会影响pNode1的只有p->val和p->next,这种修改内容而不是修改指向的
	ListNode** ppHead = &pHead;//pHead的值为0x02fb5708；地址为0x00cffd0c        所以两个指针值相同，但是储存指针的位置各不相同
	ListNode** ppNode1 = &pNode1;//pNode1的值为0x02fb5708；地址为0x00cffd60

	//pHead->next = pNode10;//2：pHead和pNode1这两个指针的值相同，指向同一个地方（这两个指针所在的位置可能不相同，但是值相同）
	                      //修改pHead的值，也就意味着修改了pNode1的值，所以pHead和pNode1都发生了变化
	return 0;
}