//��Ŀ��
//����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��;
//����������Yes,�������No���������������������������ֶ�������ͬ��

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
			if (sequence[i]>root)//��������һ����һ���ڵ���ڸ��ڵ㣬˵�������������ĵ�һ���ڵ�
			{
				break;
			}
		}

		int j = i;
		for (j = i; j<end; j++)
		{
			if (sequence[j]<root)//���������У����������һ���ڵ�ȸ��ڵ�С���򲻴��������Ķ���������
			{
				return false;
			}
		}

		bool left = true, right = true;
		//�ݹ��ж�������
		if (i>start)
		{
			left = BST(sequence, start, i - 1);
		}
		//�ݹ��ж�������  
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