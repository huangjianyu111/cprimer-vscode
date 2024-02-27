#include <map>
#include <stdlib.h>

int main() {
    std::map<int, std::string> mapDemo;
    mapDemo.emplace(std::make_pair(1, "h"));
    mapDemo.emplace(std::make_pair(3, "l"));
    mapDemo.emplace(std::make_pair(5, "0"));
    mapDemo.emplace(std::make_pair(2, "e"));
    mapDemo.emplace(std::make_pair(4, "l"));
    // 1 2 3 4 5 
    for (const auto&ele:mapDemo) {
        printf("%d ", ele.first);
    }
    printf("\n");
    return 0;
}