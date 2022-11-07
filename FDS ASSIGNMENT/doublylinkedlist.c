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
void insertnode(struct node*);
void deletepresident(struct node*);
void deletesecretary(struct node*);
void main(){
    struct node*head;
    int i,ch;
    head=(struct node*)malloc(sizeof(struct node));
    printf("enter the name and prn of president : \n");
    scanf(" %s\n",head->name);
    scanf("%d\n",&head->prn);
    head->next=NULL;
    head->prev=NULL;
    insert(head);
    display(head);
    do{
        printf("1:to add memeber\n2:display the list\n3:to delete the president\n4:delete secretary\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            {
                insertnode(head);
                break;
            }
            case 2:
            {
                display(head);
                break;
            }
            case 3:
            {
                deletepresident(head);
                break;
            }
            case 4:
            {
                deletesecretary(head);
            }
            
    }
}
while(1);
}
void insert (struct node* head){
    struct node* new;
    new=(struct node*)malloc(sizeof(struct node));
    //printf("enter the name and prn of SECRETARY:\n");
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
void insertnode (struct node* head){
    struct node* new;
    new=(struct node*)malloc(sizeof(struct node));
    printf("enter the name and prn of MEMBER:\n");
    scanf(" %s",new->name);
    scanf("%d",&new->prn);
    new->next=head->next;
    head->next=new;
    new->prev=head;
    new->next->prev=new;
}
void deletepresident(struct node* head){
    struct node* temp;
    temp=head->next;
    free(head);
    head=temp;
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