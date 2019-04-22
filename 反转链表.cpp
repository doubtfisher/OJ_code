#include <iostream>
using namespace std;


struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
        val(x), next(NULL) {}
};

//①头插
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL || pHead->next == NULL)
			return pHead;

		ListNode* newhead = NULL;
		ListNode* cur = pHead;
		while (cur)
		{
			ListNode* next = cur->next;
			cur->next = newhead;
			newhead = cur;
			cur = next;

		}
		return newhead;
	}
};

//②一般思路
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return pHead;

		ListNode* n1 = pHead;
		ListNode* n2 = n1->next;
		ListNode* n3 = n2->next;
		n1->next = NULL;
		while (n2)
		{
			n2->next = n1;
			n1 = n2;
			n2 = n3;
			if (n3)
				n3 = n3->next;
		}
		return n1;
	}
};