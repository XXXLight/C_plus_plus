#include<bits/stdc++.h>
using namespace std;

// 本质是凸包算法
//   方法一：Jarvis 算法
class Solution {
public:
	bool have[3005];// 已经确定的点
	// (x1,y1) x (x1,y2) 如果 < 0 说明点在线的右边 
	int Crossmultiplication(int& x1, int& y1, int& x2, int& y2) {
		return x1 * y2 - x2 * y1;
	}
	int Cal_dis(int& x1, int& y1, int& x2, int& y2) {
		return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	}
	bool judge(vector<vector<int>>& s, int& a, int& b) {
		// 判断 是否有点 c 在 ab 的右边
		int x, y;// (x,y) 向量ab 的表示 
		x = s[b][0] - s[a][0];
		y = s[b][1] - s[a][1];
		for (int i = 0; i < s.size(); i++) {
			int x_, y_;
			x_ = s[i][0] - s[a][0];
			y_ = s[i][1] - s[a][1];
			if (Crossmultiplication(x, y, x_, y_) < 0) return false;// 说明有点在 ab 的右侧
		}
		return true;
	}
	vector<vector<int>> outerTrees(vector<vector<int>>& s) {
		if (s.size() < 4) return s;// 三角形一定是凸的
		// 凸包题
		// 首先找到最左的点 然后慢慢的来围起来
		vector<vector<int>> res;
		int n = s.size();
		memset(have, false, n);
		int pre = 0;
		for (int i = 1; i < s.size(); i++) {
			if (s[i][0] < s[pre][0]) pre = i;
			else if (s[i][0] == s[pre][0] && s[i][1] < s[pre][1]) pre = i;
		}
		res.push_back(s[pre]);
		have[pre] = true;
		while (1) {
			int add = -1;
			for (int i = 0; i < s.size(); i++) {
				if (have[i]) continue;
				if (judge(s, pre, i)) {
					have[i] = true;
					res.push_back(s[i]);
					if (add == -1) add = i;
					else {
						if (Cal_dis(s[pre][0], s[pre][1], s[add][0], s[add][1]) < \
							Cal_dis(s[pre][0], s[pre][1], s[i][0], s[i][1])) {
							add = i;// 选择最远的 
						}
					}
				}
			}
			if (add == -1) break;
			pre = add;
		}
		return res;
	}
};



// 方法二：Graham 扫描
const int N = 3005;
class Solution {
public:
	int n;
	// 如果 < 0 说明点在线的右边 
	int Crossmultiplication(int& x1, int& y1, int& x2, int& y2) {
		return x1 * y2 - x2 * y1;
	}
	// 计算距离函数
	int Cal_dis(int& x1, int& y1, int& x2, int& y2) {
		return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	}
	int st[N];// 数组模拟栈
	int top;// 栈顶
	vector<vector<int>> outerTrees(vector<vector<int>>& s) {
		n = s.size();
		if (n < 4) return s;
		int idx = 0;// 最左下角的点
		for (int i = 1; i < n; i++) {
			if (s[i][0] < s[idx][0]) idx = i;
			else if (s[i][0] == s[idx][0] && s[i][1] < s[idx][1]) idx = i;
		}
		if (idx) swap(s[idx], s[0]);// 和第一个进行交换
		sort(s.begin() + 1, s.end(), [&](vector<int>& a, vector<int>& b) {
			int x1, y1, x2, y2;
			x1 = a[0] - s[0][0];
			y1 = a[1] - s[0][1];
			x2 = b[0] - s[0][0];
			y2 = b[1] - s[0][1];
			// < 0 说明 b 在右边
			int t = Crossmultiplication(x1, y1, x2, y2);
			if (t == 0) {
				return Cal_dis(s[0][0], s[0][1], a[0], a[1]) < Cal_dis(s[0][0], s[0][1], b[0], b[1]);
			}
			return t > 0;
		});
		// 最后一条边的情况
		int l = n - 2;
		while (l > 0) {
			int x1, y1, x2, y2;
			x1 = s[l][0] - s[0][0];
			y1 = s[l][1] - s[0][1];
			x2 = s[l + 1][0] - s[0][0];
			y2 = s[l + 1][1] - s[0][1];
			if (Crossmultiplication(x1, y1, x2, y2) == 0) l--;
			else break;
		}
		for (int i = l + 1, j = n - 1; i < j; i++, j--) swap(s[i], s[j]);
		vector<vector<int>> res;
		// 首先把前两个点加入栈
		top = 1;
		st[0] = 0;
		st[1] = 1;
		for (int i = 2; i < n; i++) {
			int a = st[top];
			int b = st[top - 1];
			int x1, y1, x2, y2;
			x1 = s[b][0] - s[a][0];
			y1 = s[b][1] - s[a][1];
			x2 = s[i][0] - s[a][0];
			y2 = s[i][1] - s[a][1];
			int t = Crossmultiplication(x1, y1, x2, y2);
			if (t <= 0) st[++top] = i;// 说明还是右转的
			else top--, i--;// 否则退栈
		}
		// 把栈里的元素都加到 res 里
		for (int i = 0; i <= top; i++) res.push_back(s[st[i]]);
		return res;
	}
};

