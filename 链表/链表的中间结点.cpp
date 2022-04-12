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
	ListNode* middleNode(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;
		// 注意这里的&&fast->next是为了确保计数情况下答案正确
		// 奇数个和偶数个while(fast)就行
		while (fast&&fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}
};