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
	ListNode *reverseBetween(ListNode *head, int left, int right) {
		// 设置 dummyNode 是这一类问题的一般做法
		ListNode *dummyNode = new ListNode(-1);
		dummyNode->next = head;
		ListNode *pre = dummyNode;
		for (int i = 0; i < left - 1; i++) {
			pre = pre->next;
		}
		ListNode *cur = pre->next;
		ListNode *next;
		for (int i = 0; i < right - left; i++) {
			next = cur->next;
			cur->next = next->next;
			next->next = pre->next;
			pre->next = next;
		}
		return dummyNode->next;
	}
};


class Solution {
private:
	void reverseLinkedList(ListNode *head) {
		// 也可以使用递归反转一个链表
		ListNode *pre = nullptr;
		ListNode *cur = head;

		while (cur != nullptr) {
			ListNode *next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
	}

public:
	ListNode *reverseBetween(ListNode *head, int left, int right) {
		// 因为头节点有可能发生变化，使用虚拟头节点可以避免复杂的分类讨论
		ListNode *dummyNode = new ListNode(-1);
		dummyNode->next = head;

		ListNode *pre = dummyNode;
		// 第 1 步：从虚拟头节点走 left - 1 步，来到 left 节点的前一个节点
		// 建议写在 for 循环里，语义清晰
		for (int i = 0; i < left - 1; i++) {
			pre = pre->next;
		}

		// 第 2 步：从 pre 再走 right - left + 1 步，来到 right 节点
		ListNode *rightNode = pre;
		for (int i = 0; i < right - left + 1; i++) {
			rightNode = rightNode->next;
		}

		// 第 3 步：切断出一个子链表（截取链表）
		ListNode *leftNode = pre->next;
		ListNode *curr = rightNode->next;

		// 注意：切断链接
		pre->next = nullptr;
		rightNode->next = nullptr;

		// 第 4 步：同第 206 题，反转链表的子区间
		reverseLinkedList(leftNode);

		// 第 5 步：接回到原来的链表中
		pre->next = rightNode;
		leftNode->next = curr;
		return dummyNode->next;
	}
};



class Solution {
public:
	// 反转链表接口封装
	pair<ListNode*, ListNode*> reverse(ListNode* head) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = dummy->next;
		while (cur) {
			ListNode* nextp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nextp;
		}
		return { pre,dummy->next };
	}
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		// st stN 链表的查找都必须从头开始，找到了才能定位
		ListNode* st = dummy;
		int dis1 = left - 1;
		while (dis1--) st = st->next;
		ListNode* stN = st->next;
		// en enN 链表的查找都必须从头开始，找到了才能定位
		ListNode* en = dummy;
		int dis2 = right;
		while (dis2--) en = en->next;
		ListNode* enN = en->next;
		// 链表断开先
		st->next = nullptr;
		en->next = nullptr;
		pair<ListNode*, ListNode*> p = reverse(stN);
		// p.first是返回的第一个值
		st->next = p.first;
		p.second->next = enN;
		return dummy->next;
	}
};