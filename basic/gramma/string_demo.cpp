#include <string>
#include <cstring>
#include <iostream>

int main() {
    char s[8] = {'G','o','o','d','!', '\0'};
    std::strcpy(s, "Good!");
    //s = "Good!"; s need 6 size

    char s2[8] = "Good!";

    char a[] = "abc123";
    char b[] = "xyz";
    printf("strcat(a, b) : %s \n", std::strcat(a, b));// 内存溢出

    std::string line;

    printf("line max_size : %d \n", line.max_size());
    while(std::getline(std::cin, line)) {
        std::cout <<  "cout << " << line << std::endl;
        if (line.compare("#") == 0) break;
    }
    printf("line capacity : %d \n", line.capacity());

    return 0;
}