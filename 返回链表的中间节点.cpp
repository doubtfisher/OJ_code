题目：
给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。

思路：让快指针走两步，慢指针走一步。

快慢指针代码实现：
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* cur=head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};