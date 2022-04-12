#pragma once
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/*****************************************************************
链表节点定义以及相关算法
*****************************************************************/


//链表节点的定义
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 


//反转链表
ListNode* reverseList(ListNode* head) {
	ListNode* pre = NULL;
	ListNode* cur = head;
	while (cur != nullptr) {
		ListNode* nextp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nextp;
	}
	return pre;
}


//链表的中间结点 用快慢指针来做,画个图有助于真正理解
ListNode* middleNode(ListNode* head) {
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast&&fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;//快指针指向链表尾部，慢指针指向中间节点，如果有两个中间节点，返回第二个中间节点
}


//环形链表
bool hasCycle(ListNode *head) {
	if (head == nullptr) return false;
	ListNode* fast = head;//快慢指针都从起点开始跑
	ListNode* slow = head;
	while (fast&&fast->next) {//没有环快指针会先到达链表的节点
		fast = fast->next->next;//快的走两步
		slow = slow->next;//慢的走一步
		if (fast == slow) return true;//相遇就表示有环
	}
	return false;
}


//从尾到头打印链表
vector<int> reversePrint(ListNode* head) {
	vector<int> res;
	while (head) {//熟悉链表的遍历算法	while (head) head=head->next;
		res.push_back(head->val);
		head = head->next;
	}
	reverse(res.begin(), res.end());
	return res;
}


// 合并两个有序链表
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



//删除链表的倒数第N个节点，快慢指针，快指针先走n步，然后快慢一起走，直到快指针走到最后，
//要注意的是可能是要删除第一个节点，这个时候可以直接返回head -> next
ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (!head | !head->next) return NULL;
	ListNode * fast = head, *slow = head;
	for (int i = 0; i < n; i++) {
		fast = fast->next;
	}//快指针先走n步，这是两者距离是n
	if (!fast) {//长度不够n会越界，删除头节点即可
		return head->next;
	}

	while (fast->next) {
		fast = fast->next;//两者以相同的速度走，快指针到达链表末尾的时候，慢指针指向
		slow = slow->next;//倒数第n个位置，因为两者距离始终是n
	}
	slow->next = slow->next->next;//删除节点
	return head;
}
//以下是递归解法
//int cur = 0;
//ListNode* removeNthFromEnd(ListNode* head, int n) {
//	if (!head) return NULL;
//	head->next = removeNthFromEnd(head->next, n);
//	cur++;
//	if (n == cur) return head->next;
//	return head;
//}


//打印输出链表（非环形链表）
void print_linkedlist(ListNode* head) {
	while (head) {
		cout << head->val<<" ";
		head = head->next;
	}
}