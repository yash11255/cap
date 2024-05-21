#include <iostream>
using namespace std;

#define MAX_SIZE 100

class ArrayDeque {
private:
    int deque[MAX_SIZE];
    int front, rear;

public:
    ArrayDeque() {
        front = -1;
        rear = -1;
    }

    // Function to check if the deque is empty
    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    // Function to check if the deque is full
    bool isFull() {
        return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
    }

    // Function to add an element at the front of the deque
    void addFront(int data) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }
        deque[front] = data;
    }

    // Function to add an element at the rear of the deque
    void addRear(int data) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = data;
    }

    // Function to remove an element from the front of the deque
    void removeFront() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    // Function to remove an element from the rear of the deque
    void removeRear() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX_SIZE - 1;
        } else {
            rear--;
        }
    }

    // Function to get the front element of the deque
    int peekFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1;
        }
        return deque[front];
    }

    // Function to get the rear element of the deque
    int peekRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1;
        }
        return deque[rear];
    }

    // Function to display the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }
        cout << "Deque: ";
        int i = front;
        while (true) {
            cout << deque[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

int main() {
    ArrayDeque dq;
    dq.addFront(10);
    dq.addFront(20);
    dq.addRear(30);
    dq.addRear(40);
    dq.display(); // Output: Deque: 20 10 30 40
    dq.removeFront();
    dq.removeRear();
    dq.display(); // Output: Deque: 10 30
    cout << "Front element: " << dq.peekFront() << endl; // Output: Front element: 10
    cout << "Rear element: " << dq.peekRear() << endl; // Output: Rear element: 30
    return 0;
}
