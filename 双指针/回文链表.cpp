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
		vector<int> v;
		while (head) {
			v.push_back(head->val);
			head = head->next;
		}
		// 简单的双指针写法，首位走，不碰面
		// 回文的逻辑：所有的都要满足，所以有反例就退出
		for (int i = 0, j = v.size() - 1; i < j; i++, j--) {
			if (v[i] != v[j])
				return false;
		}
		return true;
	}
};