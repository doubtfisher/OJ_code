//��Ŀ�����������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������.

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
		//1.��С�Ľڵ����ͷ��
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
		//2.ȡС�Ľڵ����β��
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