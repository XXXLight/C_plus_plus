//滑动窗口算法的抽象思想：

//int left = 0, right = 0;
//
//while (right < s.size()) {
//	window.add(s[right]);
//	right++;
//
//	while (valid) {
//		window.remove(s[left]);
//		left++;
//	}
//}


// 双指针+哈希表+滑动窗口
// 指针都是从头开始