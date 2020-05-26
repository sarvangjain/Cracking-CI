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

void deleteNode(node *ptr) 
{ 
	node *ref = ptr->next;
	int data = ref->val;
	ptr->val = data;
	ptr->next = ref->next;
	free(ref);
} 

node* ptrToNode(node *head, int k){
	node *hd = head;
	int i = 1;
	for(i;i<k;i++){
		hd = hd->next;
	}
	return hd;
}

int main(){

	int num, q
;	
	printf("Enter the num of nodes in LL:\n");
	scanf("%d",&num);
	
	node *root = create(num);
	printList(root);

	int del;
	printf("Enter position to be deleted from the LL (1 Based Index):\n");
	scanf(" %d", &del);
	
	node *ptr = ptrToNode(root,del);
	printf("Pointer to the node to be deleted is: %p and its value is: %d\n", ptr, ptr->val);

	printf("Deleting the node using only the pointer to it...\n");

	deleteNode(ptr);
	printList(root);

	return 0;
}