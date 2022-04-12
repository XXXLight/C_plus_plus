#include<bits/stdc++.h>
using namespace std;



// 用于存储对象的实现
struct Item
{
	// 当前候选人是谁
	int candidate;
	// 计数器
	int cnt;

	Item(int candidate, int cnt) : candidate(candidate), cnt(cnt) {}
	Item() {}
};

// 找线段树里的左右节点的序号：序号对应的就是 itemTree 里的序号
#define LEFT(i) (2*i+1)
#define RIGHT(i) (2*i+2)

class MajorityChecker {
private:
	// 存储的数据，其实就是输入arr的拷贝
	vector<int> data;
	// 线段树：大小是数据大小的四倍
	vector<Item> itemTree;
	// 数字到对应序号的映射
	// 存储的数组因为是升序排列的
	unordered_map<int, vector<int>> num2ids;
	// 数据的大小,即arr.size()
	int n;

	// 合并两个结点
	// 摩尔投票来判断谁更大，并且需要减去对应的cnt
	// 可以用摩尔投票是因为条件 2 * threshold > right - left + 1
	Item merge(Item a, Item b)
	{
		if (a.candidate == b.candidate)
		{
			return Item(a.candidate, a.cnt + b.cnt);
		}
		else if (a.cnt > b.cnt)
		{
			return Item(a.candidate, a.cnt - b.cnt);
		}
		else
		{
			return Item(b.candidate, b.cnt - a.cnt);
		}
	}

	// 递归 pushUp 去构建线段树
	void build(int index, int l, int r)
	{
		// cout << index << " " << l << " " << r << endl;
		// 叶子节点
		if (l == r)
		{
			itemTree[index].candidate = data[l];
			itemTree[index].cnt = 1;
			return;
		}
		// 分治思维去构建
		int leftIndex = LEFT(index);
		int rightIndex = RIGHT(index);
		int midIndex = (l + r) >> 1;
		build(leftIndex, l, midIndex);
		build(rightIndex, midIndex + 1, r);
		// 更新父节点
		auto newItem = merge(itemTree[leftIndex], itemTree[rightIndex]);
		itemTree[index].candidate = newItem.candidate;
		itemTree[index].cnt = newItem.cnt;
	}

	// 基于线段树去搜索
	// ql和qr是查询的左右范围
	Item queryTree(int index, int l, int r, int ql, int qr)
	{
		// 边缘情况，空数据直接返回无效-1
		if (data.size() == 0)
		{
			return { -1, -1 };
		}

		// 当前index已经覆盖被查询范围覆盖，则返回candidate信息
		if (l >= ql && r <= qr)
		{
			return itemTree[index];
		}

		// 分治在更小范围内寻找
		auto midIndex = (l + r) >> 1;
		auto leftIndex = LEFT(index);
		auto rightIndex = RIGHT(index);

		// 当前范围无法覆盖 [ql,qr]
		// 找可能覆盖的范围
		if (ql > midIndex)
		{
			// 对于数值偏小，去更大右结点去找
			return queryTree(rightIndex, midIndex + 1, r, ql, qr);
		}
		else if (qr <= midIndex)
		{
			// 对于数值偏大，去更小的左节点去找
			return queryTree(leftIndex, l, midIndex, ql, qr);
		}

		// 已经覆盖到的情况即 ql <= minIndex < qr: 则把两部分合并在一起
		return merge(queryTree(leftIndex, l, midIndex, ql, midIndex),
			queryTree(rightIndex, midIndex + 1, r, midIndex + 1, qr));
	}

public:
	MajorityChecker(vector<int>& arr) {
		n = arr.size();
		data.resize(n);
		// 最大数量
		itemTree.resize(n << 2);
		// 构建映射表（数字到对应序号的数组）和临数据data
		for (int i = 0; i < n; ++i)
		{
			data[i] = arr[i];
			num2ids[arr[i]].push_back(i);
		}
		// 构建线段树
		if (n > 0)
		{
			build(0, 0, n - 1);
		}

		// vector<int> ids = {0, 1, 2, 3, 5, 6, 7};
		// auto i1 = lower_bound(ids.begin(), ids.end(), 1);
		// auto i2 = upper_bound(ids.begin(), ids.end(), 4);
		// cout << i2-i1 << endl;
	}

	int query(int left, int right, int threshold) {
		// 基于线段树去查找绝对众数
		auto item = queryTree(0, 0, n - 1, left, right);
		// 无效数值直接返回
		if (item.candidate == -1 || item.cnt == -1)
		{
			return -1;
		}

		// 基于找到candidate去找对应的序号的数组（有序数组）
		auto candidate = item.candidate;
		if (num2ids.find(candidate) == num2ids.end())
		{
			return -1;
		}
		auto& ids = num2ids[candidate];
		// 二分查找满足查询范围上下边界，他们差值就是对应元素的数量
		int cnt = upper_bound(ids.begin(), ids.end(), right) - lower_bound(ids.begin(), ids.end(), left);
		// 若数量>=threshold,则返回数值；否则返回-1
		return cnt >= threshold ? candidate : -1;
	}
};

