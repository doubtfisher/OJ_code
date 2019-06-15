��Ŀ��
����һ������������������ ǰ�� ������


�ݹ�д����
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
public:
    void preorder(TreeNode* root,vector<int>& v)
    {
        if(root==nullptr)
            return;
        
        v.push_back(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preorder(root,v);
        
        return v;
    }
};

//�ǵݹ�д������ջ

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        TreeNode* cur=root;
        stack<TreeNode*> st;
        
        //��ʼ����һ����
        while(cur||!st.empty())
        {
            while(cur)
            {
                st.push(cur);
                v.push_back(cur->val);
                cur=cur->left;
            }
            TreeNode* top=st.top();
            st.pop();
            cur=top->right;
        }
        return v;
    }
};