#include<iostream>
using namespace std ;
//
//const int size = 100;
//int stack [size];
//int top = -1;
//
//void push(int value){
//if (top == size - 1){
//	cout<<"stack overflow";	
//}	
//else{
//	
//	top++;
//	stack[top] = value;
//  }		
//}
// void pop(){
//  if (top == -1){
//  	cout<<"stack overflow";	
//}		
// else{
// 	cout<<"popped : "<<stack[top]<<endl;
// 	top--;
//  } 	
// }
//
//void display(){
//	if(top == -1){
//	cout<<"stack is empty";	
//	}
//	else{
//	cout<<"stack elements:"	;
//
//	for (int i = top ; i>=0 ; i--){
//		 cout << stack[i] << " ";
//        }
//    }
//        cout << endl;
//    }
//    
//int main() {
//	push(10);
//	push(20);
//	display();
//    pop();
//   	display();
//    return 0;
//}
//
//Stack using Linked List 
 struct Node{
 	int data;
 	Node* next;
 };
 	
 	
Node*top = nullptr;
void push ( int value) {
	Node *newNode = new Node;
	newNode->data = value;
	newNode->next = top;
	top = newNode;
}
//
void pop(){
   if (top == nullptr)	{
   	 cout<<"stack underflow"; 	
   }
   else{
   	cout<< "Popped : "<<top->data<<endl;
   	Node* temp = top;
   	top = top ->next;
   	delete temp;
   }	
}
//
void display (){
	if (top == nullptr){
	 cout<<"stack is empty"	;
}
else{
	cout<<"stack elements"<<endl;
	Node* current = top;
	 while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}
//

int main() {
	push(100);
	push(200);
	display();
	pop();
	display();
	return 0;
   
}



