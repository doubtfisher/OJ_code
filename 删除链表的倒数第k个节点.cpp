��Ŀ��
����һ����������������е�����k����㡣

˼·��
���ÿ�ָ����k����Ȼ�����ÿ���ָ��ͬʱ�ߣ�����ָ���ߵ����һ���ڵ�ʱ��slow����һ���ڵ����Ҫɾ���Ľڵ㡣

����ʵ�֣�

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = nullptr;
        int i = 0;
        while(fast)
        {
            if(i==n)//����fast��n��
                break;
            ++i;
            fast = fast->next;
        }
       
        if(i==n &&fast==nullptr) 
            return head->next; //ɾ����ͷ���
        
        if(i!=n)  //���ʵ�ʴ�while���������������˵��Ҫɾ���ĵ�����n���������ڣ�ֱ�ӷ���ͷ���
            return head; 
        
        slow = head;
        while(fast->next)//����ж�fast��Ϊ�յĻ������Ҫɾ���Ľڵ���
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        return head;
    }
};

����2������ָ��
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
            else//n���ڽ�����
                return head;
        }
        while(fast)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        if(prev==nullptr)//ɾ������ͷ���
            head=slow->next;
        else
            prev->next=slow->next;
        return head;
    }
};