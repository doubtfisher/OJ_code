��Ŀ��
�ϲ�?k?�������������غϲ������������������������㷨�ĸ��Ӷȡ�

ʾ��:
����:
[
? 1->4->5,
? 1->3->4,
? 2->6
]
���: 1->1->2->3->4->4->5->6

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         multimap<int,ListNode*> map;
        for(const auto& e:lists)
        {
            if(e!=nullptr)
                map.insert(pair<int, ListNode*>(e->val, e));
        }
        ListNode head(0);
        ListNode* tail=&head;
        while(!map.empty())
        {
            multimap<int,ListNode*>::iterator it=map.begin();
            tail->next=it->second;
            tail=tail->next;
            if(it->second->next!=nullptr)
                map.insert(pair<int, ListNode*>(it->second->next->val,it->second->next));//��ֹ������ʧЧ
            map.erase(it); 
        }
        tail->next=nullptr;
        return head.next;
    }
};


��������ֱ��ȫ��������������Ȼ��������һ��ͺ���
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         vector<ListNode*> v;
        for (ListNode* e:lists)
        {
            ListNode* ptr = e;
             while (ptr != nullptr)
             {
                 v.push_back(ptr);
                 ptr = ptr->next;
             }
        }
    std::sort(v.begin(),v.end(),[](ListNode* x,ListNode* y){return ((x->val) < (y->val));});//ʹ��lambda���ʽ�Խڵ��������
        
    if (v.size() ==0)
    {
        return nullptr;
    }
        
    for (size_t i=0;i<v.size()-1;i++)
    {
        v[i]->next = v[i+1];
    }
    v[v.size()-1]->next = nullptr;
        
    return v[0];
    }
};

