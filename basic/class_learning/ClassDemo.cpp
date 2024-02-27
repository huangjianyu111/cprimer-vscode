#include <iostream>
#include <string>

#include "ClassDemo.h"

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
        printf(" %s val : %d \n", __FUNCTION__, static_cast<int>(format));
        switch(format) {
            case hjy_test::RTPCodecFormat::HEVC_H265:
                printf("HEVC, %s val : %d \n", __FUNCTION__, static_cast<int>(format));
                break;
            case RTPCodecFormat::AVC_H264:
                printf("AVC, %s val : %d \n", __FUNCTION__, static_cast<int>(format));
                break;
            

        }
        return format;
    }
};

int Test::gNum = 0;


};

// 1、处于统一编程风格的考虑，当我们希望定义的类的所有成员是public的时，使用struct；反之使用class

// 2、在类内部的函数默认是内联的，

// 3、friend 友元
//    友元申明只能出现在类定义的内部，具体出现的位置不限

// 4、IO 类型不能拷贝，作为函数参数，需要传递引用类型
struct Sales_data {

    // 一旦定义了构造函数，就不会有缺省的无参构造函数
    Sales_data() = default;
    Sales_data(const string&s);


    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

};

int main() {
    Sales_data salesData;
    cout << "bookNo : " << salesData.bookNo << ", units_sold : " << salesData.units_sold << 
        ", revenue : " << salesData.revenue << endl;

    int x = 10;
    int y = x;
    int z = std::move(x);
    cout << "x addr : " << (&x) << endl;
    cout << "y addr : " << (&y) << endl;
    cout << "z addr : " << (&z) << endl;

    return 0;
}