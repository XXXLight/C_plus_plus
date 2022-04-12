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
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = NULL;
		ListNode* curr = head;
		while (curr) {
			ListNode* nextp = curr->next;
			curr->next = pre;
			pre = curr;
			curr = nextp;
		}
		// 此时curr=nullptr,故返回pre（不满足循环条件了）
		return pre;
	}
	void printList(ListNode* l1) {
		while (l1) {
			cout << l1->val << " ";
			l1 = l1->next;
		}
		cout << endl;
	}
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* L1 = reverseList(l1);
		ListNode* L2 = reverseList(l2);
		printList(L1);
		printList(L2);
		int carry = 0;
		ListNode* p1 = L1;
		ListNode* p2 = L2;
		// nullptr和-1是不一样的，-1会有next
		ListNode* dummy = new ListNode(-1);
		ListNode* p = dummy;
		while (p1 || p2 || carry) {
			int n1 = (p1 == nullptr) ? 0 : p1->val;
			int n2 = (p2 == nullptr) ? 0 : p2->val;
			int curSum = n1 + n2 + carry;
			carry = curSum / 10;
			int cur = curSum % 10;
			ListNode* tmp = new ListNode(cur);
			p->next = tmp;
			p = p->next;
			if (p1)p1 = p1->next;
			if (p2)p2 = p2->next;
		}
		ListNode* r = reverseList(dummy->next);
		return r;
	}
};