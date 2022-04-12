#include<bits/stdc++.h>
using namespace std;

//����ڵ�Ķ���
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
	// ����ջģ��
	vector<int> MonotonousStack(vector<int> &nums) {
		vector<int> res(nums.size());
		stack<int> st;
		int len = nums.size();
		for (int i = len - 1; i >= 0; i--) {
			while (!st.empty() && st.top() <= nums[i]) {
				st.pop();
			}
			res[i] = st.empty() ? 0 : st.top();
			st.push(nums[i]);
		}
		return res;
	}
	vector<int> nextLargerNodes(ListNode* head) {
		vector<int> v;
		while (head) {
			v.push_back(head->val);
			head = head->next;
		}
		vector<int> res = MonotonousStack(v);
		return res;
	}
};