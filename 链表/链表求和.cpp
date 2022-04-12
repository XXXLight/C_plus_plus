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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode* p1 = l1, *p2 = l2;
		ListNode* head = new ListNode(-1);
		ListNode* p = head;
		int sum;
		while (p1 || p2 || carry) {
			sum = 0;
			if (p1) { sum += p1->val; p1 = p1->next; }
			if (p2) { sum += p2->val; p2 = p2->next; }
			sum += carry;
			carry = sum / 10;
			int cur = sum % 10;
			ListNode* h = new ListNode(cur);
			p->next = h;
			p = p->next;
		}
		return head->next;
	}
};