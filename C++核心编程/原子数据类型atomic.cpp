//#include<bits/stdc++.h>
//#include <thread>
//#include <atomic>
//#include <stdio.h>
//std::atomic_bool bIsReady = false;
//std::atomic_int iCount = 100;
//void threadfun1()
//{
//	if (!bIsReady) {
//		std::this_thread::yield();
//	}
//	while (iCount > 0)
//	{
//		printf("iCount:%d\r\n", iCount--);
//	}
//}
//
//int main()
//{
//	std::atomic_bool b;
//	std::list<std::thread> lstThread;
//	// 开了10个线程做一件事
//	for (int i = 0; i < 10; ++i)
//	{
//		lstThread.push_back(std::thread(threadfun1));
//	}
//	for (auto& th : lstThread)
//	{
//		th.join();
//	}
//	std::cout << iCount << std::endl;
//}