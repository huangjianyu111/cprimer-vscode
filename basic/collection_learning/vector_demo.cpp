#include <vector>
#include <iostream>
using namespace std;

void printVec(vector<int> nums) {
    for (const auto & num:nums) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

int main() {
    vector<int> nums(10,1);
    printf("nums capacity : %d \n", nums.capacity());//10

    nums.push_back(11);
    printVec(nums); // 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11,
    printf("nums capacity : %d \n", nums.capacity());//20
    // reduce capacity() to size()
    
    nums.shrink_to_fit();
    printf("nums capacity : %d \n", nums.capacity());//11

    nums.assign(3,2);
    printVec(nums);
    printf("nums capacity : %d \n", nums.capacity());// 2, 2, 2,
    return 0;
}