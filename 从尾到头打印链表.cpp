
//题目：从尾到头打印链表
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL){
	}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		stack<ListNode*> st;
		vector<int> v;
		ListNode* cur = head;
		while (cur != nullptr)
		{
			st.push(cur);
			cur = cur->next;
		}
		while (!st.empty())
		{
			ListNode* top = st.top();
			v.push_back(top->val);
			st.pop();
		}
		return v;
	}
};