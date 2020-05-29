#include<iostream>
using namespace std;

typedef struct nodeEle{
	int data;
	struct nodeEle *next;
} node;

node *front = NULL;
node *rear = NULL;

bool isEmpty(){
	if(front == NULL && rear == NULL){
		return true;
	}else{
	return false;
	}
}

void enQueue(int val)
{
	node *n;
	n = (node*) malloc(sizeof(node));
	n->data = val;
	n->next = NULL;

	if(front == NULL && rear == NULL){
		front = n;
		rear = n;
	}else{
		rear->next = n;
		rear = n;
	}
}

void deQueue()
{
	if(front == NULL && rear == NULL){
		cout << "Queue is empty\n";
	}else if(front == rear){
		front = NULL;
		rear = NULL;
	}else{
		node *temp = front;
		front = front->next;
		free(temp);
	}
}

void atFront(){
	if(front == NULL && rear == NULL){
		cout << "Queue is empty\n";
	}else{
		cout << "The element at the front is:" << front->data << "\n";
	}
}


void display(){
	node *tmp = front;
	if(tmp == NULL){
		printf("Queue is empty\n");
	} else {
		cout << "\n Queue is: ";
		while(tmp != NULL){
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
	}
}

int main(){
	
		cout << "\n                Implementation of Queue using LL\n";
	while(true)
	{
		int p, q, e;

		cout << "\nEnter a number:\n1 for enQueue\n"
		"2 for deQueue\n"
		"3 to print front\n"
		"4 to display the Queue\n"
		"5 to check if queue is empty\n"
		"6 to clear terminal screen, and\n"
		"0 to terminate\n";
		cin >> q;
		if (q == 0)
			break;
		switch(q)
		{
			case 1:
			int ele;
			cout << "\nEnter value to enQueue to the queue\n";
			cin >> ele;
			enQueue(ele);
			break;

			case 2:
			deQueue();

			break;

			case 3:
			atFront();

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