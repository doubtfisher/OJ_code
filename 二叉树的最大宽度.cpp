��Ŀ��
����һ������������дһ����������ȡ�����������ȡ����Ŀ�������в��е�����ȡ����������������������full binary tree���ṹ��ͬ����һЩ�ڵ�Ϊ�ա�

ÿһ��Ŀ�ȱ�����Ϊ�����˵㣨�ò���������ҵķǿսڵ㣬���˵���null�ڵ�Ҳ���볤�ȣ�֮��ĳ��ȡ�

˼·��˫�˶���+�������

����ʵ�֣�

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
        int ret=0;//�����
        deque<TreeNode*> dq;//����һ��˫�˶���
        TreeNode* tmp=nullptr;
        if(root==nullptr)
            return 0;
        dq.push_back(root);
        while(!dq.empty())
        {
            //1.ɾ������Ϊ�յĽ��
            while(!dq.empty()&&dq.front()==nullptr)//ɾ��ͷ��Ϊ�յĽ��
                dq.pop_front();
            while(!dq.empty()&&dq.back()==nullptr)//ɾ��β��Ϊ�յĽ��
                dq.pop_back();
            int n=dq.size();
            if(n==0)//���һ�������Ϊ0
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