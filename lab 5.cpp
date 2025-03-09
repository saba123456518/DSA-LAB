//- Singly Linked List (Display Nodes)  
//Task: Implement functions to display the first node, last node, Nth node, and centre node of a singly linked list.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }
void insertAtEnd(int d){
   Node* newNode = new Node(d);
   if(head == NULL){
   	head = newNode;
   	return;
   	
   }
   Node* temp= head;	
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}
void display(){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->data <<"->";
		temp = temp->next;
		
	}
	cout<<"NULL"<<endl;
	
}
void displayFirstNode(){
	if (head != NULL){
	cout<<"First node:"<<head ->data<<endl;
}
else
  cout<<"list is empty"	<<endl;	
	
		}
void displaylastNode(){
	if (head == NULL){
	cout<<"list is empty"	<<endl;
	return;	
		}
				
 Node* temp= head;	
	while(temp->next!=NULL){
		temp = temp->next;
	}		
	cout<<"last node:"<<temp ->data<<endl;	
		}	
   
    void displayNthNode(int n) {
        Node* temp = head;
        int count = 1;
        while (temp != NULL && count < n) {
            temp = temp->next;
            count++;
        }
        if (temp != NULL)
            cout << "Node at position " << n << ": " << temp->data << endl;
        else
            cout << "Position " << n << " is out of bounds!" << endl;
    }

    void displayCenterNode() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Center Node: " << slow->data << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    list.display();

    list.displayFirstNode();
    list.displaylastNode();
    list.displayNthNode(3);  
    list.displayCenterNode();  

    return 0;
}


