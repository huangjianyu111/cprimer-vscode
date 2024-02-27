#include <iostream>

using namespace std;


class BufferItem {};

void* mPparam = nullptr;
void* mBufferPparam = nullptr;
void* mRtpObject = nullptr;
void(*stream_buffer_cb)(BufferItem* bufferItem, void* pparam, void* rtpObject);
void(*mStream_buffer_cb)(BufferItem* bufferItem, void* pparam, void* rtpObject);
void sm_register_buffer_cb(void(*stream_buffer_cb)(BufferItem* bufferItem, void* pparam, void* rtpObject), int cam_id, void* pparam, void* rtpObject);
void register_buffer_cb(void(*stream_buffer_cb)(BufferItem* bufferItem, void* pparam, void* rtpObject), void* pparam, void* rtpObject);

class Test {
public:
    static void cb_buffer_data(BufferItem* bufferItem, void* pparam, void* rtpObject); // get data after decode
    int getCount() {
        return mCount;
    }

private:
    int mCount = 0;
    std::string str;

};

void Test::cb_buffer_data(BufferItem* bufferItem, void* pparam, void* rtpObject) {
    Test* mRtpObject = (Test *)rtpObject;
    mRtpObject->mCount++;
}

int main() {
    Test* test = new Test();
    BufferItem item;
    sm_register_buffer_cb(Test::cb_buffer_data, 1, nullptr, (void*)test);

    mStream_buffer_cb(&item, mBufferPparam, mRtpObject);

    cout << "count :" << test->getCount() << endl; // 1

}


// add by hjy
void sm_register_buffer_cb(void(*stream_buffer_cb)(BufferItem* bufferItem, void* pparam, void* rtpObject), int cam_id, void* pparam, void* rtpObject)
{
    register_buffer_cb(stream_buffer_cb, pparam, rtpObject);

}

void register_buffer_cb(void(*stream_buffer_cb)(BufferItem* bufferItem, void* pparam, void* rtpObject), void* pparam, void* rtpObject)
{
    mStream_buffer_cb = stream_buffer_cb;
	mBufferPparam = pparam;
    mRtpObject = rtpObject;
}