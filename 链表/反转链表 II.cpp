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
	ListNode *reverseBetween(ListNode *head, int left, int right) {
		// ���� dummyNode ����һ�������һ������
		ListNode *dummyNode = new ListNode(-1);
		dummyNode->next = head;
		ListNode *pre = dummyNode;
		for (int i = 0; i < left - 1; i++) {
			pre = pre->next;
		}
		ListNode *cur = pre->next;
		ListNode *next;
		for (int i = 0; i < right - left; i++) {
			next = cur->next;
			cur->next = next->next;
			next->next = pre->next;
			pre->next = next;
		}
		return dummyNode->next;
	}
};


class Solution {
private:
	void reverseLinkedList(ListNode *head) {
		// Ҳ����ʹ�õݹ鷴תһ������
		ListNode *pre = nullptr;
		ListNode *cur = head;

		while (cur != nullptr) {
			ListNode *next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
	}

public:
	ListNode *reverseBetween(ListNode *head, int left, int right) {
		// ��Ϊͷ�ڵ��п��ܷ����仯��ʹ������ͷ�ڵ���Ա��⸴�ӵķ�������
		ListNode *dummyNode = new ListNode(-1);
		dummyNode->next = head;

		ListNode *pre = dummyNode;
		// �� 1 ����������ͷ�ڵ��� left - 1 �������� left �ڵ��ǰһ���ڵ�
		// ����д�� for ѭ�����������
		for (int i = 0; i < left - 1; i++) {
			pre = pre->next;
		}

		// �� 2 ������ pre ���� right - left + 1 �������� right �ڵ�
		ListNode *rightNode = pre;
		for (int i = 0; i < right - left + 1; i++) {
			rightNode = rightNode->next;
		}

		// �� 3 �����жϳ�һ����������ȡ����
		ListNode *leftNode = pre->next;
		ListNode *curr = rightNode->next;

		// ע�⣺�ж�����
		pre->next = nullptr;
		rightNode->next = nullptr;

		// �� 4 ����ͬ�� 206 �⣬��ת�����������
		reverseLinkedList(leftNode);

		// �� 5 �����ӻص�ԭ����������
		pre->next = rightNode;
		leftNode->next = curr;
		return dummyNode->next;
	}
};



class Solution {
public:
	// ��ת����ӿڷ�װ
	pair<ListNode*, ListNode*> reverse(ListNode* head) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = dummy->next;
		while (cur) {
			ListNode* nextp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nextp;
		}
		return { pre,dummy->next };
	}
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		// st stN ����Ĳ��Ҷ������ͷ��ʼ���ҵ��˲��ܶ�λ
		ListNode* st = dummy;
		int dis1 = left - 1;
		while (dis1--) st = st->next;
		ListNode* stN = st->next;
		// en enN ����Ĳ��Ҷ������ͷ��ʼ���ҵ��˲��ܶ�λ
		ListNode* en = dummy;
		int dis2 = right;
		while (dis2--) en = en->next;
		ListNode* enN = en->next;
		// ����Ͽ���
		st->next = nullptr;
		en->next = nullptr;
		pair<ListNode*, ListNode*> p = reverse(stN);
		// p.first�Ƿ��صĵ�һ��ֵ
		st->next = p.first;
		p.second->next = enN;
		return dummy->next;
	}
};