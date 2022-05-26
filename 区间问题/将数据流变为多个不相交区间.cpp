#include<bits/stdc++.h>
using namespace std;



class SummaryRanges {
private:
	map<int, int> intervals;

public:
	SummaryRanges() {}

	void addNum(int val) {
		// �ҵ� l1 ��С�������� l1 > val ������ interval1 = [l1, r1]
		// ������������������䣬interval1 Ϊβ������
		auto interval1 = intervals.upper_bound(val);
		// �ҵ� l0 ���������� l0 <= val ������ interval0 = [l0, r0]
		// �����򼯺��У�interval0 ���� interval1 ��ǰһ������
		// ������������������䣬interval0 Ϊβ������
		auto interval0 = (interval1 == intervals.begin() ? intervals.end() : prev(interval1));

		if (interval0 != intervals.end() && interval0->first <= val && val <= interval0->second) {
			// ���һ
			return;
		}
		else {
			bool left_aside = (interval0 != intervals.end() && interval0->second + 1 == val);
			bool right_aside = (interval1 != intervals.end() && interval1->first - 1 == val);
			if (left_aside && right_aside) {
				// �����
				int left = interval0->first, right = interval1->second;
				intervals.erase(interval0);
				intervals.erase(interval1);
				intervals.emplace(left, right);
			}
			else if (left_aside) {
				// �����
				++interval0->second;
			}
			else if (right_aside) {
				// �����
				int right = interval1->second;
				intervals.erase(interval1);
				intervals.emplace(val, right);
			}
			else {
				// �����
				intervals.emplace(val, val);
			}
		}
	}

	vector<vector<int>> getIntervals() {
		vector<vector<int>> ans;
		for (const auto&[left, right] : intervals) {
			ans.push_back({ left, right });
		}
		return ans;
	}
};

