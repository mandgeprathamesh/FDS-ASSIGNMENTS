#include<stdio.h>
#include<stdlib.h>
void createnode();
void displaylist();
struct node
{
    int data;
    struct node* next;
}* head; 
void main()
{
    int d,ch;
    do {printf("1:to add more data \n2:to display\n3:to reverse list\n");
    scanf("%d",&ch);
    switch (ch){
        case 1:
            createnode();
            break;
        case 2:
            displaylist();
            break; 
        case 3:       
    }
}while(ch!=0);
}
void createnode()
{
    struct node* newnode,*t;
    int d;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data:\n");
    scanf("%d",&d);
    newnode->data=d;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        t=head;
        while(t->next){
            t=t->next;
        }
        t->next=newnode;
    }
}
void displaylist(){
    struct node* temp;
    temp=head;
    printf("the linkedlist is:\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}