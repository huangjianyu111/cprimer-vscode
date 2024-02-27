#include <thread>
#include <mutex>
#include <iostream>
#include <functional>
#include <condition_variable>
#include <pthread.h>
#include <list>

using namespace std;


class Test{
public:
    Test();
    ~Test();
    void inputThreadLoop();
    void outputThreadLoop();
    int stop();
private:
    bool mInputRunning = false;
    std::mutex mInputAvailableMutex;
    std::condition_variable mInputAvailableCond;
    std::list<int32_t> mInputAvailableBuffers;

    bool mOutputRuning = false;
    std::mutex mOutputAvailableMutex;
    std::condition_variable mOutputAvailableCond;
    std::list<int32_t> mOutputAvailableBuffers;


    std::thread *mInputThread;
    std::thread *mOutputThread;

    int mStreamId = 4;

};

Test::Test() {
    mInputRunning = true;
    mInputThread = new std::thread([this](){this->inputThreadLoop();});

    mOutputRuning = true;
    mOutputThread = new std::thread([this](){this->outputThreadLoop();});
}

Test::~Test() {
    if (mInputThread) {
        if (mInputThread->joinable()) {
            mInputThread->join();
        }
        delete mInputThread;
        mInputThread = nullptr;
    }

    if (mOutputThread) {
        if (mOutputThread->joinable()) {
            mOutputThread->join();
        }
        delete mOutputThread;
        mOutputThread = nullptr;
    }
}

int Test::stop() {
    printf("Test::stop() mStreamId=%d \n", mStreamId);
    mInputRunning = false;
    mInputAvailableCond.notify_all();
    if (mInputThread->joinable()) {
        mInputThread->join();
    }

    // mSurface->disconnect(NATIVE_WINDOW_API_MEDIA);
    mOutputRuning = false;
    mOutputAvailableCond.notify_all();
    if (mOutputThread->joinable()) {
        mOutputThread->join();
    }
    return 0;
}

void Test::inputThreadLoop() {
    char threadName[20] = { 0 };
    snprintf(threadName, 20, "%d-decoder-in-loop", mStreamId);
    pthread_setname_np(pthread_self(), threadName);

    while (mInputRunning) {
        printf("[%s] start ....... \n", __FUNCTION__);
        int32_t buffer_index = -1;

            {
                std::unique_lock<std::mutex> _lk(mInputAvailableMutex);
                if (!mInputAvailableBuffers.empty()) {
                    // // Called when an input buffer becomes available.
                    //  .onAsyncInputAvailable = _on_input_available,
                    // _on_input_available function will push available buffer index to mInputAvailableBuffers
                    // replace AMediaCodec_dequeueInputBuffer  get buffer index
                    buffer_index = mInputAvailableBuffers.front();
                    mInputAvailableBuffers.pop_front();
                } else {
                    printf("[%s] mInputAvailableBuffers wait ....... \n", __FUNCTION__);
                    int delay_ms = 500;
                    mInputAvailableCond.wait_for(_lk, std::chrono::milliseconds(delay_ms));
                }
            }
        printf("[%s] end ....... \n", __FUNCTION__);
    }
}


void Test::outputThreadLoop() {
    while (mOutputRuning) {
        printf("[%s] start ....... \n", __FUNCTION__);
        int32_t buffer_index = -1;
        {
            std::unique_lock<std::mutex> _lk(mOutputAvailableMutex);
            if (!mOutputAvailableBuffers.empty()) {
                buffer_index = mOutputAvailableBuffers.front();
                mOutputAvailableBuffers.pop_front();
            } else {
                printf("[%s] mOutputAvailableCond wait ....... \n", __FUNCTION__);

                int delay_ms = 500;
                mOutputAvailableCond.wait_for(_lk, std::chrono::milliseconds(delay_ms));

                // mOutputAvailableCond.wait(_lk);
            }
        }
        printf("[%s] end ....... \n", __FUNCTION__);
    }
}

int main() {

    for (int i=0;i<100;i++) {
        Test* test = new Test();
        test->stop();
    }
    return 0;
}
