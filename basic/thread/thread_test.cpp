#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <iostream>
#include <atomic>

struct Test {
public:
    void runTask();

    // std::atomic<uint16_t> mNum {0};
    uint16_t mNum = 0;
    std::atomic<bool> mFlag {false};

    std::mutex muxLock;
};

void Test::runTask() {
    std::unique_lock<std::mutex> lk(muxLock);
    for (int i=0;i < 100;i++) {
        mNum++;
        lk.unlock();
        std::cout << "thread id : " << std::this_thread::get_id() << ", num = " << mNum << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        lk.lock(); // 必须要去拿锁，否则会出现多线程资源同步问题
    }
    mFlag = true;
}

int main() {
    std::cout << "---------- main thread begin ----------" << std::endl;
    Test test;

    test.mNum = 100;
    std::thread t1(&Test::runTask, &test);

    std::thread t2(&Test::runTask, &test);

    if (t1.joinable()) {
        t1.join();
    }

    if (t2.joinable()) {
        t2.join();
    }

    std::cout << "---------- main thread end ----------" << std::endl;
    
}
