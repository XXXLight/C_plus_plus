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
	ListNode* middleNode(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;
		// ע�������&&fast->next��Ϊ��ȷ����������´���ȷ
		// ��������ż����while(fast)����
		while (fast&&fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}
};