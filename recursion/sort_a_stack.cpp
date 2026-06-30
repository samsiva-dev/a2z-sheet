#include <iostream>
#include <stack>

void insertAtSortedPosition(std::stack<int> &stk, int x) {
    if (stk.empty() || stk.top() <= x) {
        stk.push(x);
        return;
    }

    int top = stk.top();
    stk.pop();
    insertAtSortedPosition(stk, x);
    stk.push(top);
}

void sortStack(std::stack<int> &stk) {
    if (stk.empty()) {
        return;
    }

    int top = stk.top();
    stk.pop();
    sortStack(stk);
    insertAtSortedPosition(stk, top);
}

int main() {
    std::stack<int> stk;
    stk.push(2);
    stk.push(3);
    stk.push(1);
    stk.push(4);

    sortStack(stk);

    while (!stk.empty()) {
        std::cout << stk.top() << "\n";
        stk.pop();
    }

    return 0;
}
