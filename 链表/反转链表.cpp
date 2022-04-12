#include<bits/stdc++.h>
using namespace std;

//����ڵ�Ķ���
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// ��������ָ�� pre curr nextp
// ƽ��һ��         pre  curr   nextp
// ���ɣ�������Ȼ�����Ϊ����������
// ʱ�临�Ӷȣ�o(n) �ռ临�Ӷȣ�o(1)
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = NULL;
		ListNode* curr = head;
		while (curr) {
			ListNode* nextp = curr->next;
			curr->next = pre;
			pre = curr;
			curr = nextp;
		}
		// ��ʱcurr=nullptr,�ʷ���pre��������ѭ�������ˣ�
		return pre;
	}
};


//ʱ�临�Ӷȣ�O(n),���� n ������ĳ��ȡ���Ҫ�������ÿ���ڵ���з�ת������
//�ռ临�Ӷȣ�O(n)������ n ������ĳ��ȡ��ռ临�Ӷ���Ҫȡ���ڵݹ���õ�ջ�ռ䣬���Ϊ n �㡣
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) {
			return head;
		}
		ListNode* newHead = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return newHead;
	}
};


class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		vector<int> v;
		while (head) {
			v.push_back(head->val);
			head = head->next;
		}
		for (int i = 0, j = v.size() - 1; i < j; i++, j--) swap(v[i], v[j]);
		ListNode* h = new ListNode(-1);
		ListNode* p = h;
		for (int i = 0; i < v.size(); i++) {
			ListNode* tmp = new ListNode(v[i]);
			p->next = tmp;
			p = p->next;
		}
		return h->next;
	}
};