
//题目：从上往下打印出二叉树的每个节点，同层节点从左至右打印。

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