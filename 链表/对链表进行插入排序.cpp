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
	ListNode* insertionSortList(ListNode* head) {
		// �����ƽڵ�dummy��ָ������ͷ��
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		// pre��λ��ͷ��������ҽڵ㣨������ұ����ͷ��ʼ��
		ListNode* pre = dummy;
		// LastSort����������ڵ��ĩβ�ڵ�
		ListNode* LastSort = head;
		// cur��ʾ������ڵ����һ���ڵ㣬Ҳ�������Ϊ��ǰ�ڵ�
		ListNode* cur = LastSort->next;
		while (cur) {
			if (LastSort->val <= cur->val) {
				// ���������ϵ��ĩβ��������ƶ�һλ���Ⱥ�Ҳ����
				LastSort = LastSort->next;
			}
			else {
				// ������ұ����ͷ�ڵ㿪ʼ
				pre = dummy;
				while (pre->next->val <= cur->val) {
					pre = pre->next;
				}
				// ��ʱpre->next > cur
				LastSort->next = cur->next;
				cur->next = pre->next;
				pre->next = cur;
			}
			// cur��ʾ������ڵ����һ���ڵ㣬Ҳ�������Ϊ��ǰ�ڵ�
			cur = LastSort->next;
		}
		return dummy->next;
	}
};



class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;

		ListNode* LastSorted = head;
		ListNode* cur = LastSorted->next;
		while (cur) {
			if (cur->val >= LastSorted->val) {
				LastSorted = cur;
			}
			else {
				// ���������仯�����ܹ��ص��ýڵ���в���
				pre = dummy;
				while (pre->next->val < cur->val) {
					pre = pre->next;
				}
				// �ƻ��Ķ�����ߵ�����ṹ
				LastSorted->next = cur->next;
				cur->next = pre->next;
				pre->next = cur;
			}
			cur = LastSorted->next;
		}
		return dummy->next;
	}
};


// ţ����ֱ��ȡ��������
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		vector<int> v;
		while (head) {
			v.push_back(head->val);
			head = head->next;
		}
		sort(v.begin(), v.end());
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