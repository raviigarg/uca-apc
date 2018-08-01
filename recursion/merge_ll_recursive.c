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

node* merge(node* h1, node* h2){
    node *h = NULL;
    if(h1 == NULL)
        return h2;
    else if(h2 ==NULL)
        return h1;

    if(h1->data <= h2->data) {
        h = h1;
        h->next = merge(h1->next, h2);
    } else {
        h = h2;
        h->next = merge(h1, h2->next);
    }
    return h;
}

void print_list(node* head){
    node *cursor = head;
    while(cursor) {
        printf("%d\n", cursor->data);
        cursor= cursor->next;
    }
}

int main(){
     node* head1 = NULL;
     node* head2 = NULL;
     for(int i=1;i<=11; i=i+2) {
        push(&head1,i);
     }
     for(int i=2;i<=12; i=i+2) {
        push(&head2,i);
     }
    print_list(head1);
    print_list(head2);
    printf("After merge\n");
    node* head = merge(head1, head2);
    print_list(head);
    return 0;
}