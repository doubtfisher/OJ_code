��Ŀ��
����һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ����м��㡣

˼·���ÿ�ָ������������ָ����һ����

����ָ�����ʵ�֣�
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