��Ŀ��
����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�

����1���ݹ鷽��
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

����2���ǵݹ�

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