#include<bits/stdc++.h>
using namespace std;

//链表节点的定义
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* change(vector<int>&v) {
		ListNode* h = new ListNode(-1);
		ListNode* p = h;
		for (auto e : v) {
			ListNode* tmp = new ListNode(e);
			p->next = tmp;
			p = p->next;
		}
		return h->next;
	}
	ListNode* oddEvenList(ListNode* head) {
		vector<int> v;
		while (head) {
			v.push_back(head->val);
			head = head->next;
		}
		vector<int> odd, even;
		for (int i = 0; i < v.size(); i++) {
			if (i & 1) odd.push_back(v[i]);
			else even.push_back(v[i]);
		}
		vector<int> res;
		for (auto e : even) res.push_back(e);
		for (auto e : odd) res.push_back(e);
		ListNode* r = change(res);
		return r;
	}
};