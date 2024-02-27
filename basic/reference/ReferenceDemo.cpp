#include <iostream>

using namespace std;

void func(int &x, int y) {
    x++;
    y++;
    cout << "x = " << x << ", y = " << y << endl;
}

int main() {
    int x = 10;
    int y = 10;
    func(x, y);



    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}