#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct node{
    char name[20];
    int prn;
    struct node* next;
    struct node* prev; 
};
void insert(struct node* );
void display(struct node* );
void insertnode(struct node*);
void deletepresident(struct node*);
void deletesecretary(struct node*);

void main(){
    struct node*head;
    int i,ch;
    head=(struct node*)malloc(sizeof(struct node));
    printf("enter the name (President): \n");
    fflush(stdin);
    scanf("%s",head->name);
    printf("enter PRN (President):");
    fflush(stdin);
    scanf("%d",&head->prn);
    head->next=NULL;
    head->prev=NULL;
    printf("Enter Name And PRN For Secretary\n");
    insert(head);
    //display(head);
    while(1)
    {
        fflush(stdin);
        do{
            printf("0:to exit\n1:to add memeber\n2:display the list\n3:to change and insert new president\n4:chnage and add new secretary\n");
            scanf("%d",&ch);
            switch(ch){
                case 0:
                    exit(0);
                    break;
                
                case 1:
                    insertnode(head);
                    break;
                
                case 2:
                
                    display(head);
                    break;
                
                case 3:
                
                    deletepresident(head);
                    break;
                
                case 4:
                
                    deletesecretary(head);
                    break;
                
            }
        }while(ch!=0);
    }
}
void insert (struct node* head){
    struct node* newnode;
    printf("enter the name :\n");
    fflush(stdin);
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf(" %s",newnode->name);
    printf("enter the PRN:\n");
    fflush(stdin);
    scanf("%d",&newnode->prn);
    head->next=newnode;
    newnode->prev=head;
}
void display(struct node*  head){
    struct node* temp;
    temp=head;
    while(temp!=NULL){
        printf("name: %s\tPRN:%d\n",temp->name,temp->prn);
        temp=temp->next;
    }
}
void insertnode (struct node* head){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the name and prn of MEMBER:\n");
    scanf(" %s",newnode->name);
    scanf("%d",&newnode->prn);
    newnode->next=head->next;
    head->next=newnode;
    newnode->prev=head;
    newnode->next->prev=newnode;
}
void deletepresident(struct node* head){
    struct node* temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    temp=head->next;
    free(head);
    head=temp;
    printf("enter the name of new president:\n");
    scanf("%d",newnode->name);
    printf("enter the prn no:\n");
    scanf("%d",newnode->prn);
    newnode->next=head;
    head=newnode;
}
void deletesecretary(struct node* head){
    struct node* last,*temp;
    last=head;
    while(last!=NULL){
        last=last->next;
    }
    temp=last;
    last->prev->prev=NULL;
    free(temp);
}