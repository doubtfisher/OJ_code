#include <iostream>
#include <stack>
using namespace std;
//思路：
//入队：将元素进栈A
//出队：判断栈B是否为空，如果为空，则将栈A中所有元素pop，并push进栈B，栈B出栈；如果不为空，栈B直接出栈。

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	//如果栈2为空且栈1不为空时，就把栈1里的数据插入到栈2，最后再弹出栈顶元素
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