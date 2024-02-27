#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>

using namespace std;

int main() {

    // // iostream
    // cout << "please input your name: " << endl;

    // std::string name;
    // cin >> name;

    // cout << "name : " << name << endl;

    // fstream, file operation
    std::ifstream in;
    const char *path = "D:\\07-log\\log_0829_ok1.txt";
    in.open(path, std::ios::in);
    char s[256];
    if (in.is_open()) {
        for (int i = 0;i < 10;i++) {
            in.getline(s, 255);
            printf("line : %s \n", s);
        }
        
    }

    ifstream in2(path);

    // sstream demo
    std::ostringstream outStrStream;
    outStrStream << "Hello World" << " + " << "hjy";
    std::string str2 = outStrStream.str();
    printf("str2 : %s \n", str2.c_str());

    return 0;
}
