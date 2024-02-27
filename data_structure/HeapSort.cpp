#include <iostream>
#include <stdio.h>
#include <algorithm>

#include <array>
#include <vector>

using namespace std;

int main() {
    std::vector<int> vec(10,1);
    int count = 0;
    for (auto& e:vec) {
        count++;
        e *= count;
        printf("%d, ", e);
    }
    printf("\n");

    // cbegin\cend print
    for (auto iter = vec.cbegin();iter != vec.cend();iter++) {
        printf("%d, ", *iter);
    }
    printf("\n");

    // reversed print
    // rbegin
    for (auto iter = vec.rbegin();iter != vec.rend();iter++) {
        printf("%d, ", *iter);
    }
    printf("\n");

    auto is_even = [](int i) { return i % 2 == 0; };
 
    for (auto const& w : {std::array<int, 3>{3, 1, 4}, {1, 3, 5}})
        if (auto it = std::find_if(begin(w), end(w), is_even); it != std::end(w))
            std::cout << "w contains an even number " << *it << '\n';
        else
            std::cout << "w does not contain even numbers\n";


    return 0;
}