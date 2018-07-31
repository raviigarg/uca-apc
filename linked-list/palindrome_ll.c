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

void reverse(node** head) {
    node* prev = NULL;
    node* current = *head;
    node* next;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void is_palindrome(node** head) {
    node* fast = *head, *slow = *head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    int flag = 1;
    node* mid;
    mid = slow;
    reverse(&(mid->next));
    // print_list(*head);
    fast = *head;
    slow = mid->next;
    while (flag == 1 && slow) {
        if(fast->data != slow->data) {
            flag = 0;
        }
        slow = slow->next;
        fast = fast->next;
    }
    reverse(&(mid->next));
    if(flag==0) {
        printf("Linked List is not palindrome");
    }else {
        printf("Linked List is palindrome");
    }
}

int main(){
     node* head = NULL;
     int data;
     for(int i=1;i<=7; i++) {
        push(&head,i);
     }
    for(int i=5;i>=1; i--) {
        push(&head,i);
     }
    is_palindrome(&head);
    return 0;
}