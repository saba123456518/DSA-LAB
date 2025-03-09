//  Lab 6 - Singly Linked List (Delete Nodes)  
//Task: Implement functions to delete the first node, last node, Nth node, and center node of a singly linked list.
//                        delete at start:
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
    void insert_at_end(int d) {
        Node* newNode = new Node(d);
        
        if (head == NULL) {  
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {  
            temp = temp->next;
        }
        
        temp->next = newNode;  
    }
//

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void deletefirstnode(){
    	if (head == NULL){
    	cout<<"list is empty . cannot del"<<endl;
		return;	
    	}
    	
    	Node* temp = head;
    	head = head->next;
    	delete temp;
    	cout<<"first node delete"<<endl;
    	
	}
	 void deletelastnode(){
    	if (head == NULL){
    	cout<<"list is empty . cannot del"<<endl;
		return;	
    	}
    	if (head->next == NULL) {  
        delete head;
        head = NULL;
        cout << "Last node deleted." << endl;
        return;
    }
    	Node* temp = head;
        while(temp->next->next!=NULL){
        	temp = temp->next;
        		}
        		delete temp->next;
        		temp->next = NULL;
        		cout<<"last node deleted"<<endl;
        	}                                     

    
    void deleteNthnode(int n) {
        if (head == NULL) {
            cout << "List is empty! Cannot delete." << endl;
            return;
        }
        if (n == 1) {  
            deletefirstnode();
            return;
        }
        Node* temp = head;
        for (int i = 1; temp != NULL && i < n - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "Node at position " << n << " deleted." << endl;
    }

   
    void deleteCenternode() {
        if (head == NULL) {
            cout << "List is empty! Cannot delete." << endl;
            return;
        }
        if (head->next == NULL) {  
            deletefirstnode();
            return;
        }
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete slow;
        cout << "Center node deleted." << endl;
    }
};

int main() {
    LinkedList list;
    
    list.insert_at_end(10);
    list.insert_at_end(20);
    list.insert_at_end(30);
    list.insert_at_end(40);
    list.insert_at_end(50);
    
    cout << "Original List: " << endl;
    list.display();  

    list.deletefirstnode();
    cout << "After deleting first node: ";
    list.display();

    list.deletelastnode();
    cout << "After deleting last node: ";
    list.display();

    list.deleteNthnode(2);
    cout << "After deleting 2nd node: ";
    list.display();

    list.deleteCenternode();
    cout << "After deleting center node: ";
    list.display();

    return 0;
}







