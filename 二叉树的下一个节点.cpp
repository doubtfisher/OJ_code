//题目：
//给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅//包含左右子结点，同时包含指向父结点的指针。


struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;//指向父节点的指针
    
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
        if(pNode->right!=nullptr)//如果当前节点的右节点不为空，且该右节点的左不为空时，则该右节点的左就是二叉树中序遍历的下一个节点。
        {
            TreeLinkNode* rightNode=pNode->right;
            if(rightNode->left!=nullptr)
            {
                 rightNode=rightNode->left;
            }
            nextNode=rightNode;
        }
        else if(pNode->next!=nullptr)//当前节点的右节点为空时，向父节点依次向上遍历·
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
