#include <stdio.h>

using namespace std;

/**
 * 
 * -c

只激活预处理,编译,和汇编,也就是他只把程序做成obj文件

例子用法:

gcc -c demo.cpp -o demo.o
他将生成 .o 的 obj 文件

-S

只激活预处理和编译，就是指把文件编译成为汇编代码。

例子用法:

gcc -S demo.cpp -o demo.txt
*/

int main() {
    bool busy = true;
    int i = 0;
    while(true) {
        if (busy) {
            i++;
            printf(" try to contro cpu, i = %d \n", i);
        }
    }
}