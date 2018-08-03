#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct node {
    int data;
    struct node *next;
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

int pop(node **h) {
    if(*h == NULL) {
        return -1;
    }
    node *curr = *h;
    while(curr && curr->next && curr->next->next) {
        curr = curr->next;
    }
    node *temp = curr->next;
    int d = temp->data;
    free(temp);
    temp = NULL;
    curr->next = NULL;
    return d;
}

int peak(node **h) {
    if(*h == NULL) {
        return -1;
    }
    node *curr = *h;
    while(curr && curr->next && curr->next->next) {
        curr = curr->next;
    }
    return curr->next->data;
}

int main() {
    node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    int a1 = pop(&head);
    int a2 = pop(&head);
    int a3 = peak(&head);
    int a4 = peak(&head);
    assert( a1 == 4);
    assert (a2 == 3);
    assert (a3 == 2);
    assert (a4 == 2);
    return 0;
}
