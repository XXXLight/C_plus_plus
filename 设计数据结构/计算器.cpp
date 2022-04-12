#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

// 没有括号
// 注意，这里的计算器和“基本计算器2”是一样的，这里用的数据结构是stack
class Solution {
public:
	int calculate(string s) {
		int n = s.size();
		// if (n <= 0)
		// {
		//     return 0;
		// }

		const unordered_set<char> signs{ '+', '-', '*', '/' };
		stack<int> ss;
		char sign = '+';
		int num = 0;
		int topVal = 0;
		for (int i = 0; i < n; ++i)
		{
			// 更新当前的数字
			if (s[i] >= '0' && s[i] <= '9')
			{
				num = num * 10 + (s[i] - '0');
			}
			// 判断是否是运算符号或者最后一个
			// 当前计算依赖于上一个 运算符号
			// 当前s[i]		上一个sign
			if (signs.find(s[i]) != signs.end() || i == n - 1)
			{
				if (sign == '+')
				{
					ss.push(num);
					// cout << "+ " << num << endl;
				}
				else if (sign == '-')
				{
					ss.push(-num);
				}
				else if (sign == '*')
				{
					topVal = ss.top();
					ss.pop();
					ss.push(topVal * num);
					// cout << "+ " << num << " " << topVal * num << endl;
				}
				else
				{
					topVal = ss.top();
					ss.pop();
					ss.push(topVal / num);
				}
				num = 0;
				// 更新运算符号
				sign = s[i];
			}
		}

		int res = 0;
		// 最后结果要把stack里全部都取出去然后累加在一起
		while (!ss.empty())
		{
			res += ss.top();
			// cout << res << endl;
			ss.pop();
		}
		return res;
	}
};
