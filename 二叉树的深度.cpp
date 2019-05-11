题目：
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

方法1：递归方法
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==nullptr)
            return 0;
        
        int left=TreeDepth(pRoot->left);
        int right=TreeDepth(pRoot->right);
        
        return left > right ? left+1:right+1;
    }
};

方法2：非递归

class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
      queue<TreeNode*> q;
      if(pRoot==nullptr)
            return 0;
        int height=0;
       q.push(pRoot);
        while(!q.empty())
        {
            height++;
            int size=q.size();
            while(size--)
            {
                TreeNode* top=q.front();
                q.pop();
                if(top->left!=nullptr)
                {
                    q.push(top->left);
                }
                if(top->right!=nullptr)
                {
                    q.push(top->right);
                }
            }
          }
        return height;
      }
};