
//Lab 8 - Merge two LinkedLists  
//Task: 
//1. Create 2 Singly LinkedLists and Merge them and display them.
//2. Create 2 Double LinkedLists and Merge them and display them.
//


//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node* next;
//
//    Node(int d) {
//        data = d;
//        next = nullptr;
//    }
//};
////
//class singlyLinkedList {
//public:
//    Node* head;
//    
//   singlyLinkedList() {
//        head = NULL;
//    }
//    void insert_at_end(int d) {
//        Node* newNode = new Node(d);
//        
//        if (head == NULL) {  
//            head = newNode;
//            return;
//        }
////
//        Node* temp = head;
//        while (temp->next != NULL) {  
//            temp = temp->next;
//        }
//        
//        temp->next = newNode;  
//    }
////
//
//    void display() {
//        Node* temp = head;
//        while (temp != NULL) {
//            cout << temp->data << " -> ";
//            temp = temp->next;
//        }
//        cout << "NULL" << endl;
//    }
//    void merge(singlyLinkedList& list2) {
//    	if (head == NULL){
//    		head = list2.head;
//    		return ;
//		}
//		 Node* temp = head;
//        while (temp->next != NULL) {  
//            temp = temp->next;
//        }
//        temp->next = list2.head;
//        
//	}  
//};
// int main(){
//  singlyLinkedList list1 , list2;
//   list1.insert_at_end(1);
//    list1.insert_at_end(3);
//    list1.insert_at_end(5);
//
//    
//    list2.insert_at_end(2);
//    list2.insert_at_end(4);
//    list2.insert_at_end(6);
// 
//  
//   cout << "First Singly Linked List: ";
//    list1.display();
//    
//    cout << "Second Singly Linked List: ";
//    list2.display();
//
//    
//    list1.merge(list2);
//
//
//    cout << "Merged Singly Linked List: ";
//    list1.display();
//
//    return 0;
//}
//


#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* prev;
	Node* next;	

Node(int d){
	data= d;
	next=prev=NULL;	
}
};
class DoublyLinkedList{
	public:
	Node* head;
	Node* tail;	

public:
	DoublyLinkedList(){
	head=tail=NULL;		
	}
	
	void insertAtEnd(int d){
    Node* newNode= new Node(d); 	
	if(head==NULL){
	head=tail=newNode;
	return;	
	}

 newNode->prev= tail;
 tail->next= newNode;
 tail = newNode;	
}	

void displayForward() {
        Node* temp = head;
        cout<<"Forward : ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout <<"NULL"<< endl;
    } 
	 
	 void displayReverse() {
        Node* temp = tail;
         cout<<"Reverse : ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << "NULL"<< endl;
    } 
    


    void merge(DoublyLinkedList& list2) {
        if (head == NULL) {  
            head = list2.head;
            tail = list2.tail;
            return;
        }
        if (list2.head == NULL) { 
            return;
        }

        tail->next = list2.head;
        list2.head->prev = tail;
        tail = list2.tail;
    }
};


int main() {
    DoublyLinkedList list1, list2;

    list1.insertAtEnd(1);
    list1.insertAtEnd(3);
    list1.insertAtEnd(5);

    list2.insertAtEnd(2);
    list2.insertAtEnd(4);
    list2.insertAtEnd(6);

    cout << "First Doubly Linked List:" << endl;
    list1.displayForward();
    list1.displayReverse();

    cout << "Second Doubly Linked List:" << endl;
    list2.displayForward();
    list2.displayReverse();

    list1.merge(list2);

    cout << "Merged Doubly Linked List:" << endl;
    list1.displayForward();
    list1.displayReverse();

    return 0;
}

//	