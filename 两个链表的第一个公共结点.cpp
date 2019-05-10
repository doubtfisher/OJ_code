题目：输入两个链表，找出它们的第一个公共结点。

方法1：快慢指针

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* cur1=pHead1;
        ListNode* cur2=pHead2;
        int len1=0,len2=0;
        
        while(cur1!=nullptr)
        {
            len1++;
            cur1=cur1->next;
        }
        
        while(cur2!=nullptr)
        {
            len2++;
            cur2=cur2->next;
        }
        
        int gap=abs(len1-len2);
        ListNode* fast=pHead1;
        ListNode* slow=pHead2;
        if(len1<len2)
        {
            fast=pHead2;
            slow=pHead1;
        }
 
        while(gap--)
        {
            fast=fast->next;
        }
        
        while(fast&&slow)
        {
            if(fast->val==slow->val)
            {
                return fast;
            }
            fast=fast->next;
            slow=slow->next;
        }
        return nullptr;
    }
};




 