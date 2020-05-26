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

void partition(node *head, int x){
	node *temp = head, *left = NULL, *right = NULL;
	node *p1, *l1, *p2, *l2;
	int data;
	while(temp != NULL){
		data = temp->val;
		if(data<x){
			p1 = (node*)malloc(sizeof(node));
			p1->val = data;
			p1->next = NULL;
			if(left == NULL){
				left = p1;
				l1 = p1;
			}else{
				l1->next = p1;
				l1 = p1;
			}
		} else{
			p2 = (node*)malloc(sizeof(node));
			p2->val = data;
			p2->next = NULL;
			if(right == NULL){
				right = p2;
				l2 = p2;
			}else{
				l2->next = p2;
				l2 = p2;
			}
		}
		temp = temp->next;
	}
	p1->next = right;
	printList(left);
}


int len(node *head){
	node *st = head;
	int l = 0;
	while(st != NULL){
		l++;
		st = st->next;
	}
	return l;

}



int main(){

	int num, q;
	
	printf("Enter the num of nodes in LL:\n");
	scanf("%d",&num);
	
	node *root = create(num);
	printList(root);

	printf("Enter a value to partition the LL:\n");
	scanf(" %d", &q);
	printf("Partitoning the list...\n");
	partition(root,q);

	return 0;
}