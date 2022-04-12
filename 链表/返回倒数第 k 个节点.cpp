#include<bits/stdc++.h>
using namespace std;

//链表节点的定义
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// 快慢指针
class Solution {
public:
	int kthToLast(ListNode* head, int k) {
		ListNode *fast = head, *slow = head;
		while (k--) {
			fast = fast->next;
		}
		while (fast != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}
		// 此时退出循环 fast==nullptr
		return slow->val;
	}
};

// 开空间存储结果
class Solution {
public:
	int kthToLast(ListNode* head, int k) {
		vector<int> res;
		while (head) {
			res.push_back(head->val);
			head = head->next;
		}
		return res[res.size() - k];
	}
};