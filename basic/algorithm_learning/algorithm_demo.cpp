#include <stdio.h>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

template<class T>
void printNums(vector<T> & nums) {
    for (const auto& ele : nums) {
        // printf("%d ", ele);
        cout << " " << ele;
    }
    printf("\n");
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,0,3,4,0,0,0,5,6};
    printNums(nums);

    // 把 0 替换成 11， 且不改变原先容器中的值
    vector<int> newNums(nums.size(), 0);// 保证 output的容器大小与原始容器大小相同
    replace_copy(nums.begin(), nums.end(), newNums.begin(), 0, 11);
    printNums(newNums);

    // back_inserter 使用他赋值到新的容器，不需要新的容器 capicity 大于或等于 老的容器
    vector<int> newNums2;
    replace_copy(nums.begin(), nums.end(), back_inserter(newNums2), 0, 12);
    printNums(newNums2);

    // 直接修改原先容器的值
    printf("original nums :");
    printNums(nums);
    replace(nums.begin(), nums.end(), 0, 13);
    printf("new      nums :");
    printNums(nums);

    // -----------------------
    // 稳定排序
    stable_sort(nums.begin(), nums.end());

    // lambda
    vector<string> words = {"hjy", "ttc", "jzx"} ;
    stable_sort(words.begin(), words.end(), [](const string&a, const string&b){return a.size() < b.size();});
    printNums(words);

    stable_sort(words.begin(), words.end());
    printNums(words);

    for_each(words.begin(), words.end(), [](const string& s){cout << " " << s;});

    int x = 0;
    

    return 0;
}