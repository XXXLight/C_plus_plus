#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//链表节点的定义
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		stack<int> st;
		while (head) {
			st.push(head->val);
			head = head->next;
		}
		vector<int> res;
		while (!st.empty()) {
			res.push_back(st.top());
			st.pop();
		}
		return res;
	}
};