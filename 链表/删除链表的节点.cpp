#include<bits/stdc++.h>
using namespace std;

//����ڵ�Ķ���
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		if (head == nullptr) return nullptr;
		if (head->val == val) return head->next;
		ListNode* l = head;
		while (l->next&&l->next->val != val) {
			l = l->next;
		}

		// ��ʱl->next->val==val����ʾ����ڵ���ǰһ���ڵ�
		l->next = l->next->next;
		return head;
	}
};