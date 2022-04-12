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
	bool check(vector<int>& v, int l, int r) {
		for (int i = l, j = r; i < j; i++, j--) {
			if (v[i] != v[j]) return false;
		}
		return true;
	}
	vector<int> listToVec(ListNode* head) {
		vector<int> res;
		while (head) {
			res.push_back(head->val);
			head = head->next;
		}
		return res;
	}

	bool isPalindrome(ListNode* head) {
		vector<int> r = listToVec(head);
		int low = 0, high = r.size() - 1;
		while (low < high) {
			int c1 = r[low], c2 = r[high];
			if (c1 == c2) {
				++low, --high;
			}
			else {
				return check(r, low, high - 1) || check(r, low + 1, high);
			}
		}
		return true;
	}
};