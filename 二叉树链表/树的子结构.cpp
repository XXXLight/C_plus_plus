#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/*****************************************************************
二叉树节点定义以及各种算法
*****************************************************************/

//树节点的定义,要会写初始化列表
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 时间复杂度 O(MN) ： 其中 M,N 分别为树 A 和 树 B 的节点数量
// 空间复杂度 O(M) ： 当树 A 和树 B 都退化为链表时，递归调用深度最大。
class Solution {
public:
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		// 有一棵树为空就返回false
		if (A == NULL || B == NULL) return false;
		// 要么左子树包含B，要么右子树包含B，要么整棵树包含B
		return isSame(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
	}
	// A是否含B
	bool isSame(TreeNode* A, TreeNode* B) {
		// 以下两条语句的顺序还不能交换，要不然会报错
		// B空，A肯定包含B
		if (B == NULL) return true;
		// A空，A肯定不包含B
		if (A == NULL) return false;
		return (A->val == B->val) && (isSame(A->left, B->left)) && (isSame(A->right, B->right));
	}
};