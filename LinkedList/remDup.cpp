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

void deleteNode(node *head_ref, int position) 
{ 
   // If linked list is empty 
   if (head_ref == NULL) 
      return; 
  
   // Store head node 
   node *temp = head_ref; 
  
    // If head needs to be removed 
    if (position == 0) 
    { 
        head_ref = temp->next;   // Change head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Find previous node of the node to be deleted 
    for (int i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->next; 
  
    // If position is more than number of ndoes 
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    // Node temp->next is the node to be deleted 
    // Store pointer to the next of node to be deleted 
    node *nxt = temp->next->next; 
  
    // Unlink the node from linked list 
    free(temp->next);  // Free memory 
  
    temp->next = nxt;  // Unlink the deleted node from list 	
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

void remDup(node *head){

	int data;
	
	node *nd = head;
	node *dup = NULL;
	
	int l = len(head);
	int i = 0;
	
	for(i; i<l; i++){

		data = nd->val;
		dup = nd->next;
		for(int j = i+1; j<l ; j++){
			if(dup->val == data){
				dup = dup->next;
				l--;
				deleteNode(head,j);
			}else{
				dup = dup->next;
			}
		}
		nd = nd->next;
	}

}



int main(){

	int num, q;
	
	printf("Enter the num of nodes in LL:\n");
	scanf("%d",&num);
	
	node *root = create(num);
	printList(root);

	int del;
	printf("Enter position to be deleted from the LL (0 Based Index):\n");
	scanf(" %d", &del);
	
	//deleteNode(root,del);
	printList(root);
	printf("%d\n", len(root));
	
	printf("Do you want to remove duplicates? (0 for No, 1 for Yes)\n");
	scanf(" %d", &q);

	if(q==1){
		remDup(root);
		printList(root);
	}else{
		printf("Thankyou\n");
	}

	return 0;
}