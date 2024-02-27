#include <vector>
#include <string>

#include "ClassDemo.h"

namespace hjy_test {



    // add by hjy, add listener for stream stuck
    struct StreamStatusListener {
        virtual ~StreamStatusListener() = default;
        /*
        * @param val
        * @return val, val = 1 means stuck, 0 means not stuck
        */
        virtual int onStreamStuck(int val) = 0;

        /*
        * @param format
        * @return format, which symbol codec format
        */
        virtual RTPCodecFormat onCodecFormatSure(RTPCodecFormat format) = 0;
    };

};