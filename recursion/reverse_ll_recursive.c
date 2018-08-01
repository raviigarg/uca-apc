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

node* reverse_recursive(node* first) {
    node* second;
    if(first) {
        second = first->next;
    }
    if(!second) {
        return first;
    }
    else{
        node* curr = reverse_recursive(second);
        first->next = second->next;
        second->next = first;
        return curr;
    }
}

void print_list(node* head){
    node *cursor = head;
    while(cursor) {
        printf("%d\n", cursor->data);
        cursor= cursor->next;
    }
}

int main(){
     node* head = NULL;
     int data;
     for(int i=1;i<=7; i++) {
        push(&head,i);
     }
    print_list(head);
    head = reverse_recursive(head);
    printf("After reverse:\n");
    print_list(head);
    return 0;
}