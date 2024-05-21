#include <iostream>
using namespace std;

// Node structure for the Circular Queue Linked List
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularQueueLinkedList {
private:
    Node* front;
    Node* rear;

public:
    CircularQueueLinkedList() : front(nullptr), rear(nullptr) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to add an element to the queue
    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front; // Make the new node point to itself in a circular manner
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Make rear point back to front in a circular manner
        }
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        if (front == rear) {
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            rear->next = front; // Update rear to point back to front after dequeueing
        }
    }

    // Function to get the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    // Function to display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        Node* current = front;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);
        cout << endl;
    }
};

int main() {
    CircularQueueLinkedList cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.display(); // Output: Queue: 10 20 30 40
    cq.dequeue();
    cq.dequeue();
    cq.display(); // Output: Queue: 30 40
    cout << "Front element: " << cq.peek() << endl; // Output: Front element: 30
    return 0;
}
