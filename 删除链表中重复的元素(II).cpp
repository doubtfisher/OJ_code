题目：
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中?没有重复出现?的数字。


示例?1:


输入: 1->2->3->3->4->4->5

输出: 1->2->5

示例?2:


输入:
 1->1->1->2->3

输出: 2->3



实现代码如下：

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode* prev=nullptr;
        ListNode* cur=head;
        ListNode* next=cur->next;
        while(next!=nullptr)
        {
            if(cur->val!=next->val)
            {
                prev=cur;
                cur=next;
                next=next->next;
                
            }
            else
            {
                while(next!=nullptr && cur->val==next->val)
                {
                    next=next->next;
                }
                if(prev!=nullptr)//考虑可能第一个节点开始就是相同的，这样的话，head就会发生变化
                    prev->next=next;
                else
                    head=next;
                //删除重复的节点
                while(cur!=next)
                {
                    ListNode* n=cur->next;
                    delete cur;
                    cur=n;
                }
                cur=next;
                if(next)
                    next=next->next;
            }
        }
        return head;
    }
};