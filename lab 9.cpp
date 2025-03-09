///Lab 9 - Circular Linked List (Insert & Display Nodes)  
//Task: Implement functions to insert node at first, last, Nth location, and centre of a circular linked list.
// And display in order and display in reverse order.
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
        data = d;
        next = prev = NULL;
    }
};

class CircularDoublyLinkedList {
public:
    Node* head;

    CircularDoublyLinkedList() {
        head = NULL;
    }

   
    void insertAtFirst(int d) {
        Node* newNode = new Node(d);
        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        Node* tail = head->prev; 
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode; 
    }

    void insertAtLast(int d) {
        Node* newNode = new Node(d);
        if (head == NULL) {
            insertAtFirst(d);
            return;
        }

        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    void insertAtNth(int d, int pos) {
        if (pos <= 1) {
            insertAtFirst(d);
            return;
        }

        Node* newNode = new Node(d);
        Node* temp = head;
        int count = 1;

        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void insertAtCenter(int d) {
        if (head == NULL) {
            insertAtFirst(d);
            return;
        }

        Node* slow = head;
        Node* fast = head;
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }

        insertAtNth(d, 2); 
    }

    void displayForward() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Forward: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void displayReverse() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head->prev;
        cout << "Reverse: ";
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != head->prev);
        cout << endl;
    }
};

int main() {
    CircularDoublyLinkedList list;

    list.insertAtFirst(10);
    list.insertAtFirst(5);
    list.insertAtLast(15);
    list.insertAtLast(20);
    list.insertAtNth(12, 3);
    list.insertAtCenter(8);

    cout << "Displaying Circular Linked List:" << endl;
    list.displayForward();
    list.displayReverse();

    return 0;
}
