#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* head;
    int num;
    int capacity;

public:
    Stack(int initialCapacity) {
        head = nullptr;
        num = -1;
        capacity = initialCapacity;
    }

    // push
    void push(int x) {
        if (num == capacity - 1) {
            increaseCapacity();
        }

        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = head;
        head = newNode;
        num++;
    }

    // pop
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        Node* temp = head;
        int poppedValue = head->data;
        head = head->next;
        delete temp;
        num--;

        return poppedValue;
    }

    // peek
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return head->data;
    }

    // isEmpty
    bool isEmpty() {
        return num < 0;
    }

    // increaseCapacity
    void increaseCapacity() {
        capacity *= 2;
    }

    // deleteElement
    bool deleteElement(int val) {
        if (isEmpty()) {
            return false;
        }

        // if the element to delete is at the top of the stack
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            num--;
            return true;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == val) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                num--;
                return true;
            }
            current = current->next;
        }

        return false;  // element not found
    }
};

int main() {
    Stack s(5);  // create a stack with initial capacity of 5

    // test the push operation
    s.push(10);
    s.push(20);
    s.push(30);

    // test peek operation
    cout << "Top element: " << s.peek() << endl;  // should print 30

    // test pop operation
    cout << "Popped element: " << s.pop() << endl;  // should print 30

    // test deleteElement operation
    cout << "Deleting element 20: " << (s.deleteElement(20) ? "Success" : "Failure") << endl;


    return 0;
}
