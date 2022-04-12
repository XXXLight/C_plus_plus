#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

// û������
// ע�⣬����ļ������͡�����������2����һ���ģ������õ����ݽṹ��stack
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
			// ���µ�ǰ������
			if (s[i] >= '0' && s[i] <= '9')
			{
				num = num * 10 + (s[i] - '0');
			}
			// �ж��Ƿ���������Ż������һ��
			// ��ǰ������������һ�� �������
			// ��ǰs[i]		��һ��sign
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
				// �����������
				sign = s[i];
			}
		}

		int res = 0;
		// �����Ҫ��stack��ȫ����ȡ��ȥȻ���ۼ���һ��
		while (!ss.empty())
		{
			res += ss.top();
			// cout << res << endl;
			ss.pop();
		}
		return res;
	}
};
