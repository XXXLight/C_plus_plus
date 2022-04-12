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
	ListNode* insertionSortList(ListNode* head) {
		// 创建哑节点dummy并指向链表头部
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		// pre定位到头部方便查找节点（链表查找必须从头开始）
		ListNode* pre = dummy;
		// LastSort代表已排序节点的末尾节点
		ListNode* LastSort = head;
		// cur表示已排序节点的下一个节点，也可以理解为当前节点
		ListNode* cur = LastSort->next;
		while (cur) {
			if (LastSort->val <= cur->val) {
				// 满足排序关系，末尾可以向后移动一位，等号也满足
				LastSort = LastSort->next;
			}
			else {
				// 链表查找必须从头节点开始
				pre = dummy;
				while (pre->next->val <= cur->val) {
					pre = pre->next;
				}
				// 此时pre->next > cur
				LastSort->next = cur->next;
				cur->next = pre->next;
				pre->next = cur;
			}
			// cur表示已排序节点的下一个节点，也可以理解为当前节点
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
				// 不管怎样变化，都能够回到该节点进行查找
				pre = dummy;
				while (pre->next->val < cur->val) {
					pre = pre->next;
				}
				// 破坏的都是左边的链表结构
				LastSorted->next = cur->next;
				cur->next = pre->next;
				pre->next = cur;
			}
			cur = LastSorted->next;
		}
		return dummy->next;
	}
};


// 牛批，直接取出来排序
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