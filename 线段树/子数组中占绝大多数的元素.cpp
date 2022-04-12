#include<bits/stdc++.h>
using namespace std;



// ���ڴ洢�����ʵ��
struct Item
{
	// ��ǰ��ѡ����˭
	int candidate;
	// ������
	int cnt;

	Item(int candidate, int cnt) : candidate(candidate), cnt(cnt) {}
	Item() {}
};

// ���߶���������ҽڵ����ţ���Ŷ�Ӧ�ľ��� itemTree ������
#define LEFT(i) (2*i+1)
#define RIGHT(i) (2*i+2)

class MajorityChecker {
private:
	// �洢�����ݣ���ʵ��������arr�Ŀ���
	vector<int> data;
	// �߶�������С�����ݴ�С���ı�
	vector<Item> itemTree;
	// ���ֵ���Ӧ��ŵ�ӳ��
	// �洢��������Ϊ���������е�
	unordered_map<int, vector<int>> num2ids;
	// ���ݵĴ�С,��arr.size()
	int n;

	// �ϲ��������
	// Ħ��ͶƱ���ж�˭���󣬲�����Ҫ��ȥ��Ӧ��cnt
	// ������Ħ��ͶƱ����Ϊ���� 2 * threshold > right - left + 1
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

	// �ݹ� pushUp ȥ�����߶���
	void build(int index, int l, int r)
	{
		// cout << index << " " << l << " " << r << endl;
		// Ҷ�ӽڵ�
		if (l == r)
		{
			itemTree[index].candidate = data[l];
			itemTree[index].cnt = 1;
			return;
		}
		// ����˼άȥ����
		int leftIndex = LEFT(index);
		int rightIndex = RIGHT(index);
		int midIndex = (l + r) >> 1;
		build(leftIndex, l, midIndex);
		build(rightIndex, midIndex + 1, r);
		// ���¸��ڵ�
		auto newItem = merge(itemTree[leftIndex], itemTree[rightIndex]);
		itemTree[index].candidate = newItem.candidate;
		itemTree[index].cnt = newItem.cnt;
	}

	// �����߶���ȥ����
	// ql��qr�ǲ�ѯ�����ҷ�Χ
	Item queryTree(int index, int l, int r, int ql, int qr)
	{
		// ��Ե�����������ֱ�ӷ�����Ч-1
		if (data.size() == 0)
		{
			return { -1, -1 };
		}

		// ��ǰindex�Ѿ����Ǳ���ѯ��Χ���ǣ��򷵻�candidate��Ϣ
		if (l >= ql && r <= qr)
		{
			return itemTree[index];
		}

		// �����ڸ�С��Χ��Ѱ��
		auto midIndex = (l + r) >> 1;
		auto leftIndex = LEFT(index);
		auto rightIndex = RIGHT(index);

		// ��ǰ��Χ�޷����� [ql,qr]
		// �ҿ��ܸ��ǵķ�Χ
		if (ql > midIndex)
		{
			// ������ֵƫС��ȥ�����ҽ��ȥ��
			return queryTree(rightIndex, midIndex + 1, r, ql, qr);
		}
		else if (qr <= midIndex)
		{
			// ������ֵƫ��ȥ��С����ڵ�ȥ��
			return queryTree(leftIndex, l, midIndex, ql, qr);
		}

		// �Ѿ����ǵ�������� ql <= minIndex < qr: ��������ֺϲ���һ��
		return merge(queryTree(leftIndex, l, midIndex, ql, midIndex),
			queryTree(rightIndex, midIndex + 1, r, midIndex + 1, qr));
	}

public:
	MajorityChecker(vector<int>& arr) {
		n = arr.size();
		data.resize(n);
		// �������
		itemTree.resize(n << 2);
		// ����ӳ������ֵ���Ӧ��ŵ����飩��������data
		for (int i = 0; i < n; ++i)
		{
			data[i] = arr[i];
			num2ids[arr[i]].push_back(i);
		}
		// �����߶���
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
		// �����߶���ȥ���Ҿ�������
		auto item = queryTree(0, 0, n - 1, left, right);
		// ��Ч��ֱֵ�ӷ���
		if (item.candidate == -1 || item.cnt == -1)
		{
			return -1;
		}

		// �����ҵ�candidateȥ�Ҷ�Ӧ����ŵ����飨�������飩
		auto candidate = item.candidate;
		if (num2ids.find(candidate) == num2ids.end())
		{
			return -1;
		}
		auto& ids = num2ids[candidate];
		// ���ֲ��������ѯ��Χ���±߽磬���ǲ�ֵ���Ƕ�ӦԪ�ص�����
		int cnt = upper_bound(ids.begin(), ids.end(), right) - lower_bound(ids.begin(), ids.end(), left);
		// ������>=threshold,�򷵻���ֵ�����򷵻�-1
		return cnt >= threshold ? candidate : -1;
	}
};

