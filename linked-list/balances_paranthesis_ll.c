#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct node {
    char data;
    struct node *next;
} node;

node* createNewNode(){
    node *nn = (node*) malloc(sizeof(node));
    return nn;
}

void push(node **h, char d) {
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

void pop(node **h) {
    node *curr = *h;
    while(curr && curr->next && curr->next->next) {
        curr = curr->next;
    }
    node *temp = curr->next;
    char d = temp->data;
    curr = curr->next;
    free(temp);
    temp = NULL;
    curr->next = NULL;
}

char peek(node **h) {
    if(*h == NULL) {
        return -1;
    }
    node *curr = *h;
    while(curr && curr->next && curr->next->next) {
        curr = curr->next;
    }
    return curr->next->data;
}

int is_balanced(node **h, char *string, int n) {
    char p;
    int len = 0;
    for(int i = 0; i < n; i++) {
        if(string[i] == '{' || string[i] == '[' || string[i] == '(') {
            push(h, string[i]);
            len++;
            continue;
        }
        if(len == 0) {
            return 0;
        }
        switch(string[i]) {
            case ')': p = peek(h);
                    pop(h);
                    len--;
                    if(p == '{' || p == '[')
                        return 0;
                     break;
            case ']': p = peek(h);
                    pop(h);
                    len--;
                    if(p == '{' || p == '(')
                        return 0;
                    break;
            case '}': p = peek(h);
                    pop(h);
                    len--;
                    if(p == '[' || p == '(')
                        return 0;
                    break;
        }
    }
    if(len==0)
        return 1;
    else
        return 0;
}

int main() {
    char s[] = "{[()]}";
    int n = sizeof(s)/sizeof(s[0]) - 1;
    node *head = NULL;
    int balanced = is_balanced(&head, s, n);
    if(balanced == 1)
        printf("String is Balanced\n");
    else
        printf("String is not Balanced\n"); 
    return 0;
}
