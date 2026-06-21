#include <iostream>
#include <stack>


std::stack<int> reverseStack(std::stack<int>& s) {
    std::stack<int> reversed_stack;

    while (!s.empty()) {
        reversed_stack.push(s.top());
        s.pop();
    }

    return reversed_stack;
}

int main() {
    std::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::stack<int> rs = reverseStack(s);
    while (!rs.empty()) {
        std::cout << rs.top() << " ";
        rs.pop();
    }
    return 0;
}
