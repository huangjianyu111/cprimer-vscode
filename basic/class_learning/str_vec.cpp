#include <stdio.h>
#include <string>

using namespace std;

class StrVec{
public:
    StrVec();


private:

};

int main() {
    // int &l = 23;// error

    int i = 23;
    int &l = i;

    const int& l2 = 34;
    return 0;
}