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
	bool isPalindrome(ListNode* head) {
		vector<int> vals;
		while (head != nullptr) {
			vals.emplace_back(head->val);
			head = head->next;
		}
		// 判断是否是回文的写法，真的简洁，绝了
		for (int i = 0, j = (int)vals.size() - 1; i < j; ++i, --j) {
			if (vals[i] != vals[j]) {
				return false;
			}
		}
		return true;
	}
};

