#include<stdio.h>
#include<stdlib.h>
void createnode();
void displaylist();
void addstartnode();
void addendnode();
void addposnode();
struct node
{
    int data;
    struct node* next;
}* head; 
void main()
{
    int d,ch;
    do {printf("1:to add more data \n2:to display\n3:add a node at start\n4:add a node at end\n5:add node at any position\n");
    scanf("%d",&ch);
    switch (ch){
        case 1:
            createnode();
            break;
        case 2:
            displaylist();
            break;  
        case 3:
            addstartnode();       
            break;  
        case 4:
            addendnode();   
            break; 
        case 5:
            addposnode();
            break;
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
void addstartnode(){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data of newnode:");
    scanf("%d",&newnode->data);
    //newnode1->next=NULL;
    newnode->next=head;
    head=newnode;
    printf("after adding node ");
    displaylist();
}
void addendnode(){
    struct node*temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data of newnode:");
    scanf("%d",&newnode->data);
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
    printf("after adding node at last");
    displaylist();
}
void addposnode(){
    struct node*newnode,*p,*q;
    int pos,i=1;
    p=head;
    q=head->next;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data of newnode:");
    scanf("%d",&newnode->data);
    printf("enter the position of add:");
    scanf("%d",&pos);
    while(pos!=i){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=newnode;
    newnode->next=q;
    displaylist();    
}