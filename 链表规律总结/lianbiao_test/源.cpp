#include<cstdio>
#include<iostream>
#include"ListNode.h"
using namespace std;

int main()
{
	int a = 1;
	int b = a;
	ListNode* pNode1 = new ListNode(1);//0x00895708{val=1 next=0x00000000<NULL>}��0x....��pNode1���ָ���ֵ��ָ���ֵ���ǵ�ַ��,{}��Ϊָ������ݵ�ֵ
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

	ListNode* pHead = pNode1;//��pNode1��ֵ����һ�ݸ�pHead����pHead��pNode1���Ե�λ���ǲ�ͬ�ģ���ˣ��ڿ�����ɺ�������ֵ��ͬ��������ص�������������
	pHead = pHead->next;//1��pHead = pHead->next����Ӱ��pNode1�����ݣ�ֻ��pHeadָ�뻻ָ��λ���ˣ���Ӱ��ԭ����pNode1
	                    //  ��Ӱ��pNode1��ֻ��p->val��p->next,�����޸����ݶ������޸�ָ���
	ListNode** ppHead = &pHead;//pHead��ֵΪ0x02fb5708����ַΪ0x00cffd0c        ��������ָ��ֵ��ͬ�����Ǵ���ָ���λ�ø�����ͬ
	ListNode** ppNode1 = &pNode1;//pNode1��ֵΪ0x02fb5708����ַΪ0x00cffd60

	//pHead->next = pNode10;//2��pHead��pNode1������ָ���ֵ��ͬ��ָ��ͬһ���ط���������ָ�����ڵ�λ�ÿ��ܲ���ͬ������ֵ��ͬ��
	                      //�޸�pHead��ֵ��Ҳ����ζ���޸���pNode1��ֵ������pHead��pNode1�������˱仯
	return 0;
}