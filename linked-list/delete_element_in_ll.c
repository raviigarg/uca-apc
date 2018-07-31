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

//add element at last
void add_at_last(node **h, int d) {
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

//add at beginning of linked list
void add_at_begin(node **h, int data) {
    node *nn = createNewNode();
    nn->data = data;
    nn->next = *h;
    *h = nn;
}

//add at position p of linked list
void add_at_position_p(node **h, int data, int pos) {
    if(pos == 1){
        add_at_begin(h, data);
    }
    else {
        node *curr = *h;
        int p = 1;
        while(p < pos-1 && curr) {
            curr = curr->next;
            p++;
        }
        if(curr == NULL) {
            printf("Position doesn't exist");
        }
        else {
            node* nn = createNewNode();
            nn->data = data;
            nn->next = curr->next;
            curr->next = nn;
        }
    }
}

//print data of linked list
void print_list(node* head){
    node *cursor = head;
    while(cursor) {
        printf("%d\n", cursor->data);
        cursor= cursor->next;
    }
}

//delete element at last and return data of deleted node
int delete_at_last(node **h) {
   if(*h == NULL) {
       return -1;
   }
   node* curr =*h;
   while(curr && curr->next && curr->next->next){
       curr = curr->next;
   }
   node *temp = curr->next;
    int d = temp->data;
    free(temp);
    temp = NULL;
    curr->next = NULL;
    return d;
}

//delete at beginning of linked list and return data of deleted node
int delete_at_begin(node **h) {
   if(*h == NULL) {
       return -1;
   }else {
       node *temp = *h;
       (*h) = (*h)->next;
       int d = temp->data;
       free(temp);
       temp = NULL;
       return d;
   }
}

//delete at position p of linked list and return data of deleted node
int delete_at_position_p(node **h, int pos) {
    if(pos == 1){
        delete_at_begin(h);
    }
    else {
        node *curr = *h;
        int p = 1;
        while(p < pos-1 && curr) {
            curr = curr->next;
            p++;
        }
        if(curr == NULL) {
            printf("Position doesn't exist");
        }
        else {
           node *temp = curr->next;
           curr->next = temp->next;
           int d = temp->data;
           free(temp);
           temp = NULL;
           return d;
        }
    }
}

//delete whole linked list
void delete(node* curr) {
    while(curr) {
        node* temp = curr;
        curr = curr->next;
        free(temp);
        temp = NULL;
    }
}

int main(){
    node* head = NULL;
    add_at_begin(&head, 5);
    add_at_begin(&head, 4);
    add_at_begin(&head, 3);
    add_at_last(&head, 6);
    add_at_begin(&head, 7);
    add_at_position_p(&head, 8, 3);
    print_list(head);
    printf("After deletion\n");
    int a = delete_at_last(&head);
    int b = delete_at_begin(&head);
    int c = delete_at_position_p(&head, 2);
    print_list(head);
    return 0;
}