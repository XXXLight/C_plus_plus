// 对while退出条件要深入理解
// 学会自己写测试用例

//  链表创建
//	链表的查找都必须从头开始，找到了才能定位
//	破坏链表的结构都是破坏左边的指针

//生成链表节点
#include<bits/stdc++.h>
using namespace std;

//链表节点的定义
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

// 链表遍历转vector
vector<int> listToVec(ListNode* head) {
	vector<int> res;
	while (head) {
		res.push_back(head->val);
		head = head->next;
	}
	return res;
}

// vector合并成链表
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