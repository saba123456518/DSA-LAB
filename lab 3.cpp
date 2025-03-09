//Lab 3 - Singly Linked List (Insert at End, Insert at Start)  
//Task: Implement a singly linked list with functions to insert a node at the start and at the end.
// Display the list after each insertion.

#include <iostream>
using namespace std;

class Node{
public:
int data;
Node* next;

Node(int d){
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
void insertATstart(int d){
	Node* newNode = new Node(d);
	newNode->next = head;
	head = newNode;	
	display();
}
void insertATend(int d){
	Node* newNode = new Node(d);
	
  if(head==NULL){
  	head = newNode;
  }
  else{
	Node* temp = head;
	while(temp->next!=NULL){
		temp= temp->next;
	}
	temp->next = newNode;
}

	display();
}	
	
void display(){
	Node* temp = head;	
	while (temp!=NULL){
	cout<<temp->data <<"->";
	temp= temp->next;
	}
	 cout << "NULL" << endl;
    }
};
	
int main(){
  LinkedList list;
  cout<<"Insert at start"<<endl;
   list.insertATstart(10);	
   list.insertATstart(20);	
   list.insertATstart(30);
   
   cout<<"Insert at end"<<endl;	
   list.insertATend(40);
   list.insertATend(50);	
   list.insertATend(60);	
return 0;
}





