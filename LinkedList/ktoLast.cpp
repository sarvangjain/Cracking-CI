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

void printList(node *n,int k){
	int i = 0;
	while(n!=NULL){
		if(i >= k){
			printf("Data: %d\n", n->val);
		}
		i++;
		n = n->next;
	}
}


int main(){

	int num, q;
	
	printf("Enter the num of nodes in LL:\n");
	scanf("%d",&num);
	
	node *root = create(num);
	printList(root,0);

	int k;
	printf("Enter position to be printed from, from the LL (0 Based Index):\n");
	scanf(" %d", &k);

	printList(root,k);
	

	return 0;
}