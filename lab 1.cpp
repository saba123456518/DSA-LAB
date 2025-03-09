//Lab 1 - Pointers
//Task: Create a program that declares an integer variable and a pointer to it. Modify the value of the variable using 
//the pointer and display both the variable and pointer values.
#include<iostream>
using namespace std;
int main(){
int num = 10 ;
int *ptr = &num;	
 cout<<"initial val of num = "<< num <<endl;	
 cout<<"pointer point to address = "<< ptr <<endl;
 cout<<"val at ptr = "<< *ptr <<endl;	
 *ptr = 20;
 cout<<	"After using pointer : "<<endl;
  cout<<"initial val of num = "<< num <<endl;	
 cout<<"pointer still point to address = "<< ptr <<endl;
 cout<<"val at new ptr = "<< *ptr <<endl;		
}