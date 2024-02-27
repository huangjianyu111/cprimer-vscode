#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int x = 10;
    auto addTest = [x](){return x;};

    x = 0;
    auto res = addTest();
    printf("x = %d \n", res);// x = 10

    
}