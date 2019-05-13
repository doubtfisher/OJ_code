 //��Ŀ��
 //����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ��//�� �������ظ������֡���������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ���//���������ء�


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
        //�ݹ鹹��������
        (*pindex)++;
        if(begin<=rootindex)
        {
            root->left=_reConstructBinaryTree(pre,pindex,vin,begin,rootindex-1);  
        }
        //�ݹ鹹��������
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