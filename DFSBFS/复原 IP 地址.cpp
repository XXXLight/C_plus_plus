#include<bits/stdc++.h>
using namespace std;


// Q1:哪个控制纵向，哪个控制横向？（pointNum控制纵向，for遍历横向）
class Solution {
private:
	vector<string> result;// 记录结果
	// startIndex: 搜索的起始位置，pointNum:添加逗点的数量
	void backtracking(string& s, int startIndex, int pointNum) {
		if (pointNum == 3) { // 逗点数量为3时，分隔结束
			// 判断第四段子字符串是否合法，如果合法就放进result中
			// 类比树的叶子节点
			if (isValid(s, startIndex, s.size() - 1)) {
				result.push_back(s);
			}
			return;
		}
		for (int i = startIndex; i < s.size(); i++) {
			if (isValid(s, startIndex, i)) { // 判断 [startIndex,i] 这个区间的子串是否合法
				s.insert(s.begin() + i + 1, '.');  // 在i的后面插入一个逗点
				pointNum++;
				backtracking(s, i + 2, pointNum);   // 插入逗点之后下一个子串的起始位置为i+2
				pointNum--;                         // 回溯
				s.erase(s.begin() + i + 1);         // 回溯删掉逗点
			}
			else break; // 不合法，直接结束本层循环
		}
	}
	// 判断字符串s在左闭又闭区间[start, end]所组成的数字是否合法
	bool isValid(const string& s, int start, int end) {
		if (start > end) {
			return false;
		}
		if (s[start] == '0' && start != end) { // 0开头的数字不合法
			return false;
		}
		int num = 0;
		for (int i = start; i <= end; i++) {
			if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
				return false;
			}
			// 数字从左到右逐个累加
			num = num * 10 + (s[i] - '0');
			if (num > 255) { // 如果大于255了不合法
				return false;
			}
		}
		return true;
	}
public:
	vector<string> restoreIpAddresses(string s) {
		result.clear();
		backtracking(s, 0, 0);
		return result;
	}
};




class Solution {
private:
	static constexpr int SEG_COUNT = 4;

private:
	vector<string> ans;
	vector<int> segments;

public:
	void dfs(const string& s, int segId, int segStart) {
		// 如果找到了 4 段 IP 地址并且遍历完了字符串，那么就是一种答案
		if (segId == SEG_COUNT) {
			if (segStart == s.size()) {
				string ipAddr;
				for (int i = 0; i < SEG_COUNT; ++i) {
					ipAddr += to_string(segments[i]);
					if (i != SEG_COUNT - 1) {
						ipAddr += ".";
					}
				}
				ans.push_back(move(ipAddr));
			}
			return;
		}

		// 如果还没有找到 4 段 IP 地址就已经遍历完了字符串，那么提前回溯
		if (segStart == s.size()) {
			return;
		}

		// 由于不能有前导零，如果当前数字为 0，那么这一段 IP 地址只能为 0
		if (s[segStart] == '0') {
			segments[segId] = 0;
			dfs(s, segId + 1, segStart + 1);
		}

		// 一般情况，枚举每一种可能性并递归
		int addr = 0;
		for (int segEnd = segStart; segEnd < s.size(); ++segEnd) {
			addr = addr * 10 + (s[segEnd] - '0');
			if (addr > 0 && addr <= 0xFF) {
				segments[segId] = addr;
				dfs(s, segId + 1, segEnd + 1);
			}
			else {
				break;
			}
		}
	}

	vector<string> restoreIpAddresses(string s) {
		segments.resize(SEG_COUNT);
		dfs(s, 0, 0);
		return ans;
	}
};

