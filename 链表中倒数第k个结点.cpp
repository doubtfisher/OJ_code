��Ŀ��
����һ����������������е�����k����㡣

��1������ָ�룺
�����ÿ�ָ����k-1����Ȼ�����ָ��ͬʱ�ߣ�����ָ���ߵ����һ���ڵ�ʱ��slowָ����ǵ�����K���ڵ㣻
�����ÿ�ָ����k����Ȼ�����ָ��ͬʱ�ߣ�����ָ���ߵ���ʱ��slowָ����ǵ�����K���ڵ㣻

����ʵ�֣�
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
        while(--k)//���ÿ�ָ����k-1��
        {
            fast=fast->next;
        }
        while(fast->next)//��ʱ���ÿ���ָ��ͬʱ�ߣ���fst�ߵ����һ�����ʱ��slow�����ǵ�����k��
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};


����2��
˼·��ʹ��Stack�������н��ѹ��ջ�У���Ϊջ�����Ƚ����������ȡ��ջ�еĵ�k�����ǵ�����k����㣻

