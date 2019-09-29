题目：
输入一个链表，输出该链表中倒数第k个结点。

（1）快慢指针：
①先让快指针走k-1步，然后快慢指针同时走，当快指针走到最后一个节点时，slow指针就是倒数第K个节点；
②先让快指针走k步，然后快慢指针同时走，当快指针走到空时，slow指针就是倒数第K个节点；

代码实现：
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==nullptr||k<1)
            return nullptr;
         ListNode* cur=pListHead;
         int count=0;
        while(cur)
        {
            count++;
            cur=cur->next;
        }
        if(count<k)
            return nullptr;
        ListNode* slow=pListHead;
        ListNode* fast=slow;
        while(--k)//先让快指针走k-1步
        {
            fast=fast->next;
        }
        while(fast->next)//此时，让快慢指针同时走，当fst走到最后一个结点时，slow结点就是倒数第k个
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};


方法2：
思路：使用Stack，将所有结点压入栈中，因为栈满足先进后出，所以取出栈中的第k个就是倒数第k个结点；

