#include <set>
#include <iostream>
#include <stdio.h>

using namespace std;

void print(const multiset<int, std::greater<int>> &nums) {
    for (const int &ele:nums) {
        printf("%d, ", ele);;
    }
    printf("\n");
}

int main() {
    multiset<int, std::greater<int>> setDemo;
    setDemo.emplace(3);
    setDemo.emplace(13);
    setDemo.emplace(23);
    setDemo.emplace(1);
    setDemo.emplace(31);
    setDemo.emplace(1);
    setDemo.emplace(4);
    setDemo.insert(6);

    // 输出 set中的元素
    // 1, 3, 4, 13, 23, 31,
    print(setDemo);
    return 0;
}