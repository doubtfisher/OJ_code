��Ŀ��ɾ�������е��ڸ���ֵ val �����нڵ㡣

����ʵ�֣�
��1����ԭ�����޸�
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
                if(prev==nullptr)//�п��ܵ�һ����������Ҫɾ��������
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

��2��������Ҫɾ����Ԫ����ӵ�������
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* l=new ListNode(-1);//ͷ�ڵ�
        ListNode *l1=l;//�����
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




