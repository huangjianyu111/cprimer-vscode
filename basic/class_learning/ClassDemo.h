#include <vector>
#include <string>
#include <stdio.h>
#include <memory>

namespace hjy_test {
struct DecoderStatusListener;

    // add by hjy
enum class RTPCodecFormat {
    HEVC_H265 = 1,
    AVC_H264 = 2,
};

// add by hjy, add listener for decoder restart
    struct DecoderStatusListener {
        virtual ~DecoderStatusListener() = default;
        /*
        * @param val
        * @return val, val = 1 means decoder restart, 0 means not restart
        */
        virtual int onDecodeRestart(int val) = 0;

        /*
        * @param format
        * @return format, which symbol codec format
        */
        virtual RTPCodecFormat onCodecFormatSure(RTPCodecFormat format) = 0;
    };

    // // add for  monitor decoder status 
    std::shared_ptr<DecoderStatusListener>  mDecoderListener = nullptr;

// add listener, timely tell camx codec format
    // add for  monitor decoder status 
    // use after StreamSession::setUpDecoder TODO
    int setDecoderStatusListener(std::shared_ptr<DecoderStatusListener> listener) {
        mDecoderListener = listener;
        return 0;
    }


class Test {
public:
    static int gNum;

private:
    int num;
    std::string name;
};

};