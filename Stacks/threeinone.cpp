#include<iostream>
using namespace std;
int top1 = -1;
int top2 = 9;
int top3 = 19;

int arr[30];

void push(int val, int stack){
	switch(stack){
	case 1:
		if(top1 == 9){
			cout << "Stack is full\n";
			return;
		}
		arr[++top1] = val;
		cout << val << " pushed to the stack\n";
		break;
	case 2:
		if(top2 == 19){
			cout << "Stack is full\n";
			return;
		}
		arr[++top2] = val;
		cout << val << " pushed to the stack\n";
		break;
	case 3:
		if(top3 == 29){
			cout << "Stack is full\n";
			return;
		}
		arr[++top3] = val;
		cout << val << " pushed to the stack\n";
		break;
	}
}

void peek(int stack){
	switch(stack){
		case 1:
		cout << "Top of stack 1 is: " << arr[top1] << "\n";
		break;
		case 2:
		cout << "Top of stack 2 is: " << arr[top2] << "\n";
		break;
		case 3:
		cout << "Top of stack 3 is: " << arr[top3] << "\n";
		break;
	}

}

int main(){
	cout << "Capacity of Stacks is 10\n";
	push(2,1);
	push(4,1);
	push(5,1);
	push(21,2);
	push(52,2);
	push(8,3);
	push(6,3);
	peek(1);
	peek(2);
	peek(3);
	

}