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
	ListNode* rotateRight(ListNode* head, int k) {
		if (k == 0 || head == nullptr || head->next == nullptr) {
			return head;
		}
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		// cnt��������Ԫ�ظ���
		int cnt = 0;
		while (head) {
			head = head->next;
			cnt++;
		}
		// ��ʱhead���ƻ�������return head
		if (k%cnt == 0) return dummy->next;
		k %= cnt;
		ListNode* pre1 = dummy;
		for (int i = 0; i < cnt - k; i++) {
			pre1 = pre1->next;
		}//pre1Ϊ��һ���Ͽ���
		ListNode* newHead = pre1->next;
		//cout << pre1->val << endl;
		pre1->next = nullptr;

		ListNode* tail = newHead;
		for (int i = 0; i < k - 1; i++) {
			tail = tail->next;
		}
		//cout << tail->val << endl;
		tail->next = dummy->next;
		return newHead;
	}
};

// ����д��while��ʽ
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		// k=0û����ת��һ��Ԫ�ػ�û��Ԫ��ת��û��
		if (k == 0 || head == nullptr || head->next == nullptr) {
			return head;
		}
		// �ƽڵ�
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		// ��ڵ����
		ListNode* pre = head;
		int cnt = 0;
		while (pre) { pre = pre->next; cnt++; }
		k %= cnt;
		if (k == 0) return head; //��ǰ���
		// ��㣺�ƽڵ㣬 ����cnt-k
		pre = dummy;
		int dis1 = cnt - k;
		while (dis1--) pre = pre->next;

		ListNode* newHead = pre->next;
		pre->next = nullptr;
		// ��㣬����k-1
		ListNode* st = newHead;
		int dis2 = k - 1;
		while (dis2--) st = st->next;
		st->next = dummy->next;
		return newHead;
	}
};