#include <iostream>
#include <stdio.h>

int main() {
    int i = 0;
    bool busy = true;
    while (true) {
        if (busy) {
            i++;
            printf("i = %d\n", i);
        } else {

        }
    }
    return 0;
}