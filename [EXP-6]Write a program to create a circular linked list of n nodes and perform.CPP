#include <iostream>

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Circular linked list class
class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularLinkedList() : head(nullptr) {}

    // Destructor
    ~CircularLinkedList() {
        if (!head)
            return;
        
        Node* current = head->next;
        while (current != head) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
    }

    // Function to insert at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode; // Circular link to itself
            head = newNode;
        } else {
            newNode->next = head->next;
            head->next = newNode;
        }
    }

    // Function to insert at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode; // Circular link to itself
            head = newNode;
        } else {
            newNode->next = head->next;
            head->next = newNode;
            head = newNode;
        }
    }

    // Function to insert at a specific location
    void insertAtLocation(int val, int pos) {
        if (pos <= 0) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
        if (pos == 1) {
            insertAtBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp && temp->next != head; ++i) {
            temp = temp->next;
        }
        if (!temp || temp->next == head) {
            std::cout << "Position out of range." << std::endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete from the beginning
    void deleteFromBeginning() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        if (head->next == head) { // Only one node
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head->next;
        head->next = temp->next;
        delete temp;
    }

    // Function to delete from the end
    void deleteFromEnd() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        if (head->next == head) { // Only one node
            delete head;
            head = nullptr;
            return;
        }
        Node* prev = nullptr;
        Node* temp = head->next;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
    }

    // Function to delete from a specific location
    void deleteFromLocation(int pos) {
        if (pos <= 0 || !head) {
            std::cout << "List is empty or invalid position." << std::endl;
            return;
        }
        if (pos == 1) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        for (int i = 1; i < pos && temp && temp->next != head; ++i) {
            prev = temp;
            temp = temp->next;
        }
        if (!temp || temp->next == head) {
            std::cout << "Position out of range." << std::endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    // Function to display the circular linked list
    void display() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = head->next;
        std::cout << head->data << " ";
        while (temp != head) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    CircularLinkedList list;
    // Insertion at the beginning
    list.insertAtBeginning(1);
    list.insertAtBeginning(2);
    list.insertAtBeginning(3);
    std::cout << "List after insertion at the beginning: ";
    list.display();
    // Insertion at the end
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);
    std::cout << "List after insertion at the end: ";
    list.display();
    // Insertion at a specific location
    list.insertAtLocation(10, 3);
    std::cout << "List after insertion at position 3: ";
    list.display();
    // Deletion from the beginning
    list.deleteFromBeginning();
    std::cout << "List after deletion from the beginning: ";
    list.display();
    // Deletion from the end
    list.deleteFromEnd();
    std::cout << "List after deletion from the end: ";
    list.display();
    // Deletion from a specific location
    list.deleteFromLocation(3);
    std::cout << "List after deletion from position 3: ";
    list.display();
    return 0;
}
