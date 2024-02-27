#include <vector>
#include <stdio.h>
#include <string>
#include <cstring>

// 容器输出
template<class Object>
int compare(const Object& a1, const Object& a2) {
    if (a1 > a2) {
        return 1;
    } else if (a1 < a2) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    printf("compare(1, 2) result: %d \n", compare(1, 2));
    printf("compare(1, 2) result: %d \n", compare(1.1, 2.1));
    printf("compare(1, 2) result: %d \n", compare('b', 'a'));

    return 0;
}