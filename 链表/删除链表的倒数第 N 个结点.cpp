#include<bits/stdc++.h>
using namespace std;

//链表节点的定义
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


// 链表的查找必须从头开始
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		// 计算链表节点个数
		int cnt = 0;
		ListNode* cur = head;
		while (cur) {
			cur = cur->next;
			cnt++;
		}
		// 删除第一个节点
		if (n == cnt) return head->next;
		// 找到被删除节点的前一个节点
		cur = head;// 查找必须从头开始
		for (int i = 0; i < cnt - n - 1; i++) {
			cur = cur->next;
		}
		cur->next = cur->next->next;
		return head;
	}
};