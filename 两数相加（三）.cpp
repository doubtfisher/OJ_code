��Ŀ��
��������?�ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ���?����?�ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢?һλ?���֡���������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�


˼·������
�����벹�㣬������Ϊ������sum(����ÿ��λ�ĺ͵Ľ��)���ϣ����ǽ�λ��

����ʵ�֣�

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {     
        ListNode* head=new ListNode(-1);//������ս��������
        ListNode* cur=head;//����ƶ���ָ��
        int sum=0;//ÿһλ��ӵĺ�
        bool next=false;//��λ
        while(l1!=nullptr||l2!=nullptr)
        {
            sum=0;//ÿ�ν�����sum��Ҫ��Ϊ0
            if(l1!=nullptr)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            if(next)//
                sum+=1;
            
            cur->next=new ListNode(sum%10);
            cur=cur->next;
            next=sum>=10?true:false;
        }
        if(next)
        {
            cur->next=new ListNode(1);
        } 
        return head->next;
    }
};
