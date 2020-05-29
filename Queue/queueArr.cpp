// queueaArr
#include<iostream>
using namespace std;

#define SIZE 5

typedef class queueArr{
	
	int front = -1;
	int rear = -1;
	int arr[SIZE];

public:

	void enQueue(int val){
		if(this->rear == SIZE - 1){
			cout << "Queue is full\n";
			return;
		}

		this->arr[++this->rear] = val;
		
		if(this->front == -1){
			this->front++;
		}
	}

	bool isEmpty(){
		if(this->front == -1 && this->rear == -1){
			return true;
		}
		return false;
	}

	int atFront(){
		if(this->front == -1){
			cout << "Queue is empty\n";
			return -1;
		} else {
			return this->arr[this->front];
		}
	}

	int deQueue(){
		if (front == rear){
			cout << "Queue is empty\n";
			this->front = -1;
			this->rear = -1;
			return -1;
		}else{
			return arr[front++];
		}
	}

	void display(){
		if(isEmpty()){
			cout << "Queue is empty\n";
			return;
		}

		for(int i = front; i <= rear ; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
	}

} queue;


int main()
{
	queue myQueue;
	
	cout << "\n                   Implementation of Queue\n";
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
			myQueue.enQueue(ele);
			break;

			case 2:
			p = myQueue.deQueue();
			if(p == -1){
				cout << "\n";
			} else{
				cout << "\nValue DeQueued: " << p << "\n\n";
			}
			break;

			case 3:
			p = myQueue.atFront();
			if(p == -1){
				cout << "\n";
			} else{
				cout << "\nValue at front is: " << p << "\n\n";
			}
			break;

			case 4:
			myQueue.display();
			break;

			case 5:
			e = myQueue.isEmpty();
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