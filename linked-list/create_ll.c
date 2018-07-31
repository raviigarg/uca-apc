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

//print data of linked list
void print_list(node* head){
    node *cursor = head;
    while(cursor) {
        printf("%d\n", cursor->data);
        cursor= cursor->next;
    }
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

int main(){
     node* head = NULL;
     for(int i= 1; i <= 6; i++) {
        push(&head,i); // add at last
     }
    print_list(head);
    return 0;
}


//By passing only head i.e using single pointer
// node* push(node *h, int d) {
//     node *nn = createNewNode();
//     nn->data = d;
//     nn->next = NULL;
//     if(h == NULL) {
//         h = nn;
//     } else {
//         node *curr = h;
//         while(curr->next) {
//             curr = curr->next;
//         }
//         curr->next = nn;
//     }
//     return h;
// }

// int main(){
//      node* head = NULL;
//      for(int i= 1; i <= 6; i++) {
//         head = push(head,i); // add at last
//      }
//     print_list(head);
//     return 0;
// } 