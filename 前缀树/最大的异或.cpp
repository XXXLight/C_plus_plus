#include<bits/stdc++.h>
using namespace std;

struct Trie {
	// ������ָ���ʾ 0 ���ӽڵ�
	Trie* left = nullptr;
	// ������ָ���ʾ 1 ���ӽڵ�
	Trie* right = nullptr;

	Trie() {}
};

class Solution {
private:
	// �ֵ����ĸ��ڵ�
	Trie* root = new Trie();
	// ���λ�Ķ�����λ���Ϊ 30
	static constexpr int HIGH_BIT = 30;

public:
	void add(int num) {
		Trie* cur = root;
		for (int k = HIGH_BIT; k >= 0; --k) {
			int bit = (num >> k) & 1;
			if (bit == 0) {
				if (!cur->left) {
					cur->left = new Trie();
				}
				cur = cur->left;
			}
			else {
				if (!cur->right) {
					cur->right = new Trie();
				}
				cur = cur->right;
			}
		}
	}

	int check(int num) {
		Trie* cur = root;
		int x = 0;
		for (int k = HIGH_BIT; k >= 0; --k) {
			int bit = (num >> k) & 1;
			if (bit == 0) {
				// a_i �ĵ� k ��������λΪ 0��Ӧ������ʾ 1 ���ӽڵ� right ��
				if (cur->right) {
					cur = cur->right;
					x = x * 2 + 1;
				}
				else {
					cur = cur->left;
					x = x * 2;
				}
			}
			else {
				// a_i �ĵ� k ��������λΪ 1��Ӧ������ʾ 0 ���ӽڵ� left ��
				if (cur->left) {
					cur = cur->left;
					x = x * 2 + 1;
				}
				else {
					cur = cur->right;
					x = x * 2;
				}
			}
		}
		return x;
	}

	int findMaximumXOR(vector<int>& nums) {
		int n = nums.size();
		int x = 0;
		for (int i = 1; i < n; ++i) {
			// �� nums[i-1] �����ֵ�������ʱ nums[0 .. i-1] �����ֵ�����
			add(nums[i - 1]);
			// �� nums[i] ���� ai���ҳ����� x ���´�
			x = max(x, check(nums[i]));
		}
		return x;
	}
};

