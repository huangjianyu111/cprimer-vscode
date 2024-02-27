#include <set>
#include <map>
#include <stdio.h>

using namespace std;

int main() {
    std::multimap<int, int> nums;
    nums.emplace(pair<int, int>{1,2});
    nums.emplace(pair<int, int>{1,3});
    nums.emplace(pair<int, int>{1,4});
    nums.emplace(pair<int, int>{1,2});

    nums.emplace(pair<int, int>{11,2});

    nums.emplace(pair<int, int>{12,2});

    printf("nums count : %d  \n", nums.count(1));

    for(auto &num : nums) {
        printf("num : %d %d, addr : %p \n", num.first, num.second, num);
    }
    return 0;
}