��Ŀ��
��תһ��������

ʾ��:

����: 1->2->3->4->5->NULL
���: 5->4->3->2->1->NULL

����1��
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
            if(n3)//����n3��Ϊ��
                n3=n3->next;
        }
        return n1;
        
    }
};

����2��

����ʵ�֣�

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
