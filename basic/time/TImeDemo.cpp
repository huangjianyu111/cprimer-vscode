#include <iostream>
#include <vector>



int main() {
    int width = 1024;
    int height = 1024;
    std::vector<uint8_t> pixels(width * height * 4);
    std::cout << sizeof(uint32_t) << ", ";

    return 0;
}