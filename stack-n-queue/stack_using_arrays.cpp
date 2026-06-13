#include <iostream>
#include <stdexcept>
#include <vector>

class Stack {
private:
    std::vector<int> stack;

public:
    void push(int x) {
        stack.push_back(x);
    }

    int pop() {
        if (isEmpty()) throw std::underflow_error("pop on empty stack");
        int val = stack.back();
        stack.pop_back();
        return val;
    }

    int top() {
        if (isEmpty()) throw std::underflow_error("top on empty stack");
        return stack.back();
    }

    bool isEmpty() const {
        return stack.empty();
    }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    std::cout << stack.pop() << std::endl;  // 4
    std::cout << stack.top() << std::endl;  // 3
    std::cout << "Is Empty: " << stack.isEmpty() << std::endl;  // 0
}
