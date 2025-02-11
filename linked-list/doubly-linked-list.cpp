#include <stdio.h>
#include <stdlib.h>

struct Node                                    /* Comment Enable */
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head=NULL;                         // DECLARING 'head' as GLOBAL VARIABLE
struct Node *tail=NULL;                         // DECLARING 'tail' as GLOBAL VARIABLE

typedef struct Node Node;                       // CREATING ALIAS NAME FOR struct NODE

void insertNode(int x)
{
    struct Node *temp;
    temp=(Node*)malloc(sizeof(Node));
    temp->data=x;                               // INSERT VALUE AT NODE
    temp->prev=NULL;                            // INSERT NULL IN POINTERS
    temp->next=NULL;
    
    if(head==NULL)                              // IF ONLY ONE NODE IS THERE, HEAD & TAIL BOTH ARE SAME
    {
    head=temp;
    tail=temp;
    }
    
    else
    {
        tail->next=temp;     // CREATING_FORWARD_LINK
        temp->prev=tail;     // CREATING_BACKWARD_LINK
        tail=temp;           // STORING_LAST_NODE_IN_TAIL
    }
    
}

void printForward(struct Node *temp)
{
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void printBackward(struct Node *temp)
{
   while(temp!=NULL) 
   {
       printf("%d ",temp->data);
       temp=temp->prev;
   }
   printf("\n");
}

int main()
{
    insertNode(10);
    insertNode(20);
    insertNode(30);
    insertNode(40);
    insertNode(50);
    
    printForward(head);
    printBackward(tail);
    return 0;
}
