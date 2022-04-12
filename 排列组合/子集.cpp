#include<bits/stdc++.h>
using namespace std;

// 参考文档：https://leetcode-cn.com/problems/subsets/solution/c-zong-jie-liao-hui-su-wen-ti-lei-xing-dai-ni-gao-/

//	backtrack框架
//	（1）边界
//	（2）tmp放
//	（3）tmp不放
//

//方式一：写成放与不放两种状态，思路非常清晰，容易理解（子集树），最后一行的叶子节点存储结果
//                              []             depth=0             
//						      /    \
//							[1]     []        --------是否放1;depth=1
//                          / \    /  \
//                       [12] [1] [2]  []     --------是否放2;depth=2


class Solution {
public:
	//作为成员变量的好处是参数不用传来传去
	vector<int> tmp; //理解1：中间结果  理解2：选与不选形成的路径
	vector<vector<int>> res; //存储结果

	void backtrack(int depth, vector<int>& nums) {
		//子集问题的递归边界是达到数据尾部,因为从0开始，[0,nums.size()-1)
		if (depth == nums.size()) {//depth表示递归深度，达到数组末尾则需要存放结果了
			res.push_back(tmp); //已经形成了中间路径
			return;//这里是return
		}
		//四行式
		//放元素
		tmp.push_back(nums[depth]);
		backtrack(depth + 1, nums);
		//不放元素
		tmp.pop_back();
		backtrack(depth + 1, nums);//这行必须有，试过
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		backtrack(0, nums); //这里只需要传原始数组和深度就行了
		return res;
	}
};

//写成for(a a可以到达的集合)，"三段论形式"
// 三段式对应的树形结构：每个中间节点存储结果
//                                 1 2 3
//                            /    |    \    \
//					         []    1     2    3
//                                / \     \
//                               12  13   23  
//                               /
//						       123
class Solution {
public:
	//作为成员变量的好处是参数不用传来传去
	vector<int> tmp; //理解1：中间结果  理解2：选与不选形成的路径
	vector<vector<int>> res; //存储结果

	void backtrack(int depth, vector<int>& nums) {
		res.push_back(tmp); //每个节点上存储结果，对比上面，这里没有return的操作
		// 1 2 3 i=0 {1}+[2,3]子集  {} i=1 {2}+[3]的子集  i=2 ,{3}
		for (int i = depth; i < nums.size(); i++) {//遍历每一层
			//3行式
			tmp.push_back(nums[i]);
			backtrack(i + 1, nums); // 注意这里是i,不是depth
			//不放元素
			tmp.pop_back();
		}
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		backtrack(0, nums); //这里只需要传原始数组和深度就行了
		return res;
	}
};


//另外一种方法，遇到一个数就把所有子集加上该数组成新的子集，遍历完毕即是所有子集
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.size() == 0) return { {} };//return {}与return {{}}是不一样的
		int n = nums.back();
		nums.pop_back();//先删除一个元素求子集
		vector<vector<int>> res = subsets(nums); // 此处可以通过控制变量法进行调试
		int len = res.size();
		for (int i = 0; i < len; i++) {
			res.push_back(res[i]);
			res.back().push_back(n);
		}
		return res;
	}
};

//另一种方法，位集来做
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		int len = pow(2, nums.size());//int len = 1 << (nums.size());  用1的左移位数来表示
		vector<int> r;
		for (int mask = 0; mask < len; mask++) {
			for (int j = 0; j < nums.size(); j++) {
				if ((1 << j)&mask)   // if ((i >> j) & 1)
					r.push_back(nums[j]);
			}
			res.push_back(r);
			r.clear();
		}
		return res;
	}
};



class Solution {
public:
	//作为成员变量的好处是参数不用传来传去
	vector<int> tmp; //理解1：中间结果  理解2：选与不选形成的路径
	vector<vector<int>> res; //存储结果

	void backtrack(int depth, vector<int>& nums) {
		//子集问题的递归边界是达到数据尾部,因为从0开始，[0,nums.size()-1)
		if (depth == nums.size()) {//depth表示递归深度，达到数组末尾则需要存放结果了
			res.push_back(tmp); //已经形成了中间路径
			return;//这里是return
		}
		//四行式
		//放元素
		tmp.push_back(nums[depth]);
		backtrack(depth + 1, nums);
		cout << "深度" << depth << " ";
		for (auto e : tmp) cout << e << " ";
		cout << endl;
		//不放元素
		tmp.pop_back();
		backtrack(depth + 1, nums);//这行必须有，试过
		cout << "深度" << depth << " ";
		for (auto e : tmp) cout << e << " ";
		cout << endl;
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		backtrack(0, nums); //这里只需要传原始数组和深度就行了
		return res;
	}
};





// 另一种方法，位集来做
// 位集的调试输出，利用bitset<位数>(数字n)的方法来实现
// 注意理解时可以借助控制变量法的思想，固定i不变，让j变
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		int len = pow(2, nums.size());//int len = 1 << (nums.size());  用1的左移位数来表示，pow(2, nums.size())==1 << (nums.size())
		vector<int> r;
		for (int mask = 0; mask < len; mask++) {
			for (int j = 0; j < nums.size(); j++) {
				if ((1 << j)&mask)   // if ((i >> j) & 1)
				{
					r.push_back(nums[j]);
				}
			}
			// [1,2,3,4,5,6]的集合的调试方法
			cout << bitset<6>(mask) << " ";// 数据有6位就用6位二进制位进行显示
			for (auto e : r) cout << e << " ";
			cout << endl;
			res.push_back(r);
			r.clear();
		}
		return res;
	}
};