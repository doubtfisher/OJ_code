//��Ŀ��
//����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�ע�⣬���еĽ�㲻��//���������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣


struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;//ָ�򸸽ڵ��ָ��
    
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==nullptr)
        {
            return pNode;
        }
        TreeLinkNode* nextNode=nullptr;
        if(pNode->right!=nullptr)//�����ǰ�ڵ���ҽڵ㲻Ϊ�գ��Ҹ��ҽڵ����Ϊ��ʱ������ҽڵ������Ƕ����������������һ���ڵ㡣
        {
            TreeLinkNode* rightNode=pNode->right;
            if(rightNode->left!=nullptr)
            {
                 rightNode=rightNode->left;
            }
            nextNode=rightNode;
        }
        else if(pNode->next!=nullptr)//��ǰ�ڵ���ҽڵ�Ϊ��ʱ���򸸽ڵ��������ϱ�����
        {
            TreeLinkNode* currentNode=pNode;
            TreeLinkNode* parentNode=currentNode->next;
            while(parentNode!=nullptr && currentNode!=parentNode->left)
            {
                currentNode=parentNode;
                parentNode=parentNode->next;
            }
            nextNode=parentNode;
        }
        return nextNode;
    }
};
