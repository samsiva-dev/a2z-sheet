#include <iostream>
#include <vector>
#include <stdexcept>

class Queue {
    private:
        std::vector<int> queue;

    public:
        void enqueue(int x) {
            queue.push_back(x);
        }

        int dequeue() {
            if (isEmpty()) {
                throw std::underflow_error("Queue is empty");
            }
            int val = queue.at(0);
            queue.erase(queue.begin());
            return val;
        }

        int front() {
            if (isEmpty()) {
                throw std::underflow_error("Queue is empty");
            }
            return queue.front();
        }

        bool isEmpty() {
            return queue.empty();
        }
};

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.front() << std::endl;
    std::cout << "Is Empty: " << queue.isEmpty() << std::endl;

    return 0;
}
