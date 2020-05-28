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

int peek(stack *s)
{
	if (s->top == -1)
	{
		cout << "Stack is empty\n";
		return -1;
	}

	//cout << "Value at top of stack is:" << s->arr[s->top] << "\n";
	return s->arr[s->top];
}

int main()
{
	int cap;
	cout << "Please enter the capacity of stack to be implemented\n";
	cin >> cap;
	int p, minim;
	stack *st = createStack(cap);
	stack *min = createStack(cap);
	for(int i = 0; i< cap; i++){
		int val;
		cout << "Enter values to be pushed to stack and enter -1 to pop\n";
		cin >> val;
		if (i == 0){
			minim = val;
			push(min,val);
		}
		
		if(val == -1){
			p = pop(st);
			if( p == peek(min)){
				p = pop(min);
				minim = peek(min);
			}
		}else{
			push(st,val);
			if(val<minim){
				push(min,val);
				minim = val;
			}
		}
	}

	cout << peek(st) << "\n";
	cout << peek(min) << "\n";

	return 0;
}
