#include <iostream>
#include <functional>

using namespace std;
// C 语言 常用 宏定义 取代一些简单函数，看起来像函数又不会导致函数调用
#define max1(a,b) ((a) > (b) ? (a) : (b))

/**
 * inline 函数由 inline 关键字定义，引入 inline 函数的主要原因是用它替代 C 中复杂易错、不易维护的宏函数
*/
template <typename T>
const T& max2(const T& a, const T& b) {return (a > b) ? a : b;}

template <typename T>
T& max3(T& a, T& b) {return (a > b) ? a : b;}

int main() {
    int a = 6;
    int b = 1;
    max1(++a,++b);//a = 8, b = 1; a > b, a的值增加了 2 次

    cout << "a = " << a <<", b = " << b << endl; // a = 8, b = 2

    b = 10;
    max1(++a,++b);//a = 9, b = 12; b > a, b的值增加了 2 次

    cout << "a = " << a <<", b = " << b << endl; // a = 8, b = 4


    cout << "max2<int>(103,3) : " << max2(103, 10) << endl;

    // cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    //cout << "max2<int>(103,3) : " << max3(103, 10) << endl;

    a = 103;
    b = 3;
    cout << "max3<int>(103,3) : " << max3((int&)(a), (int&)(b)) << endl;

    // initializing argument 1 of 'T& max3(T&, T&) [with T = std::reference_wrapper<int>]'   // error
    // cout << "max3<int>(103,3) : " << max3(ref(a), ref(b)) << endl;


    // cout << "max3<int>(10,1) : " << max3(ref(10), ref(1)) << endl;

}
