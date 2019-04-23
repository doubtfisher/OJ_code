//题目：链表中倒数第k个节点

//使用快慢指针的思想

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
			if (fast)//一定注意要判空
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