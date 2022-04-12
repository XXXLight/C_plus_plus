#include<bits/stdc++.h>
using namespace std;

//链表节点的定义
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	void reorderList(ListNode* head) {
		vector<ListNode*> tmp;
		while (head) {
			tmp.push_back(head);
			head = head->next;
		}
		//	熟悉下面的while写法
		int i = 0, j = tmp.size() - 1;
		for (; i < j;) {
			tmp[i]->next = tmp[j];
			i++;
			if (i == j) break;
			tmp[j]->next = tmp[i];
			j--;
		}
		tmp[i]->next = nullptr;
	}
};


class Solution {
public:
	void reorderList(ListNode *head) {
		if (head == nullptr) {
			return;
		}
		vector<ListNode *> vec;
		ListNode *node = head;
		while (node != nullptr) {
			vec.emplace_back(node);
			node = node->next;
		}
		int i = 0, j = vec.size() - 1;
		while (i < j) {
			vec[i]->next = vec[j];
			i++;
			if (i == j) {
				break;
			}
			vec[j]->next = vec[i];
			j--;
		}
		vec[i]->next = nullptr;
	}
};
