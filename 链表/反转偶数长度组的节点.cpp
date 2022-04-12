#include<bits/stdc++.h>
using namespace std;

//链表节点的定义
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



// 所有的链表题的一个思路是：将链表取出来放到数组里，对数组进行操作，再重建链表并返回结果
class Solution {
public:
	ListNode* reverseEvenLengthGroups(ListNode* head) {
		vector<int> v;
		ListNode *p = head;
		while (p != nullptr) {
			v.emplace_back(p->val);
			p = p->next;
		}
		int n = v.size();
		int i = 0, g = 1;
		while (i < n) {
			if (g > n - i)
				g = n - i;
			if (g % 2 == 0)
				reverse(v.begin() + i, v.begin() + i + g);
			i += g;
			g++;
		}

		ListNode *sen = new ListNode();
		p = sen;
		for (int vi : v) {
			p->next = new ListNode(vi);
			p = p->next;
		}

		return sen->next;
	}
};


class Solution {
public:
	ListNode* reverseEvenLengthGroups(ListNode* head) {
		vector<int> vs;
		for (auto* node = head; node != nullptr; node = node->next) {
			vs.push_back(node->val);
		}
		for (int i = 0, cnt = 1; i < vs.size(); i += cnt++) {
			int j = min(int(vs.size()) - i, cnt);
			if (j % 2 == 0) {
				reverse(vs.begin() + i, vs.begin() + i + j);
			}
		}
		int idx = 0;
		for (auto* node = head; node != nullptr; node = node->next, ++idx) {
			node->val = vs[idx];
		}
		return head;
	}
};