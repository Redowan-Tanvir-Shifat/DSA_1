#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

struct node *createNewNode(int x) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode; 
};

void insertBeginning(int key) {
    struct node *newNode = createNewNode(key);
    newNode -> next = head;
    head = newNode;
}

void insertLast(int key)
{
    struct node *newNode = createNewNode(key);
    // If the list is empty...
    if (head == NULL) {
        head = newNode;
    }
    else {
        struct node *t = head; 
        while(t -> next != NULL) {
            t = t -> next;
        }
        // Now t is the last node...
        t -> next = newNode;
    }
}

void insertAt(int key,int pos)
{
    if(pos<0)
    {
        printf("invalid position\n");
        return;
    }
    else if(pos==0)
    {
        insertBeginning(key);
        return;
    }
    else
    {
        int current_position=0;
        struct node *current=head;
        while(current!=NULL && current_position< pos-1)
        {
            current=current->next;
            current_position++;
        }

        if(current!=NULL)
        {
            struct node *newnode=createNewNode(key);
            newnode->next=current->next;
            current->next=newnode;
        }
        else
        {
            printf("Position exceeds the length of the list. %d is not inserted.\n",key);
        }
    }

}
void deleteFirst()
{

}

void deleteLast()
{

}
void deleteAt(int pos)
{
    if(pos<0)
    {
        printf("Invalid position.\n");
    }
    else if(pos==0)
    {
        deleteFirst();
    }
    else
    {
        int current_position=0;
        struct node *current=head;
        while(current!=NULL && current_position<pos-1)
        {
            current=current->next;
            current_position++;
        }
        if(current==NULL)
        {
            printf("Position exceeds the length of the list. Can't be deleted at position %d.\n",pos);

        }
        else
        {
            struct node *t=current->next;
            current->next=current->next->next;
            free(t);
        }
    }
}

int search(int x){

}

void printList() {
    printf("LinkList: ");
    struct node *t = head;

    while (t != NULL) {
        printf("%d ", t -> data);
        t = t -> next;
    }
    printf("\n");
    printf("\n");
}

int main() {
    int choice,key,pos;
    printf("1.insert first 2.insert last 3.insert at\n");
    printf("4.delete first 5.delete last 6.delete at 7.search 8.exit\n");
    while(1){

        printf("enter choice:");
        scanf("%d",&choice);
        if(choice==1){
            printf("enter element:");
            scanf("%d",&key);
            insertBeginning(key);
        }else if(choice==2){
            printf("enter element:");
            scanf("%d",&key);
            insertLast(key);
        }else if(choice==3){
            printf("enter position:");
            scanf("%d",&pos);
            printf("enter element:");
            scanf("%d",&key);
            insertAt(key,pos);
        }else if(choice==4){
            deleteFirst();
        }else if(choice==5){
            deleteLast();
        }else if(choice==6){
            printf("enter position:");
            scanf("%d",&pos);
            deleteAt(pos);
        }else if(choice==7){
            printf("enter element:");
            scanf("%d",&key);
            int idx=search(key);
            if(idx==-1){
                printf("%d is not in the list.\n",key);
            }else{
                printf("The key is found at:%d\n",idx);
            }
        }else{
            break;
        }
        printList();
    }
}
