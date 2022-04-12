#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//����ڵ�Ķ���
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


// ��һ�������ڻ����ܣ����ٶȲ�϶�����������ͬ�ٶȿ϶�������

// ����һ������ָ��

// �������������һ��
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

// �������������һ��
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

// ����Ĳ�������һ��
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

// ����������ϣ��
class Solution {
public:
	bool hasCycle(ListNode *head) {
		// ������ַ
		unordered_map<ListNode*, int> mp;
		while (head) {
			mp[head]++;
			if (mp[head] >= 2) return true;
			head = head->next;
		}
		return false;
	}
};