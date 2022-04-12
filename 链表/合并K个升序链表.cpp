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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l2->next, l1);
			return l2;
		}
	}
	// 理解函数意义：   merge 将区间[l,r]之间的链表合并，所以可以先将 [l,mid]之间的链表合并，再将[mid,r]之间的链表合并
	// 最后再将两个部分拼起来就行了
	ListNode* merge(vector <ListNode*> &lists, int l, int r) {
		if (l == r) return lists[l]; //
		if (l > r) return nullptr; //越界
		int mid = (l + r) >> 1;//二分区间
		return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		return merge(lists, 0, lists.size() - 1);
	}
};


// 顺序合并
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l2->next, l1);
			return l2;
		}
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *ans = nullptr;
		for (auto e : lists) {
			ans = mergeTwoLists(ans, e);
		}
		return ans;
	}
};
