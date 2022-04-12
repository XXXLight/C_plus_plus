#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long int str2int(string s, int l, int r) {
		// 字符串 转 整数
		long long int res = 0;
		for (int i = l; i < r; i++) {
			res *= 10;
			res += s[i] - '0';
			if (res > 184467440737095516) // 防止越界, 随便写一个就好了
				return -10;
		}
		return res;
	}
	bool splitString(string s) {
		if (s.size() <= 1) return false;
		long long int arr[21][21];
		memset(arr, 0, sizeof(arr));

		// 计算数组 arr
		for (int i = 0; i < s.size(); i++) {
			for (int j = i + 1; j <= s.size(); j++) {
				arr[i][j] = str2int(s, i, j);
			}
		}

		// 建立队列及初始化
		queue<int> q;
		queue<long long int> num;
		for (int i = 1; i < s.size(); i++) {
			q.push(i);
			num.push(arr[0][i]);
		}
		while (q.size() > 0) {
			// 每次从队列头部取值
			long long int idx = q.front();
			long long int last_num = num.front();
			q.pop();
			num.pop();

			// 寻找满足条件的 下一个 下标 及 数值
			for (int i = 1; idx + i <= s.size(); i++) {
				if (arr[idx][idx + i] == last_num - 1) { // 如果找到了
					if (idx + i == s.size()) return true; // 判断是否成功
					q.push(idx + i);        // 新元素入队
					num.push(last_num - 1);
				}
				// 如果没找到，什么也不做
			}
		}
		return false;
	}
};
