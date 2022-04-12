#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	//首先itervals按照起点升序 终点降序排序
	//为每个区间设置一个todos变量 里面存储的是本区间还需要找到 存在于交集的元素的个数 
	//因为交集长度至少是2 所以初始时都为2
	//从后往前遍历 如果todo[i]>0 则取出这个区间的前todo[i]个 这里使用了贪心
	//贪心的思想是每次在一个区间 取的个数为这个区间所需要取的个数的最小值 取的值为这个区间的最小值
	//每次取的值为val，同时更新res res++
	//再从此位置 更新下标i之前的todos
	//若第j个位置的右端点小于等于val 则todos[j]--
	static bool cmp(vector<int>& a, vector<int>& b)
	{
		return a[0] == b[0] ? a[1] > b[1]:a[0] < b[0];
	}
	int intersectionSizeTwo(vector<vector<int>>& intervals) {
		//按区间起点升序 区间终点降序
		sort(intervals.begin(), intervals.end(), cmp);
		int size = intervals.size();
		//每个区间还需要找到的交点的个数
		vector<int> todos(size, 2);
		int i = size, res = 0;
		while (--i >= 0)
		{
			//若第i个区间还需要找到todos[i]个交点 从第i个区间依次取前todos[i]个值 记为val
			for (int val = intervals[i][0]; val < intervals[i][0] + todos[i]; val++)
				//实际上所有val构成的值就是集合S
				//更新i之前的todos
				for (int j = i - 1; j >= 0; j--)
					//如果第j个todos[j]不为0 且第j个区间的终点大于等于val
					if (todos[j] && val <= intervals[j][1])
						todos[j]--;
			res += todos[i];//结果加上第i个区间 加到集合中值的个数
			//todos[i]=0;//这句为了完整性更新 实际上不更新也对结果无影响
		}
		return res;
	}
};