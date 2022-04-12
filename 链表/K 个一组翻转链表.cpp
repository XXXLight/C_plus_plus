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
	// 翻转一个子链表，并且返回新的头与尾
	pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
		ListNode* prev = tail->next;
		ListNode* p = head;
		while (prev != tail) {
			ListNode* nex = p->next;
			p->next = prev;
			prev = p;
			p = nex;
		}
		return { tail, head };
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = head;
		ListNode* pre = dummyNode;

		while (head) {
			ListNode* tail = pre;
			// 查看剩余部分长度是否大于等于 k
			for (int i = 0; i < k; ++i) {
				tail = tail->next;
				if (!tail) {
					return dummyNode->next;
				}
			}
			ListNode* nex = tail->next;
			// 这里是 C++17 的写法，也可以写成
			// pair<ListNode*, ListNode*> result = myReverse(head, tail);
			// head = result.first;
			// tail = result.second;
			tie(head, tail) = myReverse(head, tail);
			// 把子链表重新接回原链表
			pre->next = head;
			tail->next = nex;
			pre = tail;
			head = tail->next;
		}

		return dummyNode->next;
	}
};


// 直接取出来再处理也可以
class Solution {
public:
	void reverseVec(vector<int>&v, int l, int r) {
		for (int i = l, j = r; i < j; i++, j--) swap(v[i], v[j]);
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		vector<int> res;
		while (head) {
			res.push_back(head->val);
			head = head->next;
		}
		int l, r;
		for (int i = 0; i < res.size(); i += k) {
			l = i, r = i + k - 1;
			if (res.size() % k != 0 && r >= res.size()) break;
			reverseVec(res, l, r);
		}
		ListNode* h = new ListNode(-1);
		ListNode* p = h;
		for (int i = 0; i < res.size(); i++) {
			ListNode* tmp = new ListNode(res[i]);
			p->next = tmp;
			p = p->next;
		}
		return h->next;
	}
};
