#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;


struct node *createNewNode(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
};


void insertBeginning(int key) {
    struct node *newnode = createNewNode(key);
    newnode->next = head;
    head = newnode;
}


void insertLast(int key) {
    struct node *newnode = createNewNode(key);
    // If the list is empty
    if(head == NULL) {
        head = newnode;
    }
    else {
        struct node *t = head;

        while(t->next != NULL){
            t = t->next;
        }

        // Now t is the last node
        t->next = newnode;
    }
}


void insertAt(int key, int pos) {
    if(pos < 0) {
        printf("invalid position\n");
        return;
    }
    else if(pos == 0) {
        insertBeginning(key);
        return;
    }
    else {
        int idx = 0;
        struct node *t = head;
        while(t != NULL && idx < pos-1) {
            idx++;
            t = t->next;
        }

        // t is the node at pos-1
        if(t != NULL) {
            struct node *newnode = createNewNode(key);
            newnode->next = t->next;
            t->next = newnode;
        }
        else {
            printf("Position exceeds the length of the list. %d is not inserted.\n", key);
        }
    }
}


void deleteFirst() {
    // Check if list is empty
    if(head == NULL) {
        printf("List is empty. Nothing to delete\n");
        return;
    }
    struct node *t = head;
    head = head->next;
    free(t);
}


void deleteLast() {
    // case -1: list is empty
    if(head == NULL) {
        printf("List is empty\n");
    }
    else if(head->next == NULL) { //case-2: only 1 node in the list
        struct node *t = head;
        head = NULL;
        free(t);
    }
    else {
        struct node *t = head;
        // Find the 2nd last node
        while(t->next->next != NULL){
            t = t->next;
        }
        // t is the 2nd last node. last node is t->next
        free(t->next);  //delete last node
        t->next = NULL;  //set the next of 2nd last node as NULL
    }
}


void deleteAt(int pos) {
    if(pos < 0) {
        printf("Invalid position.\n");
    }
    else if(pos == 0) {
        deleteFirst();
    }
    else {
        int current_position = 0;
        struct node *current = head;
        while(current != NULL && current_position < pos-1) {
            current = current->next;
            current_position++;
        }
        // current is the node at pos-1
        if(current == NULL) {
            printf("Position exceeds the length of the list. Can't be deleted at position %d.\n", pos);
        }
        else {
            struct node *t = current->next;
            current->next = t->next;
            free(t);
        }
    }
}


int search(int x) {
    // returns the first occurrence of x
    // if not present in the list, return -1
    int idx = 0;
    struct node *current = head;
    while(current != NULL){
        if(current->data == x) {
            return idx;
        }
        else {
            idx++;
            current = current->next;
        }
    }
    return -1;
}


void printList() {
    printf("Linked list: ");
    struct node *t = head;

    while(t != NULL) {
        printf("%d ",t->data);
        t = t->next;
    }
    printf("\n");
}


int main() {
    int choice, key, pos;
    printf("1.insert first 2.insert last 3.insert at 4.delete first 5.delete last 6.delete at 7.search 8.exit\n");

    while(1){
        printf("enter choice: ");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("enter element: ");
            scanf("%d", &key);
            insertBeginning(key);
        }
        else if(choice == 2) {
            printf("enter element: ");
            scanf("%d", &key);
            insertLast(key);
        }
        else if(choice == 3) {
            printf("enter position: ");
            scanf("%d",&pos);
            printf("enter element: ");
            scanf("%d", &key);
            insertAt(key, pos);
        }
        else if(choice == 4) { 
            deleteFirst();
        }
        else if(choice == 5) {
            deleteLast();
        }
        else if(choice == 6) {
            printf("enter position: ");
            scanf("%d", &pos);
            deleteAt(pos);
        }
        else if(choice == 7) {
            printf("enter element: ");
            scanf("%d", &key);
            int idx = search(key);

            if(idx == -1) {
                printf("%d is not in the list.\n", key);
            }
            else {
                printf("The key is found at: %d\n", idx);
            }
        }
        else{
            break;
        }
        printList();
        printf("\n");
    }
}