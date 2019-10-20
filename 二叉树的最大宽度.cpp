题目：
给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。

每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。

思路：双端队列+层序遍历

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
    int widthOfBinaryTree(TreeNode* root) {
        int ret=0;//最大宽度
        deque<TreeNode*> dq;//定义一个双端队列
        TreeNode* tmp=nullptr;
        if(root==nullptr)
            return 0;
        dq.push_back(root);
        while(!dq.empty())
        {
            //1.删除两边为空的结点
            while(!dq.empty()&&dq.front()==nullptr)//删除头部为空的结点
                dq.pop_front();
            while(!dq.empty()&&dq.back()==nullptr)//删除尾部为空的结点
                dq.pop_back();
            int n=dq.size();
            if(n==0)//最后一层结点个数为0
                break;
            ret=max(ret,n);
            for(int i=0;i<n;i++)
            {
                tmp=dq.front();
                dq.pop_front();
                if(tmp)
                {
                    dq.push_back(tmp->left);
                    dq.push_back(tmp->right);
                }
                else
                {
                    dq.push_back(nullptr);
                    dq.push_back(nullptr);
                }
            }
        }
        return ret;   
    }
};