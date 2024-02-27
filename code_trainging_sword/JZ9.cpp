#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int res;
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
            
        res = stack2.top();
        stack2.pop();
        return res;
        
    }

private:
    stack<int> stack1;//push
    stack<int> stack2;//pop
};

int main() {

    return 0;
}