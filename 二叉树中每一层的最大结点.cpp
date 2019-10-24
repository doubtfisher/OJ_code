题目：
您需要在二叉树的每一行中找到最大的值。

示例：


输入: 

     
     1
       
   / \
      
  3   2
      
 / \   \  
    
5   3   9 


输出: [1, 3, 9]



思路：层序遍历+max值更新

代码实现：
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            int maxNum=INT_MIN;
            while(sz--)
            {
                TreeNode* front=q.front();
                q.pop();
                maxNum=max(maxNum,front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            ans.push_back(maxNum);
        }
        return ans;
    }
};