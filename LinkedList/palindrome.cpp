#include<iostream>
#include<cmath>
using namespace std;

typedef struct llnode
{
	struct llnode *next;
	char val;	
} node;

node* create(int n)
{
	node *st = NULL;
	node *p,*l;
	int i = 0;
	char data;
	for(i;i<n;i++){
		p = (node*)malloc(sizeof(node));
		printf("Enter data to be stored in %d node:\n", i+1);
		scanf(" %c", &data);
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
		printf("%c", n->val);
		if(n->next!=NULL){
			printf("->");
		}
		n = n->next;
	}
	printf("\n");

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

int palind(node *head, int l)
{
	if(l%2==0)
	{
		int mid = l/2;
		node *st = head->next, *rt = head;
		for(int i = 0; i<mid; i++)
		{
			st = st->next;
		}
		for(int j=0;j<mid;j++)
		{
			char m,n;
			m = rt->val;
			n = st->val;
			if(m==n)
			{
				continue;
			}else
			{
				return 0;
				break;
			}
		}
		return 1;
	}
	else
	{
		int mid = l/2;
		node *st = head->next, *rt = head;
		for(int i = 0; i<mid; i++)
		{
			st = st->next;
		}
		st = st->next;
		for(int j=0;j<mid;j++)
		{
			char m,n;
			m = rt->val;
			n = st->val;
			if(m==n)
			{
				continue;
			}else
			{
				return 0;
				break;
			}
		}
		return 1;
	}
}

int main()
{
	int num, q;
	
	printf("Enter the num of nodes in LL:\n");
	scanf("%d",&num);
	
	node *root = create(num);
	printList(root);
	int pal = palind(root,num);
	if(pal==0)
	{
		printf("The given string is not a palindrome.\n");
	}else
	{
		printf("The given string is a palindrome.\n");
	}
}