#include<bits/stdc++.h>
using namespace std;

//����ڵ�Ķ���
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


// ����Ĳ��ұ����ͷ��ʼ
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		// ��������ڵ����
		int cnt = 0;
		ListNode* cur = head;
		while (cur) {
			cur = cur->next;
			cnt++;
		}
		// ɾ����һ���ڵ�
		if (n == cnt) return head->next;
		// �ҵ���ɾ���ڵ��ǰһ���ڵ�
		cur = head;// ���ұ����ͷ��ʼ
		for (int i = 0; i < cnt - n - 1; i++) {
			cur = cur->next;
		}
		cur->next = cur->next->next;
		return head;
	}
};