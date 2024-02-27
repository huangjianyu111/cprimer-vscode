#include <iostream>

void print(int arr*, int row, int col) {
    return 0;
}

int main() {
    int ia[3][4] = {

    {1, 2, 3, 4},

    { 1, 2, 3, 4 },

    { 1, 2, 3, 4 },

    }

    // 遍历
    int count = 0;
    for (auto& row:ia) {
        for (auto& col:row) {
            col = count++;
        }
    }


    return 0;
}

