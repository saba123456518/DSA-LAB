///Lab 4 - Singly Linked List (Insert at Specific Location)  
//Task: Write a function to insert a node at a specific position in a singly linked list,
// ensuring valid position handling. 
#include <iostream>
using namespace std;
class Node{
public:
int data;
Node* next;	
Node(int d)	{
 data = d;	
 next = NULL;	
	
}
};
class LinkedList{
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }
	
void insertATpos(int pos , int d){
 Node* newNode = new Node(d);
 if(pos<0){
 	cout<<"invalid position"<<endl;
}
else if (pos==1){
 	newNode->next = head;
	 head = newNode;
	 return;	
 } 
 
 
 Node* temp = head;
 for(int i=1 ;i<pos-1; i++){
     if(temp==NULL){
 	cout<<"INVALID POSITION"<<endl;
 	return;
 }
  temp = temp->next;
        }
 newNode -> next = temp -> next;
 temp -> next = newNode;
 		
 }


 void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
 int main(){
 	
  LinkedList list;
  list.insertATpos(1,10);
  list.insertATpos(2,20);
  list.insertATpos(3,30);
  list.display();
  return 0;
  }
	


