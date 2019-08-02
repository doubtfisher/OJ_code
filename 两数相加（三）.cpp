题目：
给出两个?非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照?逆序?的方式存储的，并且它们的每个节点只能存储?一位?数字。如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。


思路分析：
不对齐补零，若链表不为空则用sum(代表每个位的和的结果)加上，考虑进位。

代码实现：

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
        ListNode* head=new ListNode(-1);//存放最终结果的链表
        ListNode* cur=head;//向后移动的指针
        int sum=0;//每一位相加的和
        bool next=false;//进位
        while(l1!=nullptr||l2!=nullptr)
        {
            sum=0;//每次进来，sum都要置为0
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
