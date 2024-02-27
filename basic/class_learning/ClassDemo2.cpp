#include <iostream>
#include <stdio.h>
#include <string>

#include "ClassDemo2.h"

using namespace std;

namespace hjy_test {
// add by hjy, add listener for decoder restart
class MyDecoderStatusListener : public hjy_test::DecoderStatusListener {
public:
    virtual ~MyDecoderStatusListener() = default;

    // when rtp decoder stuck more than 5s, it will be invoke and return 1
    virtual int onDecodeRestart(int val) override {
        // camx_rtp can do something
        printf("rtp decoder restart, %s val : %d \n", __FUNCTION__, val);
        
        return val;
    }

    /*
        * @param format
        * @return format, which symbol codec format
        */
    virtual RTPCodecFormat onCodecFormatSure(RTPCodecFormat format) override {
        printf("rtp decoder restart, %s val : %d \n", __FUNCTION__, static_cast<int>(format));
        return format;
    }
};

};

class Screen {
public:
    typedef std::string::size_type pos; // std::size_t
    Screen() = default;
    Screen(pos height, pos width, char c):mHeight(height), mWidth(width) {}
private:
    pos mCursor = 0;
    pos mHeight = 0; 
    pos mWidth = 0;
    std::string mContents;
};

int main() {

    printf("sizeof(Screen):%d \n", sizeof(Screen));
    return 0;
}