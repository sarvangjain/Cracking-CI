#include<iostream>
using namespace std;

typedef struct llnode{
	struct llnode *next;
	int val;	
} node;

node* create(int n){
	node *st = NULL;
	node *p,*l;
	int i = 0, data;
	for(i;i<n;i++){
		p = (node*)malloc(sizeof(node));
		printf("Enter data to be stored in %d node:\n", i+1);
		scanf(" %d", &data);
		p->val = data;
		p->next = NULL;
		if(st == NULL){
			st = p;
			l = p;
		}else{
			l->next = p;
			l=p;
		}
	}

	return st;
}

void printList(node *n){
	while(n!=NULL){
		printf("Data: %d\n", n->val);
		n = n->next;
	}
}

void delVal(int data, node *head){
	
	node *n = head, *p;
	
	if (head == NULL){
		printf("LL is empty\n");
	}

	while(n->val != data && n != NULL){
		p = n;
		n = n->next;
	}
	if(n == head && n->val == data){
		head = head->next;
		free(n);
	}else if(n->next==NULL){
		p->next = NULL;
		free(n);
	}
	else{
		p->next = n->next;
		free(n);
	}
}

int delAtPos(int n, node *head){
	int i = 0;
	node *nxt = head, *prev;
	
	if (head == NULL){
		printf("LL is empty\n");
		return 0;
	}

	if(n==0){
		head = head->next;
		free(nxt);
		return 1;
	}

	for(i;i<n;i++){
		if(nxt->next == NULL){
			printf("Please enter a number within length of the LL\n");
			return 0;
		}
		prev = nxt;
		nxt = nxt->next;	
	}

	prev->next = nxt->next;
	free(nxt);

	return 1;
}

int main(){
	int num;
	int del;
	
	printf("Enter the num of nodes in LL:\n");
	scanf("%d",&num);
	
	node *root = create(num);
	printList(root);
	
	printf("Enter value to be deleted from the LL (0 Based Index):\n");
	scanf(" %d", &del);
	
	delVal(del,root);
	printList(root);


	return 0;
}