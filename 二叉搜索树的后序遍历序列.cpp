//题目：
//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果;
//如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

class Solution {
public:
	bool BST(vector<int> sequence, int start, int end)
	{
		if (sequence.empty() || start>end)
			return false;

		int root = sequence[end];
		int i = 0;
		for (i = 0; i<end; i++)
		{
			if (sequence[i]>root)//左子树中一旦有一个节点大于根节点，说明它是右子树的第一个节点
			{
				break;
			}
		}

		int j = i;
		for (j = i; j<end; j++)
		{
			if (sequence[j]<root)//在右子树中，如果出现有一个节点比根节点小，则不存在这样的二叉搜索树
			{
				return false;
			}
		}

		bool left = true, right = true;
		//递归判断左子树
		if (i>start)
		{
			left = BST(sequence, start, i - 1);
		}
		//递归判断右子树  
		if (i<end - 1)
		{
			right = BST(sequence, i, end - 1);
		}

		return left&&right;
	}

	bool VerifySquenceOfBST(vector<int> sequence)
	{
		return BST(sequence, 0, sequence.size() - 1);
	}
};