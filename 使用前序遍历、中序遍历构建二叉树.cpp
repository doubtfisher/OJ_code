 //题目：
 //输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果//中 都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二//叉树并返回。


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* _reConstructBinaryTree(vector<int> pre,int* pindex,vector<int> vin,int begin,int end)
    {
        if(begin>end)
            return nullptr;
        
        struct TreeNode* root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val=pre[*pindex];
        int rootindex=begin;
        for(rootindex=begin;rootindex<end;rootindex++)
        {
            if(vin[rootindex]==root->val)
            {
                break;
            }
        }
        //递归构建左子树
        (*pindex)++;
        if(begin<=rootindex)
        {
            root->left=_reConstructBinaryTree(pre,pindex,vin,begin,rootindex-1);  
        }
        //递归构建右子树
         if(rootindex<=end)
        {
             root->right=_reConstructBinaryTree(pre,pindex,vin,rootindex+1,end);  
        }
        
        return root;
    }
    
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
    {
        if(pre.size()==0 && vin.size()==0)
            return nullptr;
        
        int index=0;
        struct TreeNode* root=_reConstructBinaryTree(pre,&index,vin,0,vin.size()-1);
        
        return root;
    }
};