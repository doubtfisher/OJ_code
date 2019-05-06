//题目：输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则.

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr&&pHead2 == nullptr)
		{
			return pHead1;
		}

		if (pHead1 == nullptr)
		{
			return pHead2;
		}

		if (pHead2 == nullptr)
		{
			return pHead1;
		}

		ListNode* newhead = nullptr;
		//1.拿小的节点进行头插
		if (pHead1->val<pHead2->val)
		{
			newhead = pHead1;
			pHead1 = pHead1->next;
		}
		else
		{
			newhead = pHead2;
			pHead2 = pHead2->next;
		}
		//2.取小的节点进行尾插
		ListNode* tail = newhead;
		while (pHead1 != nullptr&&pHead2 != nullptr)
		{
			if (pHead1->val< pHead2->val)
			{
				tail->next = pHead1;
				pHead1 = pHead1->next;
			}
			else
			{
				tail->next = pHead2;
				pHead2 = pHead2->next;
			}
			tail = tail->next;
		}
		if (pHead1 != nullptr)
		{
			tail->next = pHead1;
		}
		if (pHead2 != nullptr)
		{
			tail->next = pHead2;
		}

		return newhead;
	}
};