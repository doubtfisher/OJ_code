��Ŀ��
����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�


ʾ��?1:


����: 1->1->2

���: 1->2

ʾ��?2:


����: 1->1->2->3->3

���: 1->2->3




ʵ�ִ������£�

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur=head;//��ָ��
        if(cur==nullptr||cur->next==nullptr)
            return cur;
        ListNode* next=cur->next;//��ָ��
        while(next!=nullptr)
        {
            if(cur->val!=next->val)//ǰ��Ԫ�ز����
            {
                cur=next;
                next=next->next;
            }
            else//�ҵ��ظ�Ԫ��
            {
                cur->next=next->next;
                next=next->next;
            }
        }
        return head;
    }
};