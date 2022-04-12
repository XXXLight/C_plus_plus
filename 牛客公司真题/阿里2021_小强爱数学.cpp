// 题目链接：https://www.nowcoder.com/question/next?pid=30440638&qid=1664953&tid=46305004
// 思路：令f(n)=x^n+y^n;找f(n)、f(n-1)之间关系

#include<bits/stdc++.h>
using namespace std;
const int kmod = 1e9 + 7;
vector<long long> dp(1e5 + 5);
long long XnYn(int A, int B, int n) {
	dp[0] = 2;
	dp[1] = A;
	for (int i = 2; i <= n; i++) {
		// 这里kmod怎么写才是难点
		dp[i] = (A*dp[i - 1] % kmod - B * dp[i - 2] % kmod + kmod) % kmod;
	}
	return dp[n];
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int a, b, n;
		cin >> a >> b >> n;
		cout << XnYn(a, b, n) << endl;
	}
}