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
	ListNode* sortList(ListNode* head) {
		return sortList(head, nullptr);
	}
	ListNode* sortList(ListNode* head, ListNode* tail) {
		if (head == nullptr) {
			return head;
		}
		if (head->next == tail) {
			head->next = nullptr;
			return head;
		}
		ListNode* slow = head, *fast = head;
		while (fast != tail) {
			slow = slow->next;
			fast = fast->next;
			if (fast != tail) {
				fast = fast->next;
			}
		}
		ListNode* mid = slow;
		return merge(sortList(head, mid), sortList(mid, tail));
	}
	ListNode* merge(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		if (l1->val < l2->val) {
			l1->next = merge(l1->next, l2);
			return l1;
		}
		else {
			l2->next = merge(l2->next, l1);
			return l2;
		}
	}
};