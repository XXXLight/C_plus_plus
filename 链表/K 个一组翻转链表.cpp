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
	// ��תһ�����������ҷ����µ�ͷ��β
	pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
		ListNode* prev = tail->next;
		ListNode* p = head;
		while (prev != tail) {
			ListNode* nex = p->next;
			p->next = prev;
			prev = p;
			p = nex;
		}
		return { tail, head };
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = head;
		ListNode* pre = dummyNode;

		while (head) {
			ListNode* tail = pre;
			// �鿴ʣ�ಿ�ֳ����Ƿ���ڵ��� k
			for (int i = 0; i < k; ++i) {
				tail = tail->next;
				if (!tail) {
					return dummyNode->next;
				}
			}
			ListNode* nex = tail->next;
			// ������ C++17 ��д����Ҳ����д��
			// pair<ListNode*, ListNode*> result = myReverse(head, tail);
			// head = result.first;
			// tail = result.second;
			tie(head, tail) = myReverse(head, tail);
			// �����������½ӻ�ԭ����
			pre->next = head;
			tail->next = nex;
			pre = tail;
			head = tail->next;
		}

		return dummyNode->next;
	}
};


// ֱ��ȡ�����ٴ���Ҳ����
class Solution {
public:
	void reverseVec(vector<int>&v, int l, int r) {
		for (int i = l, j = r; i < j; i++, j--) swap(v[i], v[j]);
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		vector<int> res;
		while (head) {
			res.push_back(head->val);
			head = head->next;
		}
		int l, r;
		for (int i = 0; i < res.size(); i += k) {
			l = i, r = i + k - 1;
			if (res.size() % k != 0 && r >= res.size()) break;
			reverseVec(res, l, r);
		}
		ListNode* h = new ListNode(-1);
		ListNode* p = h;
		for (int i = 0; i < res.size(); i++) {
			ListNode* tmp = new ListNode(res[i]);
			p->next = tmp;
			p = p->next;
		}
		return h->next;
	}
};
