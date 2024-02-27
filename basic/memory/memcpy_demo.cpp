#include <stdio.h>
#include <iostream>

/**
 * Defined in header <cstring>
void* memcpy( void* dest, const void* src, std::size_t count );

*/

int main() {
    char* source = "Hello World";
    char dest1[4];
    char dest2[4];
    // char 数组需要预留一个字符，作为结束符

    printf("sizeof(dest1):%d\n", sizeof(dest1));

    //注意如用sizeof(dest)，会造成b的内存地址溢出
    memcpy(dest1, source, sizeof(dest1));//dest:Hell@@
    printf("dest1:%s\n", dest1);

    memcpy(dest2, source, 3);//dest:Hell@@
    printf("dest2:%s\n", dest2);//dest2:Hel

    char dest3[4];
    for (int i = 0;i < sizeof(dest3) - 1;i++) {
        dest3[i] = 's';
    }
    printf("dest3:%s\n", dest3);

    for (int i = 0;i < sizeof(dest3);i++) {
        dest3[i] = 's';
    }
    // char数组没有预留字符，作为string输出，直到遇到\0才会结束，会越界
    printf("dest3:%s\n", dest3);

    return 0;
}