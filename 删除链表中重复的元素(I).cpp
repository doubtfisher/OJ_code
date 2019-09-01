题目：
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。


示例?1:


输入: 1->1->2

输出: 1->2

示例?2:


输入: 1->1->2->3->3

输出: 1->2->3




实现代码如下：

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur=head;//慢指针
        if(cur==nullptr||cur->next==nullptr)
            return cur;
        ListNode* next=cur->next;//快指针
        while(next!=nullptr)
        {
            if(cur->val!=next->val)//前后元素不相等
            {
                cur=next;
                next=next->next;
            }
            else//找到重复元素
            {
                cur->next=next->next;
                next=next->next;
            }
        }
        return head;
    }
};