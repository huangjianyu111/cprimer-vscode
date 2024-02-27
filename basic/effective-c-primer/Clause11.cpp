#include <iostream>
#include <string>
#include <cstring>
#include <mutex>

// 011 为需要动态分配内存的类声明一个拷贝构造函数和一个赋值操作符
class String {
public:
    String(const char *value);
    ~String();
    

public:
    char *data;
};

String::String(const char * value) {
    if (value) {
        data = new char[sizeof(value) + 1];
        std::strcpy(data, value);
    } else {
        data = new char[1];
        *data = '\0';
    }
}

inline String::~String() {
    delete [] data;
}

int main() {

    String strA("Hello");
    String strB("World");
    std::cout << strA.data<< " " << strB.data << std::endl;

    // dangerous operation
    // 1) 原先 strB 所指向的内存永远不会被释放
    // 2) strB、strA 指向同一个String 对象，那么其中一个离开了它的生存空间，
    //    其 析构函数 就会删除掉另一个指针还指向的那块内存
    strB = strA;

    return 0;
}