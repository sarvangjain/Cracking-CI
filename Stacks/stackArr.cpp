#include<iostream>
using namespace std;

typedef struct impStack
{
	int top;
	unsigned int capacity;
	int *arr;
}stack;

stack *createStack(int cap)
{
		stack *myStack = (stack*)malloc(sizeof(stack));
		myStack->capacity = cap;
		myStack->arr =(int*)malloc(myStack->capacity*sizeof(int));
		myStack->top = -1;
		return myStack;
}

void push(stack *s, int val)
{
	if(s->top == s->capacity - 1)
	{
		cout << "Stack Overflow\n";
		return;
	}

	s->arr[++s->top] = val;
	cout << "Value " << val << " pushed to the stack\n";
}

int pop(stack *s)
{
	if (s->top == -1)
	{
		cout << "Stack Underflow\n";
	}

	return s->arr[s->top--];
}

void peek(stack *s)
{
	if (s->top == -1)
	{
		cout << "Stack is empty\n";
		return;
	}

	cout << "Value at top of stack is:" << s->arr[s->top] << "\n";
	return;
}

int main()
{
	int cap;
	cout << "Please enter the capacity of stack to be implemented\n";
	cin >> cap;
	int p;
	stack *st = createStack(cap);
	push(st,4);
	push(st,6);
	push(st,2);
	push(st,3);
	peek(st);
	p = pop(st);
	cout << p <<"\n";
	peek(st);

	return 0;
}
