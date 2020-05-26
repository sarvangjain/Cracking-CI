#include<iostream>
#include<cmath>
using namespace std;

typedef struct llnode
{
	struct llnode *next;
	int val;	
} node;

node* create(int n)
{
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
	printf("LL: ");
	while(n!=NULL){
		printf("%d", n->val);
		if(n->next!=NULL){
			printf("->");
		}
		n = n->next;
	}

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

int lltonum(node *head, int l){
	node *ref = head;
	int num = 0, dig;
	int i = 0;
	for(i; i<l; i++){
		dig = ref->val;
		num += dig * (pow(10,i));
		ref = ref->next;
	}
	return num;
}

node * numtoll(int sum){
	node *st = NULL, *p = NULL, *l = NULL;
	while(sum != 0){
		p = (node*)malloc(sizeof(node));
		p->next = NULL;
		p->val = sum % 10;
		sum = sum/10;
		if(st == NULL){
			st = p;
			l = p;
		}else{
			l->next = p;
			l = p;
		}
	}
	return st;
}


int main(){

	int l1, num1;
	
	printf("Enter the num of nodes in LL 1 (i.e. digits in number 1):\n");
	scanf("%d",&l1);
	printf("Enter the digits in rev order\n");
	node *root1 = create(l1);
	printList(root1);
	printf("\n");

	num1 = lltonum(root1,l1);

	int l2, num2;
	
	printf("Enter the num of nodes in LL 2 (i.e. digits in number 1):\n");
	scanf("%d",&l2);
	printf("Enter the digits in rev order\n");
	node *root2 = create(l2);
	printList(root2);
	printf("\n");

	num2 = lltonum(root2,l2);
	int sum = num1 + num2;
	printf("Num1 is: %d and Num2 is %d and their sum is: %d\n", num1,num2,sum);

	node *root;
	root = numtoll(sum);
	printf("Sum stored in LL in reverse order is:\n");
	printList(root);
	printf("\n");
	
	return 0;
}