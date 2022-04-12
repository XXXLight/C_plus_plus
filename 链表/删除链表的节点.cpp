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
	ListNode* deleteNode(ListNode* head, int val) {
		if (head == nullptr) return nullptr;
		if (head->val == val) return head->next;
		ListNode* l = head;
		while (l->next&&l->next->val != val) {
			l = l->next;
		}

		// 此时l->next->val==val，表示这个节点是前一个节点
		l->next = l->next->next;
		return head;
	}
};