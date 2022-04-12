#include<bits/stdc++.h>
using namespace std;

// 记忆方法 left+随机正整数%区间长度


//产生一定范围随机数的通用表示公式：
//要取得[a, b)的随机整数，使用(rand() % (b - a)) + a;
//要取得[a, b]的随机整数，使用(rand() % (b - a + 1)) + a;
//要取得(a, b]的随机整数，使用(rand() % (b - a)) + a + 1;
//通用公式:a + rand() % n；其中的a是起始值，n是整数的范围。
//要取得a到b之间的随机整数，另一种表示：a + (int)b * rand() / (RAND_MAX + 1)。
//要取得0～1之间的浮点数，可以使用rand() / double(RAND_MAX)。


//分析洗牌算法正确性的准则：产生的结果必须有 n! 种可能，否则就是错误的。

class Solution {
private:
	// 数组自己写
	vector<int> data;
public:
	Solution(vector<int>& nums) {
		data = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return data;
	}
	// 产生[a,b]间随机整数
	int randINT(int a, int b) {
		return rand() % (b - a + 1) + a;
	}
	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> res(data); //拷贝构造
		//法一：
		for (int i = 0; i < res.size(); i++)
		{
			// 随机取下标
			int rand = randINT(i, res.size() - 1);
			// 交换位置
			swap(res[i], res[rand]);
		}
		//法二：
		/*for (int i = 0; i < res.size() - 1; i++)
		{
			int rand = randINT(i, res.size() - 1);
			swap(res[i], res[rand]);
		}*/
		//法三：
		//for (int i = res.size() - 1; i >= 0; i--)
		//{
		//	int rand = randINT(0, i);
		//	swap(res[i], res[rand]);
		//}
		//法四：
		//for (int i = res.size() - 1; i > 0; i--)
		//{
		//	int rand = randINT(0, i);
		//	swap(res[i], res[rand]);
		//}
		return res;
	}
};


