#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//链表节点的定义
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *node1 = headA;
		ListNode *node2 = headB;

		while (node1 != node2) {
			node1 = node1 != NULL ? node1->next : headB;
			node2 = node2 != NULL ? node2->next : headA;
		}
		// 此时node1==node2
		return node1;
	}
};


class Solution {
public:
	unordered_map<ListNode*, bool> mp;
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		while (headA) {
			mp[headA] = true;
			headA = headA->next;
		}
		while (headB) {
			if (mp.count(headB)) {
				return headB;
			}
			headB = headB->next;
		}
		return nullptr;
	}
};
