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
	int kthToLast(ListNode* head, int k) {
		ListNode *fast = head, *slow = head;
		while (k--) {
			fast = fast->next;
		}
		while (fast != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}
		// ��ʱ�˳�ѭ�� fast==nullptr
		return slow->val;
	}
};

// ���ռ�洢���
class Solution {
public:
	int kthToLast(ListNode* head, int k) {
		vector<int> res;
		while (head) {
			res.push_back(head->val);
			head = head->next;
		}
		return res[res.size() - k];
	}
};