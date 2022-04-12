// ��while�˳�����Ҫ�������
// ѧ���Լ�д��������

//  ������
//	����Ĳ��Ҷ������ͷ��ʼ���ҵ��˲��ܶ�λ
//	�ƻ�����Ľṹ�����ƻ���ߵ�ָ��

//��������ڵ�
#include<bits/stdc++.h>
using namespace std;

//����ڵ�Ķ���
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* vectorToListNode(vector<int>& list) {

	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for (int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

int main() {
	ListNode* head = new ListNode(-1);
	ListNode* p = head;
	for (int i = 0; i < 9; i++) {
		ListNode* tmp = new ListNode(i);
		p->next = tmp;
		p = p->next;
	}
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}

// �������תvector
vector<int> listToVec(ListNode* head) {
	vector<int> res;
	while (head) {
		res.push_back(head->val);
		head = head->next;
	}
	return res;
}

// vector�ϲ�������
ListNode* change(vector<int>&v) {
	ListNode* h = new ListNode(-1);
	ListNode* p = h;
	for (auto e : v) {
		ListNode* tmp = new ListNode(e);
		p->next = tmp;
		p = p->next;
	}
	return h->next;
}