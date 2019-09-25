题目：
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

方法1：
 class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode* n1=head;
        ListNode* n2=n1->next;
        ListNode* n3=n2->next;
        n1->next=nullptr;
        while(n2)
        {
            n2->next=n1;
            n1=n2;
            n2=n3;
            if(n3)//考虑n3不为空
                n3=n3->next;
        }
        return n1;
        
    }
};

方法2：

代码实现：

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead =nullptr;
        ListNode* cur=head;
        while(cur)
        {
            ListNode* next=cur->next;
            cur->next=newhead;
            newhead=cur;
            cur=next;
        }
        return newhead;
    }
};
