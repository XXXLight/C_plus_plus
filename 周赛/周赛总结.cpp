//1.每个接口实现一个简单功能，然后进行相应测试看接口是否设计正确
//2.大问题进行向小问题转化的，化归，大问题 = 》小问题，小问题解决了，大问题就能解决
//3.简单题可以先直接暴力模拟(这种办法对于前两题几乎都可以)
//4.大佬的并行处理问题能力很强，咱们菜鸡不行就先串行处理，再连起来
//5.任何算法，能自己实现（从0到AC），才算是真正掌握，因为复制粘贴少了debug的过程，debug才是精髓(如归并排序debug过程，其实就是控制变量法)
//6.擅于利用语言优势，python更擅长处理字符串、大数、进制转换、lru_cache(递归保存中间结果)
//7.先算出所有结果，存在数组里，即开大内存存储所有结果，然后再遍历查找(动态规划的核心思想), 内存有的是
//8.擅于利用编辑器的特性，学会看代码的框架，养成框架思维(任何语言代码都是，html, css, js, 注释都是ctrl + / )，都有格式化代码的功能
//9.C++里面的cout会占用大量时间，提交代码时注意了!!!要去掉
//10.不要拘泥于别人的代码，要有自己的想法，学以致用，比如C++点云的结构体T与vector<T>
//11.大数mod，对每项mod就可，10的9次方 + 7写成1e9 + 7，floor向下取整，ceil向上取整，round四舍五入, a + rand() % (b - a + 1)产生随机数[a, b].随机返回0或1骗分，return rand() % 2
//12.using ll = long long; cout << fixed << setprecision(8) << a << endl;
//13.数学上可行代码上才可行，先把逻辑想清楚了
//14.y ^ 2并不是求平方, 而是求异或，位运算尽量加括号，要不然会报错，如if((x^i) > m)，int m = l + ((r - l) >> 1); // 注意运算符的优先级，>>小于+
//15.map的逆序遍历：for(auto rit = mp.rbegin(); rit != mp.rend(); rit++)
//16.isalpha ：判断一个字符是否为字母，
//isdigit : 判断一个字符是否表示数字，
//	isalnum : 判断一个字符是否表示数字或者字母，
//	islower : 判断一个字符是否为小写字母，
//	isupper : 判断一个字符是否为大写字母，
//	tolower : 若字符为字母则转化为小写字母；
//	toupper : 若字符为字母则转化为大写字母；
//	17.transform(s.begin(), s.end(), s.begin(), ::tolower)将单词的大写转换为小写
//	18.int / long / long long的最大值分别是INT_MAX / LONG_MAX / LLONG_MAX
//	19.f or (auto&)和for(auto)运行时间前者更快
//	20.Line 19 : Char 17 : runtime error : signed integer overflow : 100000 * 100001 cannot be represented in type 'int' (solution.cpp), 将 int *(1.0)转换成float，或者左乘1LL
//	21.(a + b) % p = (a % p + b % p) % p(a - b) % p = (a % p - b % p) % p
//	(a * b) % p = (a % p * b % p) % p(a^b) % p = ((a % p) ^ b) % p
//	22.ull超出范围会自动取模
//	23.std::string_view view = s; 方法是真的牛皮,比std::string要快很多





// 根据数据范围反推算法：
// https://www.acwing.com/blog/content/32/
//n≤30, 指数级别, dfs + 剪枝，状态压缩dp
//n≤100 = > O(n3)O(n3) ，floyd，dp，高斯消元
//n≤1000 = > O(n2)O(n2)，O(n2logn)O(n2logn)，dp，二分，朴素版Dijkstra、朴素版Prim、Bellman - Ford
//n≤10000 = > O(n∗n√)O(n∗n)，块状链表、分块、莫队
//n≤10^5 = > O(nlogn)O(nlogn) = > 各种sort，线段树、树状数组、set / map、heap、拓扑排序、dijkstra + heap、prim + heap、Kruskal、spfa、求凸包、求半平面交、二分、CDQ分治、整体二分、后缀数组、树链剖分、动态树
//n≤10^6 = > O(n)O(n), 以及常数较小的 O(nlogn)O(nlogn) 算法 = > 单调队列、 hash、双指针扫描、并查集，kmp、AC自动机，常数比较小的 O(nlogn)O(nlogn) 的做法：sort、树状数组、heap、dijkstra、spfa
//n≤10^7 = > O(n)O(n)，双指针扫描、kmp、AC自动机、线性筛素数
//n≤10^9 = > O(n√)O(n)，判断质数
//n≤10^18 = > O(logn)O(logn)，最大公约数，快速幂，数位DP
//n≤10^1000 = > O((logn)2)O((logn)2)，高精度加减乘除
//n≤10^100000 = > O(logk×loglogk)，k表示位数O(logk×loglogk)，k表示位数，高精度加减、FFT / NTT

