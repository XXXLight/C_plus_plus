#include<bits/stdc++.h>
using namespace std;

//����ڵ�Ķ���
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// ע�����ֱ�ʾɾ���������м�ģ����Բ���Ա߽�Ľڵ㿼��
class Solution {
public:
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
	}
};