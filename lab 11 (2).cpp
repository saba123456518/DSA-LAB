//#include <iostream>
//using namespace std;


//const int size = 100;
//int queueArray[size];
//int f = -1, rear = -1;
//
//void enqueue(int value) {
//    if (rear == size - 1) {
//        cout << "Queue Overflow";
//    } else {
//        if (f == -1) f = 0;
//        queueArray[++rear] = value;
//    }
//}
//
//void dequeue() {
//    if (f == -1 || f > rear) {
//        cout << "Queue Underflow";
//    } else {
//        cout << "Dequeued: " << queueArray[f++] << endl;
//    }
//}
//void display() {
//    if (f == -1 || f > rear) {
//        cout << "Queue is empty";
//    } else {
//        cout << "Queue elements: ";
//        for (int i = f; i <= rear; i++) {
//            cout << queueArray[i] << " ";
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//    enqueue(10);
//    enqueue(20);
//    enqueue(30);
//    display();
//    dequeue();
//    display();
//    return 0;
//}

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* f = nullptr;
Node* r = nullptr;
//
void enqueue(int v){
	Node* newNode = new Node;
	newNode->data = v;
    newNode->next = nullptr;

    if (r == nullptr) {
        f = r= newNode;
    } else {
        r->next = newNode;
        r = newNode;
    }
}
//
void dequeue() {
    if (f == nullptr) {
        cout << "Queue Underflow";
    } else {
        cout << "Dequeued: " << f->data << endl;
        Node* temp = f;
        f = f->next;
        if (f == nullptr) r = nullptr;
        delete temp;
    }
}

void display() {
    if (f == nullptr) {
        cout << "Queue is empty";
    } else {
        cout << "Queue elements: ";
        Node* current = f;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}
//
int main() {
    enqueue(100);
    enqueue(200);
    enqueue(300);
    display();
    dequeue();
    display();
    return 0;
}
//



