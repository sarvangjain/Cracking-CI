#include<iostream>
using namespace std;

typedef struct llnode{
	int data;
	struct llnode *next;
} node;

node *root = NULL;

void push(int val)
{
	node *n = (node*) malloc(sizeof(node));
	n->data = val;
	n->next = root;
	root = n;
	cout << "\nPush operation succeded\n\n";
}

int pop(){
	if(root == NULL)
	{
		cout << "\nStack is empty\n\n";
		return -1;
	}
	int val = root->data;
	node *nxt = root->next;
	free(root);
	root = nxt;
	return val;
}

bool isEmpty(){
	if(root == NULL)
	{
		return true;
	}else
	{
		return false;
	}
}

void peek(){
	if(root==NULL)
	{
		cout << "\nThe stack is empty.\n\n";
	}else
	{
		cout << "\nThe top most element is: " <<root->data << "\n\n";
	}
}

void display()
{
	node *temp = root;
	cout << "\n";
	if (temp == NULL)
		cout << "The stack is empty.\n";
	while(temp != NULL)
	{
		cout << "| " << temp->data << " |\n";
		cout << "-----\n";
		temp = temp->next;
	}
	cout << "\n\n";

}


// -------------------------------------------------------------------- Main Function --------------------------------------------------------------------


int main()
{
	cout << "                   Implementation of Stack\n";
	while(true)
	{
		int p, q, e;

		cout << "\nEnter a number:\n1 for Push\n"
		"2 for Pop\n"
		"3 to Peek the topmost element\n"
		"4 to Display the stack\n"
		"5 to Check if stack is empty\n"
		"6 to Clear terminal screen, and\n"
		"0 to Terminate\n";
		cin >> q;
		if (q == 0)
			break;
		switch(q)
		{
			case 1:
			int ele;
			cout << "\nEnter value to push to the stack\n";
			cin >> ele;
			push(ele);
			break;

			case 2:
			p = pop();
			cout << "\nValue popped: " << p << "\n\n";
			break;

			case 3:
			peek();
			break;

			case 4:
			display();
			break;

			case 5:
			e = isEmpty();
			if (e == 1)
				cout << "\nTrue\n\n";
			else
				cout << "\nFalse\n\n";
			break;

			case 6:
			system("clear");
			break;

			default:
			cout << "Please enter a valid response\n";

		}

	}	

	return 0;	
}