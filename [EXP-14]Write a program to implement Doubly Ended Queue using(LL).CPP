#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Deque class
class Deque {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Deque() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Check if the deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Insert an element at the front of the deque
    void pushFront(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = front;
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    // Insert an element at the back of the deque
    void pushBack(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = rear;
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Remove an element from the front of the deque
    int popFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        Node* temp = front;
        int data = temp->data;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            if (front)
                front->prev = nullptr;
        }
        delete temp;
        size--;
        return data;
    }

    // Remove an element from the back of the deque
    int popBack() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        Node* temp = rear;
        int data = temp->data;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            if (rear)
                rear->next = nullptr;
        }
        delete temp;
        size--;
        return data;
    }

    // Get the front element of the deque
    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Get the back element of the deque
    int getBack() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return rear->data;
    }

    // Print the contents of the deque
    void printDeque() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque deque;
    deque.pushFront(10);
    deque.pushBack(20);
    deque.pushFront(5);
    deque.pushBack(30);
    cout << "Deque after insertion: ";
    deque.printDeque();
    cout << "Front element: " << deque.getFront() << endl;
    cout << "Back element: " << deque.getBack() << endl;
    deque.popFront();
    deque.popBack();
    cout << "Deque after deletion: ";
    deque.printDeque();
    return 0;
}
