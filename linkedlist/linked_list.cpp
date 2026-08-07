#include <iostream>

class ListedListNode {
    public:
        int data;
        ListedListNode *next;
        ListedListNode(int x) : data(x), next(nullptr) {}
};

class LinkedList {
    public:
        ListedListNode *head;

        LinkedList(int x) {
            head = new ListedListNode(x);
        }

        void insertAtHead(int x) {
            ListedListNode *newNode = new ListedListNode(x);
            newNode->next = head;
            head = newNode;
        }

        void insertAtBack(int x) {
            ListedListNode *newNode = new ListedListNode(x);
            if (head == nullptr) {
                head = newNode;
                return;
            }
            ListedListNode *current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        void insertAtPos(int pos, int x) {
            if (pos <= 0 || head == nullptr) {
                insertAtHead(x);
                return;
            }
            ListedListNode *current = head;
            for (int i = 0; i < pos - 1 && current->next != nullptr; i++) {
                current = current->next;
            }
            ListedListNode *newNode = new ListedListNode(x);
            newNode->next = current->next;
            current->next = newNode;
        }

        void deleteAtHead() {
            if (head == nullptr) return;
            ListedListNode *toDelete = head;
            head = head->next;
            delete toDelete;
        }

        void deleteAtBack() {
            if (head == nullptr) return;
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
                return;
            }
            ListedListNode *current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }

        void deleteAtPos(int pos) {
            if (head == nullptr) return;
            if (pos <= 0) {
                deleteAtHead();
                return;
            }
            ListedListNode *current = head;
            for (int i = 0; i < pos - 1 && current->next != nullptr; i++) {
                current = current->next;
            }
            if (current->next == nullptr) return;
            ListedListNode *toDelete = current->next;
            current->next = toDelete->next;
            delete toDelete;
        }

        int search(int x) {
            ListedListNode *current = head;
            int pos = 0;
            while (current != nullptr) {
                if (current->data == x) return pos;
                current = current->next;
                pos++;
            }
            return -1;
        }

        void printLinkedList() {
            ListedListNode *current = this->head;
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }

        int getSize() {
            int size = 0;
            ListedListNode *current = head;
            while (current != nullptr) {
                size++;
                current = current->next;
            }
            return size;
        }
};

int main() {
    LinkedList list(10);

    list.insertAtHead(0);
    list.insertAtBack(20);
    list.insertAtPos(1, 5);
    list.printLinkedList();

    std::cout << "search(5): " << list.search(5) << std::endl;
    std::cout << "search(99): " << list.search(99) << std::endl;

    list.deleteAtPos(1);
    list.printLinkedList();

    list.deleteAtHead();
    list.printLinkedList();

    list.deleteAtBack();
    list.printLinkedList();

    std::cout << "Size of linked list: " << list.getSize() << std::endl;

    return 0;
}
