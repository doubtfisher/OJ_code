题目：删除链表中等于给定值 val 的所有节点。

代码实现：
（1）在原链表修改
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)
            return head;
            
        struct ListNode* cur=head;
        struct ListNode* prev=nullptr;
        while(cur)
        {
            if(cur->val != val)
            {
                 prev = cur;
                 cur=cur->next; 
            }
            else
            {
                ListNode* next=cur->next;
                if(prev==nullptr)//有可能第一个数就是需要删除的数字
                    head=cur->next;
                else
                {
                    prev->next=cur->next;
                }
                delete cur;
                cur=next;
            }         
        }
        return head;
}

（2）将不需要删除的元素添加到新链表
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* l=new ListNode(-1);//头节点
        ListNode *l1=l;//向后走
        while(head)
        {
            if(head->val==val)
            {
                head=head->next;
            }
            else
            {
                ListNode* p=new ListNode(head->val);
                l1->next=p;
                l1=l1->next;
                head=head->next;
            }
        }
        return l->next;
    }
};




