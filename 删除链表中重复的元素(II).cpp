��Ŀ��
����һ����������ɾ�����к����ظ����ֵĽڵ㣬ֻ����ԭʼ������?û���ظ�����?�����֡�


ʾ��?1:


����: 1->2->3->3->4->4->5

���: 1->2->5

ʾ��?2:


����:
 1->1->1->2->3

���: 2->3



ʵ�ִ������£�

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
                if(prev!=nullptr)//���ǿ��ܵ�һ���ڵ㿪ʼ������ͬ�ģ������Ļ���head�ͻᷢ���仯
                    prev->next=next;
                else
                    head=next;
                //ɾ���ظ��Ľڵ�
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