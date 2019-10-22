题目：
输入一个链表，输出该链表中倒数第k个结点。

思路：
先让快指针走k步，然后再让快慢指针同时走，当快指针走到最后一个节点时，slow的下一个节点就是要删除的节点。

代码实现：

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = nullptr;
        int i = 0;
        while(fast)
        {
            if(i==n)//先让fast走n步
                break;
            ++i;
            fast = fast->next;
        }
       
        if(i==n &&fast==nullptr) 
            return head->next; //删的是头结点
        
        if(i!=n)  //如果实际从while语句中跳出来，就说明要删除的倒数第n个数不存在，直接返回头结点
            return head; 
        
        slow = head;
        while(fast->next)//如果判断fast不为空的话，会把要删除的节点错过
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        return head;
    }
};

方法2：快慢指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr)
            return head;
        ListNode* prev=nullptr;
        ListNode* slow=head;
        ListNode* fast=slow;
        while(n--)
        {
            if(fast)
                fast=fast->next;
            else//n大于结点个数
                return head;
        }
        while(fast)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        if(prev==nullptr)//删除的是头结点
            head=slow->next;
        else
            prev->next=slow->next;
        return head;
    }
};