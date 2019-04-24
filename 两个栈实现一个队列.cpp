#include <iostream>
#include <stack>
using namespace std;
//˼·��
//��ӣ���Ԫ�ؽ�ջA
//���ӣ��ж�ջB�Ƿ�Ϊ�գ����Ϊ�գ���ջA������Ԫ��pop����push��ջB��ջB��ջ�������Ϊ�գ�ջBֱ�ӳ�ջ��

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	//���ջ2Ϊ����ջ1��Ϊ��ʱ���Ͱ�ջ1������ݲ��뵽ջ2������ٵ���ջ��Ԫ��
	int pop() {
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				int top = stack1.top();
				stack2.push(top);
				stack1.pop();
			}
		}
		int ret = stack2.top();
		stack2.pop();
		return ret;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};