#include<bits/stdc++.h>
using namespace std;

//链表节点的定义
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// 开了三个指针 pre curr nextp
// 平移一步         pre  curr   nextp
// 理解吧！！！当然是理解为王！！！！
// 时间复杂度：o(n) 空间复杂度：o(1)
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
};


//时间复杂度：O(n),其中 n 是链表的长度。需要对链表的每个节点进行反转操作。
//空间复杂度：O(n)，其中 n 是链表的长度。空间复杂度主要取决于递归调用的栈空间，最多为 n 层。
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) {
			return head;
		}
		ListNode* newHead = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return newHead;
	}
};


class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		vector<int> v;
		while (head) {
			v.push_back(head->val);
			head = head->next;
		}
		for (int i = 0, j = v.size() - 1; i < j; i++, j--) swap(v[i], v[j]);
		ListNode* h = new ListNode(-1);
		ListNode* p = h;
		for (int i = 0; i < v.size(); i++) {
			ListNode* tmp = new ListNode(v[i]);
			p->next = tmp;
			p = p->next;
		}
		return h->next;
	}
};