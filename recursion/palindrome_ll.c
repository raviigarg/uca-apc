#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * next;
} node;

node* createNewNode(){
    node *nn = (node*) malloc(sizeof(node));
    return nn;
}

void push(node **h, int d) {
    node *nn = createNewNode();
    nn->data = d;
    nn->next = NULL;
    if(*h == NULL) {
        *h = nn;
    } else {
        node *curr = *h;
        while(curr->next) {
            curr = curr->next;
        }
        curr->next = nn;
    }
}

void print_list(node* head){
    node *cursor = head;
    while(cursor) {
        printf("%d\n", cursor->data);
        cursor= cursor->next;
    }
}

int is_palindrome(node** left, node* right) {
    if(right==NULL)
    	{
        	return 1;
    	}
    	int result = is_palindrome(left,right->next);
    	if(result==0)
    	{
        	return 0;
    	}
	    if((*left)->data==right->data)
	    {	
        	*left=(*left)->next;
        	return 1;
    	}
	    return 0;
}

int main(){
     node* head = NULL;
     int data;
     for(int i=1;i<=3; i++) {
        push(&head,i);
     }
    for(int i=4;i>=1; i--) {
        push(&head,i);
     }
    int ans = is_palindrome(&head, head);
    if(ans==1) {
        printf("Linked list is palindrome.");
    } else {
        printf("Linked list is not palindrome.");
    }
    return 0;
}