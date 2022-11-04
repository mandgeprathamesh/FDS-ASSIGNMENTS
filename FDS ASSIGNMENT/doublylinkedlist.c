#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char name[10];
    int prn;
    struct node* next;
    struct node* prev; 
};
void insert(struct node* );
void display(struct node* );
void main(){
    struct node*head;
    head=(struct node*)malloc(sizeof(struct node));
    printf("enter the name and prn of president : \n");
    scanf(" %s\n",head->name);
    scanf("%d\n",&head->prn);
    head->next=NULL;
    head->prev=NULL;
    insert(head);
    display(head);

}
void insert (struct node* head){
    struct node* new;
    new=(struct node*)malloc(sizeof(struct node));
    printf("enter the name and prn of SECRETARY:\n");
    scanf(" %s",new->name);
    scanf("%d",&new->prn);
    head->next=new;
    new->prev=head;
}
void display(struct node*  head){
    struct node* temp;
    temp=head;
    while(temp!=NULL){
        printf("name: %s \t PRN:%d\n",temp->name,temp->prn);
        temp=temp->next;
    }
}