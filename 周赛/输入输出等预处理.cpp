#include<bits/stdc++.h>
using namespace std;

// 给该类重新命名
typedef struct Point {
	int x;
	int y;
	int z;
}Pt;

int main() {
	vector<Pt> p(3); // 注意这里不是[]
	p[0].x = 1, p[0].y = 2, p[0].z = 3;
	p[1].x = 4, p[1].y = 5, p[1].z = 6;
	p[2].x = 7, p[2].y = 9, p[2].z = 3;
	p.push_back({ 8,7,6 });
	Pt tmp;
	tmp.x = 88, tmp.y = 99, tmp.z = 100;
	p.push_back(tmp);
	// 按y降序
	sort(p.begin(), p.end(), [](auto& p1, auto& p2) {return p1.y > p2.y; });
	string s = "789-123-456";
	string re;
	int a;
	int b;
	int c;
	sscanf(s.c_str(), "%d-%d-%d", &a, &b, &c);
	return 0;
}