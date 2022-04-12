#pragma once
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/*****************************************************************
����ڵ㶨���Լ�����㷨
*****************************************************************/


//����ڵ�Ķ���
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 


//��ת����
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


//������м��� �ÿ���ָ������,����ͼ�������������
ListNode* middleNode(ListNode* head) {
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast&&fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;//��ָ��ָ������β������ָ��ָ���м�ڵ㣬����������м�ڵ㣬���صڶ����м�ڵ�
}


//��������
bool hasCycle(ListNode *head) {
	if (head == nullptr) return false;
	ListNode* fast = head;//����ָ�붼����㿪ʼ��
	ListNode* slow = head;
	while (fast&&fast->next) {//û�л���ָ����ȵ�������Ľڵ�
		fast = fast->next->next;//���������
		slow = slow->next;//������һ��
		if (fast == slow) return true;//�����ͱ�ʾ�л�
	}
	return false;
}


//��β��ͷ��ӡ����
vector<int> reversePrint(ListNode* head) {
	vector<int> res;
	while (head) {//��Ϥ����ı����㷨	while (head) head=head->next;
		res.push_back(head->val);
		head = head->next;
	}
	reverse(res.begin(), res.end());
	return res;
}


// �ϲ�������������
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



//ɾ������ĵ�����N���ڵ㣬����ָ�룬��ָ������n����Ȼ�����һ���ߣ�ֱ����ָ���ߵ����
//Ҫע����ǿ�����Ҫɾ����һ���ڵ㣬���ʱ�����ֱ�ӷ���head -> next
ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (!head | !head->next) return NULL;
	ListNode * fast = head, *slow = head;
	for (int i = 0; i < n; i++) {
		fast = fast->next;
	}//��ָ������n�����������߾�����n
	if (!fast) {//���Ȳ���n��Խ�磬ɾ��ͷ�ڵ㼴��
		return head->next;
	}

	while (fast->next) {
		fast = fast->next;//��������ͬ���ٶ��ߣ���ָ�뵽������ĩβ��ʱ����ָ��ָ��
		slow = slow->next;//������n��λ�ã���Ϊ���߾���ʼ����n
	}
	slow->next = slow->next->next;//ɾ���ڵ�
	return head;
}
//�����ǵݹ�ⷨ
//int cur = 0;
//ListNode* removeNthFromEnd(ListNode* head, int n) {
//	if (!head) return NULL;
//	head->next = removeNthFromEnd(head->next, n);
//	cur++;
//	if (n == cur) return head->next;
//	return head;
//}


//��ӡ��������ǻ�������
void print_linkedlist(ListNode* head) {
	while (head) {
		cout << head->val<<" ";
		head = head->next;
	}
}