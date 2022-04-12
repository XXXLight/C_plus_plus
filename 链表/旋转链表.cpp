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
	ListNode* rotateRight(ListNode* head, int k) {
		if (k == 0 || head == nullptr || head->next == nullptr) {
			return head;
		}
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		// cnt计算链表元素个数
		int cnt = 0;
		while (head) {
			head = head->next;
			cnt++;
		}
		// 此时head已破坏，不能return head
		if (k%cnt == 0) return dummy->next;
		k %= cnt;
		ListNode* pre1 = dummy;
		for (int i = 0; i < cnt - k; i++) {
			pre1 = pre1->next;
		}//pre1为第一个断开点
		ListNode* newHead = pre1->next;
		//cout << pre1->val << endl;
		pre1->next = nullptr;

		ListNode* tail = newHead;
		for (int i = 0; i < k - 1; i++) {
			tail = tail->next;
		}
		//cout << tail->val << endl;
		tail->next = dummy->next;
		return newHead;
	}
};

// 建议写成while格式
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		// k=0没有旋转，一个元素或没有元素转了没用
		if (k == 0 || head == nullptr || head->next == nullptr) {
			return head;
		}
		// 哑节点
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		// 求节点个数
		ListNode* pre = head;
		int cnt = 0;
		while (pre) { pre = pre->next; cnt++; }
		k %= cnt;
		if (k == 0) return head; //提前检查
		// 起点：哑节点， 步数cnt-k
		pre = dummy;
		int dis1 = cnt - k;
		while (dis1--) pre = pre->next;

		ListNode* newHead = pre->next;
		pre->next = nullptr;
		// 起点，步数k-1
		ListNode* st = newHead;
		int dis2 = k - 1;
		while (dis2--) st = st->next;
		st->next = dummy->next;
		return newHead;
	}
};