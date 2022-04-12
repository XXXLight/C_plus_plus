#include<bits/stdc++.h>
using namespace std;

//调库
// 1.全排列调库前需要先进行排序
// 2.next_permutation的返回值是bool类型，注意还有prev_permutation
// 3.该方法可以直接拿到‘全排列II’使用，直接去重了
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		sort(nums.begin(), nums.end());//必须先排序
		vector<vector<int>> res;
		do {
			res.push_back(nums);
		} while (next_permutation(nums.begin(), nums.end()));
		return res;
	}
};

//排列问题需要vis数组来标记有没有访问过
//对应的是排列数
class Solution {
public:
	//作为成员变量的好处是参数不用传来传去
	vector<int> tmp; //理解1：中间结果  理解2：选与不选形成的路径
	vector<vector<int>> res; //存储结果

	void backtrack(vector<int>& nums, vector<bool>& vis) {
		if (tmp.size() == nums.size()) {
			res.push_back(tmp); //已经形成了中间路径
			return;
		}
		//  for循环处理横向的遍历，其实每次都会有三个分支（[1,2,3]的全排列），只不过标记过的不用重复访问；depth处理深度,全排列无需用到
		for (int i = 0; i < nums.size(); i++) {
			if (vis[i]) continue;
			tmp.push_back(nums[i]);
			vis[i] = true;
			backtrack(nums, vis);// 递归进去分支数不变，只是进行了剪枝
			//不放元素
			tmp.pop_back();
			vis[i] = false;
		}
	}

	// 注意下面没有先进行sort操作
	vector<vector<int>> permute(vector<int>& nums) {
		vector<bool> vis(nums.size(), false);//vis与nums有关系，不好放在外面
		backtrack(nums, vis); //这里只需要传原始数组和深度就行了
		return res;
	}
};


// swap方法
class Solution {
public:
	vector<vector<int>> res;
	void backtrack(vector<int>& nums, int depth, vector<int>&tmp) {
		if (depth == nums.size()) {
			res.push_back(tmp);
		}
		for (int i = depth; i < nums.size(); i++) {
			swap(tmp[i], tmp[depth]);
			backtrack(nums, depth + 1, tmp); // 注意这里是depth
			swap(tmp[i], tmp[depth]);
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		backtrack(nums, 0, nums); // tmp传的是原始数组
		return res;
	}
};



// 以下是调试过程
class Solution {
public:
	vector<vector<int>> res;
	void backtrack(vector<int>& nums, int depth, vector<int>&tmp) {
		if (depth == nums.size()) {
			res.push_back(tmp);
		}
		for (int i = depth; i < nums.size(); i++) {
			swap(tmp[i], tmp[depth]);
			cout << "交换前" << "depth: " << depth << endl;
			for (auto e : tmp) cout << e << " ";
			cout << endl;
			backtrack(nums, depth + 1, tmp); // 注意这里是depth
			swap(tmp[i], tmp[depth]);
			cout << "交换回来" << "depth: " << depth << endl;
			for (auto e : tmp) cout << e << " ";
			cout << endl;
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		backtrack(nums, 0, nums); // tmp传的是原始数组
		// 理解为什么输出数组的顺序是这样的
		for (auto v : res) {
			for (auto e : v) {
				cout << e << " ";
			}
			cout << endl;
		}
		return res;
	}
};


// 输出的结果对照递归树
class Solution {
public:
	//作为成员变量的好处是参数不用传来传去
	vector<int> tmp; //理解1：中间结果  理解2：选与不选形成的路径
	vector<vector<int>> res; //存储结果

	void backtrack(vector<int>& nums, vector<bool>& vis, int depth) {
		if (tmp.size() == nums.size()) {
			res.push_back(tmp); //已经形成了中间路径
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (vis[i]) continue;
			tmp.push_back(nums[i]);
			vis[i] = true;
			cout << "深度" << depth << " ";
			for (auto e : tmp) cout << e << " ";
			cout << endl;
			backtrack(nums, vis, depth + 1);
			//不放元素
			tmp.pop_back();
			vis[i] = false;
			cout << "深度" << depth << " ";
			for (auto e : tmp) cout << e << " ";
			cout << endl;
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<bool> vis(nums.size(), false);//vis与nums有关系，不好放在外面
		backtrack(nums, vis, 0); //这里只需要传原始数组和深度就行了
		for (auto v : res) {
			for (auto e : v) {
				cout << e << " ";
			}
			cout << endl;
		}
		return res;
	}
};
