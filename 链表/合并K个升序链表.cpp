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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l2->next, l1);
			return l2;
		}
	}
	// ��⺯�����壺   merge ������[l,r]֮�������ϲ������Կ����Ƚ� [l,mid]֮�������ϲ����ٽ�[mid,r]֮�������ϲ�
	// ����ٽ���������ƴ����������
	ListNode* merge(vector <ListNode*> &lists, int l, int r) {
		if (l == r) return lists[l]; //
		if (l > r) return nullptr; //Խ��
		int mid = (l + r) >> 1;//��������
		return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		return merge(lists, 0, lists.size() - 1);
	}
};


// ˳��ϲ�
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l2->next, l1);
			return l2;
		}
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *ans = nullptr;
		for (auto e : lists) {
			ans = mergeTwoLists(ans, e);
		}
		return ans;
	}
};
