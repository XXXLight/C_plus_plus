// Java版本代码


//class Solution {
//	static Map<Integer, Integer> map = new HashMap<>();
//	int get(int cur) {
//		if (map.containsKey(cur)) {
//			return map.get(cur);
//		}
//		int ans = 0;
//		for (int i = cur; i > 0; i -= lowbit(i)) ans++;
//		map.put(cur, ans);
//		return ans;
//	}
//	int lowbit(int x) {
//		return x & -x;
//	}
//
//	int n;
//	int ans = Integer.MIN_VALUE;
//	Random random = new Random(20210619);
//	double hi = 1e4, lo = 1e-4, fa = 0.90;
//	int N = 400;
//	int calc() {
//		int mix = 0, cur = 0;
//		for (int i = 0; i < n; i++) {
//			int hash = ws[i];
//			if ((mix & hash) == 0) {
//				mix |= hash;
//				cur += get(hash);
//			}
//			else {
//				break;
//			}
//		}
//		ans = Math.max(ans, cur);
//		return cur;
//	}
//	void swap(int[] arr, int i, int j) {
//		int c = arr[i];
//		arr[i] = arr[j];
//		arr[j] = c;
//	}
//	void sa() {
//		for (double t = hi; t > lo; t *= fa) {
//			int a = random.nextInt(n), b = random.nextInt(n);
//			int prev = calc();
//			swap(ws, a, b);
//			int cur = calc();
//			int diff = prev - cur;
//			if (Math.log(diff / t) >= random.nextDouble()) {
//				swap(ws, a, b);
//			}
//		}
//	}
//	int[] ws;
//	public int maxLength(List<String> _ws) {
//		// 预处理字符串：去重，剔除无效字符
//		// 结果这一步后：N 可以下降到 100；fa 可以下降到 0.70，耗时约为 78 ms
//		// 为了预留将来添加测试数据，题解还是保持 N = 400 & fa = 0.90 的配置
//		n = _ws.size();
//		HashSet<Integer> set = new HashSet<>();
//		for (String s : _ws) {
//			int val = 0;
//			for (char c : s.toCharArray()) {
//				int t = (int)(c - 'a');
//				if (((val >> t) & 1) != 0) {
//					val = -1;
//					break;
//				}
//				val |= (1 << t);
//			}
//			if (val != -1) set.add(val);
//		}
//
//		n = set.size();
//		if (n == 0) return 0;
//		ws = new int[n];
//		int idx = 0;
//		for (Integer i : set) ws[idx++] = i;
//
//		while (N-- > 0) sa();
//		return ans;
//	}
//}
//
