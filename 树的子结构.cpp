题目：输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

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
    bool IsHasSubTree(TreeNode* rootA,TreeNode* rootB)
    {
        if(rootB==nullptr)
            return true;
        
        if(rootA==nullptr)
            return false;
        
         return rootA->val == rootB->val&&
               IsHasSubTree(rootA->left,rootB->left)&&
               IsHasSubTree(rootA->right,rootB->right);
    }
    
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
      if(pRoot1==nullptr)
          return false; 
        
      if(pRoot2== nullptr)
          return false;
        
       return  IsHasSubTree(pRoot1,pRoot2)||
               HasSubtree(pRoot1->left,pRoot2)||
               HasSubtree(pRoot1->right,pRoot2);
    }
};
