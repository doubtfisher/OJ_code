��Ŀ����������һ�ö��������жϸö������Ƿ���ƽ���������

class Solution {
public:
    int Height(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        
        int left_height=Height(root->left);
        int right_height=Height(root->right);
        
        return left_height>right_height?left_height+1:right_height+1;
    }
    
    bool IsBalanced_Solution(TreeNode* pRoot) {
         if(pRoot==nullptr)
             return true;
        
        int left=Height(pRoot->left);
        int right=Height(pRoot->right);
        return abs(left-right)< 2 
            &&IsBalanced_Solution(pRoot->left)
            &&IsBalanced_Solution(pRoot->right);
    }
};