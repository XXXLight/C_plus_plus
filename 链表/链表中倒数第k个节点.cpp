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
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode *fast = head, *slow = head;
		while (k--) fast = fast->next;
		while (fast) {
			fast = fast->next;
			slow = slow->next;
		}
		// 此时不满足循环条件 fast==nullptr
		return slow;
	}
};


// 开内存存储结果
class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		vector<ListNode*> res;
		while (head) {
			res.push_back(head);
			head = head->next;
		}
		return res[res.size() - k];
	}
};