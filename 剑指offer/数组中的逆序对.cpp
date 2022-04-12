#include<bits/stdc++.h>
using namespace std;
//求逆序对数量
//学习点：
//1.int mid = left + (right - left) / 2; // 此算式等同于 (left + right) / 2，是为了避免溢出！！！学习！！！！
//2.将归并过程中的所有情况统一起来，四个if else
//3.辅助数组是用来比较的
//4.没有main函数方便保存


class Solution {
public:
	int reversePairs(vector<int>& nums) { //函数作用：求逆序对数量，重载了
		int len = nums.size();
		if (len < 2) {
			return 0; // 若不存在数对，直接 return 0
		}
		vector<int> helper(len); //辅助数组
		return reversePairs(nums, 0, len - 1, helper);
	}

private:
	int reversePairs(vector<int>& nums, int left, int right, vector<int>& helper) {
		if (left == right) {
			return 0; // 递归终止条件是只剩一个元素了（即不存在数对了）
		}

		int mid = left + (right - left) / 2; // 此算式等同于 (left + right) / 2，是为了避免溢出！！！学习！！！！

		int leftPairs = reversePairs(nums, left, mid, helper); // 计算左半部分的逆序对[left,mid]
		int rightPairs = reversePairs(nums, mid + 1, right, helper); // 计算右半部分的逆序对[mid+1,right]

		if (nums[mid] <= nums[mid + 1]) {
			// 此判断用于加速，即如果左右都已排好序，而且左边的最大值 <= 右边的最小值，
			// 那么就不存在跨越左边和右边的逆序对了
			return leftPairs + rightPairs;
		}

		int crossPairs = mergeAndCount(nums, left, mid, right, helper); // 计算跨越左边和右边的逆序对

		return leftPairs + rightPairs + crossPairs;
	}

	int mergeAndCount(vector<int>& nums, int left, int mid, int right, vector<int>& helper) {
		// 本函数的前提条件是：左半部分和右半部分都是已经按升序排好序了的,是这样的没错
		// 因为本函数是从左右部分都是只有一个元素的情况开始运行的（自底向上），所以是可以保证前提条件的
		for (int i = left; i <= right; ++i) {
			helper[i] = nums[i]; // 先填充 helper 辅助数组,数组作为备份
		}

		int i = left, j = mid + 1; // i 和 j 分别是左半部分和右半部分的起点
		int count = 0; // count 用来统计逆序对数量

		for (int k = left; k <= right; ++k) {
			if (i == mid + 1) {
				// 假如 i 已经越过左边的边界，直接填充右半部分进 nums
				nums[k] = helper[j];//左边是nums,右边是helper
				++j;
			}
			else if (j == right + 1) {
				// 假如 j 已经越过右边的边界，直接填充左半部分进 nums
				nums[k] = helper[i];//左边是nums,右边是helper
				++i;
			}
			else if (helper[i] <= helper[j]) { // 注意健壮的归并排序这里要是 <=,不能少了等于号，比较用的是helper数组
			 // 假如左边小于等于右边，那就不是逆序对，不用修改 count
				nums[k] = helper[i];//左边是nums,右边是helper
				++i;
			}
			else {
				// 假如左边大于右边，是逆序对，count += 当前左边 [i, mid] 的所有元素
				// 因为假如左边是 [7,8]，右边是[5,6]，然后 i 指向 7，j 指向 5
				// 那么 5 和 7、8 都构成了逆序对，也就是此时有两对新的逆序对
				// 所以可以总结出规律：count += mid - i + 1
				nums[k] = helper[j];
				count += mid - i + 1;
				++j;
			}
		}

		return count;
	}
};

