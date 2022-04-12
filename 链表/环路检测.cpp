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
	unordered_map<ListNode*, bool> mp;
	ListNode *detectCycle(ListNode *head) {
		while (head) {
			mp[head] = true;
			head = head->next;
			if (mp[head] == true) return head;
		}
		return nullptr;
	}
};