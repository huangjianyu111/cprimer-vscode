#include <string>
#include <cstring>
#include <stdio.h>

int main() {
    // 1、字符串的 初始化
    std::string s1 = "Hellor World";
    std::string s2(s1);
    std::string s3 = s2;
    std::string s4;
    s4.assign(s3.begin(), s3.end());
    std::string s5(s4, 7);// 从下标7开始拷贝
    printf("s5:%s \n", s5.c_str());

    char ch[] = "Hello World";
    std::string s6(ch, 12);// 拷贝 数组 ch的前12个字符
    printf("s6:%s \n", s6.c_str());

    std::string s7(ch);
    printf("s7:%s \n", s7.c_str());

    // 获取子字符串
    std::string subString1 = s7.substr(1, 7);// pos(default 0), nums
    printf("subString1:%s \n", subString1.c_str());

    // 搜索
    int index = s7.find_first_of('l');
    printf("s7.find_first_of('l') : %d \n", index);//2

    // 替换
    s7.replace(2, 3, "hjy");// pos, n, replace string
    printf("s7:%s \n", s7.c_str());//s7:Hehjy World

    s7.replace(2, 3, "123456");// pos, n, replace string
    printf("s7:%s \n", s7.c_str());//s7:He123456 World

    // 比较
    // s6:Hello World
    // s7:He123456 World
    if (s6 == s7) {
        printf("s6==s7\n");
    } else {
        printf("s6!=s7\n");
    }

    printf("s6.compare(s7) result:%d \n", s6.compare(s7));// 1 , s6 > s7

    // 0, 表示相等
    printf("s6.compare(0, 2, s7, 0, 2) result:%d \n", s6.compare(0, 2, s7, 0, 2));

    // std::string subString2 = s7.substr(s7.begin(), s7.begin() + 8);
    // printf("subString2:%s \n", subString2.c_str());

    // 数值转换
    // 数字转换为字符串
    printf("std::to_string(123) : %s \n", std::to_string(123).c_str());

    // char 数组转换为 字符串
    char * str = "Hello World!";
    std::string s(str);
    printf("s : %s \n", s.c_str());

    printf("((std::string)(str)).c_str() : %s \n", ((std::string)(str)).c_str());


    return 0;
}