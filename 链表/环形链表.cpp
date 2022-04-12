#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//链表节点的定义
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


// 举一反三：在环上跑，有速度差，肯定会相遇，相同速度肯定不相遇

// 方法一：快慢指针

// 快的两步，慢的一步
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == nullptr) return false;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast&&fast->next) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) return true;
		}
		return false;
	}
};

// 快的三步，慢的一步
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == nullptr) return false;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast&&fast->next&&fast->next->next) {
			fast = fast->next->next->next;
			slow = slow->next;
			if (fast == slow) return true;
		}
		return false;
	}
};

// 快的四步，慢的一步
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == nullptr) return false;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast&&fast->next&&fast->next->next&&fast->next->next->next) {
			fast = fast->next->next->next->next;
			slow = slow->next;
			if (fast == slow) return true;
		}
		return false;
	}
};

// 方法二：哈希表
class Solution {
public:
	bool hasCycle(ListNode *head) {
		// 键：地址
		unordered_map<ListNode*, int> mp;
		while (head) {
			mp[head]++;
			if (mp[head] >= 2) return true;
			head = head->next;
		}
		return false;
	}
};