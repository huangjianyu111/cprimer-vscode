#include <iostream>
#include <vector>

using namespace std;
int main() {

    int x = 10;
    const int &x2 = x;

    cout << "x = " << x << ", x2 = " << x2 << endl;

    // x2 = 11; // error
    x = 11;
    cout << "x = " << x << ", x2 = " << x2 << endl;

    int &x3 = x;
    x3 = 111;
    cout << "x = " << x << ", x2 = " << x2 << ", x3 = " << x3 << endl;
    return 0;
}