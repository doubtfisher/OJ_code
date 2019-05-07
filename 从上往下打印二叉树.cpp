
//��Ŀ���������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��

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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		queue<TreeNode*> q;
		vector<int> v;
		if (root == nullptr)
			return v;

		q.push(root);
		while (!q.empty())
		{
			TreeNode* top = q.front();
			v.push_back(top->val);
			q.pop();
			if (top->left != nullptr)
			{
				q.push(top->left);
			}
			if (top->right != nullptr)
			{
				q.push(top->right);
			}
		}
		return v;

	}
};