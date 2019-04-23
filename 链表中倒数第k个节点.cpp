//��Ŀ�������е�����k���ڵ�

//ʹ�ÿ���ָ���˼��

#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
}; 
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* fast = pListHead;
		ListNode* slow = fast;
		while (k--)
		{
			if (fast)//һ��ע��Ҫ�п�
				fast = fast->next;
			else
				return NULL;
		}
		while (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};