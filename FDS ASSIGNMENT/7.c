#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define str struct abc
str{
    int PRN;
    char name[20];
    str *next,*prv;
}*head;
void createpres(){
    head=(str*)malloc(sizeof(str));
    printf("\nEnter the name and PRN of President : \n");
    scanf(" %s%d",head->name,&head->PRN);
    head->next=NULL;
    head->prv=NULL;
}
void insertsec(){
    str *new;
    new= (str*)malloc(sizeof(str));
    printf("\nEnter the name and PRN of Secretary : \n");
    scanf(" %s%d",new->name,&new->PRN);
    new->next=NULL;
    new->prv=NULL;
    new->prv=head;
    head->next=new;
}
void insert_mem(){
    str *new,*temp;
    temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    new= (str*)malloc(sizeof(str));
    printf("\nEnter the name and PRN of member : \n");
    scanf(" %s%d",new->name,&new->PRN);
    new->next=NULL;
    new->prv=NULL;
    new->next=temp->next;
    new->prv=temp->next->prv;
    temp->next=new;
    temp->next->prv=new;
}
void display(){
    str *temp;
    temp=head;
    printf("\nList of members in the club:\n");
    while(temp!=NULL){
        printf(" %s  ->  %d\n",temp->name,temp->PRN);
        temp=temp->next;
    }
}
void delete_mem(){
    printf("Enter the name of a member to delete : ");
    char mem_name[20];
    scanf(" %s",mem_name);
    str * temp,*back;
    temp=head->next;
    back=head;
    while((strcmp(temp->name,mem_name)) && temp->next!=NULL){
        back=temp;
        temp=temp->next;
    }
    if(temp->next==NULL){
        printf("Member is not in the list..\n");
    }
    else{
        back->next=temp->next;
        free(temp);
        printf("The selected member has been deleted..\n");
    }
}
void delete_pres(){
    str *temp;
    temp=head;
    free(head);
    head=temp->next;
    printf("\nThe President has been deleted..\n");
}
void delete_sec(){
    str *temp, *back;
    temp=head;
    back=head;
    while(temp->next!=NULL){
        back=temp;
        temp=temp->next;
    }
    back->next=temp->next;
    free(temp);
    printf("\nThe secretary has been deleted..\n");
}
void count_mem(){
    str *temp;
    int count=0;
    temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    printf("Total members are %d\n",count);
}
void reverse(){
    str *temp,*swap;
    temp=head;
    while(temp!=NULL){
        swap=temp->prv;
        temp->prv=temp->next;
        temp->next=swap;
        if(temp->prv==NULL){
            head=temp;
        }
        temp=temp->prv;
    }
    printf("The members list has been reversed..\n");
    
}
void main()
{   
    printf("\n~~~ Welcome to Pinnacle Club ~~~\n");
    createpres();
    insertsec();
    rep:
    printf("\n1. Insert a member\n2. Delete a member\n3. Delete President\n4. Delete Seretary\n5. Count members\n6. Reverse member's list of club\n7. Display list of members\n\nSelect an option to perform : ");
    int ch;
    scanf("%d",&ch);
    switch(ch){
        case 1: insert_mem();
                break;
        case 2: delete_mem();
                break;
        case 3: delete_pres();
                break;
        case 4: delete_sec();
                break;
        case 5: count_mem();
                break;                                  
        case 6: reverse();
                break; 
        case 7: display();
                break;
        default: goto rep;
    }
    printf("\nDo you to perform it again (Y/N) : ");
    char q;
    scanf(" %c",&q);
    if(q=='y'||q=='Y'){
        goto rep;
    }
}