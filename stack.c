#include<stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE],top=-1;
int isFull(){
	//returns 1 if stack is full else returns -1
		if(top==MAX_SIZE)
		return 1;
	else
	return -1;
}

int isEmpty(){
	//returns 1 if stack is empty else returns -1
	return top==-1;

int peek(){
	//return element at the top of stack
	return  stack[top];
}

void push(int e){
	//inserts an element into stack
	if(!isFull)
	{
		top++;
		stack[top]==e;
		printf("element is inserted successfully");
	}
	else
	{
		printf("stack overflow");
	}
}

void pop(int e){
	//delete element from stack
	int d;
	if(!is Empty)
	{
		d=top of stack;
		top--
		printf("elements are deleted succesfully");
	}
	else{
		printf("stack underflow");
	}
}

int main(){
	int choice,e;
	do
	{
		display menu 1.peek 2.push 3.pop 4.exit
		printf("enter your choice");
		take input in choice variable
		switch(choice){
		case 1:
		     e=peek();//call peek function
		     printf("\nelement at the top of stack is :%d",e);
		     break;
		case 2:
		     //call push function
		     break;
		case 3:
		     //call pop function
		     break;
		case 4:
		     //call exit(0) function
		     break;     
	}while(1);
	return=0;
}

