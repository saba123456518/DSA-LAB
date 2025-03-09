Lab 7 - Doubly Linked List (Insert & Display Nodes)  
Task: Implement functions to insert node at first, last, Nth location, and centre of a doubly linked list. And display in
 order and display in reverse order.


#include<iostream>
using namespace std;
class Node;
Node* head = NULL;
class Node {
    int roll;
    string name;
    float cgpa;
    string email;
    Node* next;
    Node* prev;

public:
    Node(int r, string n, float c, string e) {
        roll = r;
        name = n;
        cgpa = c;
        email = e;
        next = NULL;
        prev = NULL;
    }
    void insert_at_start(int r, string n, float c, string e) {
        Node* newNode = new Node(r, n, c, e);
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
    }

    void insert_at_last(int r, string n, float c, string e) {
        Node* newNode = new Node(r, n, c, e);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
//
    void insert_at_any_pos(int pos, int r, string n, float c, string e) {
        Node* newNode = new Node(r, n, c, e);
        Node* temp = head;
        if (pos < 1) {
            cout << "invalid";
        } else if (pos == 1) {
            insert_at_start(r, n, c, e);
        } else {
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->next;
                if (temp == NULL) {
                    break;
                }
            }
            if (temp != NULL) {
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next != NULL) {
                    temp->next->prev = newNode;
                }
                temp->next = newNode;
            }
        }
    }

   
    void display() {
        if (head != NULL) {
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->roll << " " << temp->name << " " << temp->cgpa << " " << temp->email << endl;
                temp = temp->next;
            }
        }
    }
};

int main() {
    Node* head = NULL;
    head->insert_at_start(1, "ayesha", 3.2, "ayesha@gmail.com");
    head->insert_at_last(2, "asim", 3.8, "asim@gmail.com");
    head->insert_at_last(3, "fahad", 3.7, "fahad@gmail.com");
    head->insert_at_last(4, "saira", 3.9, "saira@gmail.com");
    head->insert_at_any_pos(3, 5, "Zain", 3.6, "zain@gmail.com");
//    head->insert_at_center(35);

    cout << "Doubly Linked List:" << endl;
    head->display_forward();
    list.display_reverse();

    return 0;
}
    head->display();
}
	
////	
	
//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node* next;
//    Node* prev;
//
//    Node(int d) {
//        data = d;
//        next = NULL;
//        prev = NULL;
//    }
//};
//
//class DoublyLinkedList {
//public:
//    Node* head;
//    Node* tail;
//    int size;  // Track the size of the list
//
//    DoublyLinkedList() {
//        head = NULL;
//        tail = NULL;
//        size = 0;
//    }
//
//    // Insert at the beginning
//    void insert_at_first(int d) {
//        Node* newNode = new Node(d);
//        if (head == NULL) {  
//            head = tail = newNode;
//        } else {
//            newNode->next = head;
//            head->prev = newNode;
//            head = newNode;
//        }
//        size++;
//    }
//
//    // Insert at the end
//    void insert_at_last(int d) {
//        Node* newNode = new Node(d);
//        if (head == NULL) {
//            head = tail = newNode;
//        } else {
//            tail->next = newNode;
//            newNode->prev = tail;
//            tail = newNode;
//        }
//        size++;
//    }
//
//    // Insert at the Nth position
//    void insert_at_nth_position(int pos, int d) {
//        if (pos < 1 || pos > size + 1) {
//            cout << "Invalid position!" << endl;
//            return;
//        }
//        if (pos == 1) {
//            insert_at_first(d);
//            return;
//        }
//        if (pos == size + 1) {
//            insert_at_last(d);
//            return;
//        }
//
//        Node* newNode = new Node(d);
//        Node* temp = head;
//        for (int i = 1; i < pos - 1; i++) {
//            temp = temp->next;
//        }
//        newNode->next = temp->next;
//        newNode->prev = temp;
//        if (temp->next != NULL) {
//            temp->next->prev = newNode;
//        }
//        temp->next = newNode;
//        size++;
//    }
//
//    // Insert at the center (Fixed version)
//    void insert_at_center(int d) {
//        if (size == 0) {
//            insert_at_first(d);
//            return;
//        }
//        int mid = (size / 2) + 1; // Correctly calculate the middle position
//        insert_at_nth_position(mid, d);
//    }
//
//    // Display list in forward order
//    void display_forward() {
//        if (head == NULL) {
//            cout << "List is empty!" << endl;
//            return;
//        }
//        Node* temp = head;
//        cout << "Forward: ";
//        while (temp != NULL) {
//            cout << temp->data << " ⇄ ";
//            temp = temp->next;
//        }
//        cout << "NULL" << endl;
//    }
//
//    // Display list in reverse order
//    void display_reverse() {
//        if (tail == NULL) {
//            cout << "List is empty!" << endl;
//            return;
//        }
//        Node* temp = tail;
//        cout << "Reverse: ";
//        while (temp != NULL) {
//            cout << temp->data << " ⇄ ";
//            temp = temp->prev;
//        }
//        cout << "NULL" << endl;
//    }
//};
//
//int main() {
//    DoublyLinkedList list;
//
//    // Insert at first
//    list.insert_at_first(10);
//    list.insert_at_first(20);
//    list.insert_at_first(30);
//
//    // Insert at last
//    list.insert_at_last(40);
//    list.insert_at_last(50);
//
//    // Insert at Nth position (3rd position)
//    list.insert_at_nth_position(3, 25);
//
//    // Insert at the center (Fixed)
//    list.insert_at_center(35);
//
//    // Display forward and reverse
//    cout << "Doubly Linked List:" << endl;
//    list.display_forward();
//    list.display_reverse();
//
//    return 0;
//}
