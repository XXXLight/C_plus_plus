#include<bits/stdc++.h>
using namespace std;

//����ڵ�Ķ���
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// ����ָ��
class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode *fast = head, *slow = head;
		while (k--) fast = fast->next;
		while (fast) {
			fast = fast->next;
			slow = slow->next;
		}
		// ��ʱ������ѭ������ fast==nullptr
		return slow;
	}
};


// ���ڴ�洢���
class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		vector<ListNode*> res;
		while (head) {
			res.push_back(head);
			head = head->next;
		}
		return res[res.size() - k];
	}
};