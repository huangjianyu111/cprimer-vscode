#include <iostream>
#include <string>

int main() {
    // int id = 10;
    // char* name;
    // std::sprintf(name, "stram-%d-monitor", id);

    // std::cout << "name : " << name << std::endl;

    char *str = "hello world";
    // 1、Using the “=” operator
    std::string name2 = str;

    std::cout << name2 << std::endl;

    // 2 Using string constructor
    std::string name3(str);
    std::cout << name3 << std::endl;

    // 3 Using the assign function
    std::string name4;
    name4.assign(str, str + 12);
    std::cout << name4 << std::endl;

    

    return 0;
}