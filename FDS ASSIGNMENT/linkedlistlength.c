#include<stdio.h>
#include<stdlib.h>
void createList(int n);
void lengthcal();
struct node {
    int data;           
    struct node* next;  
}*head;
int main()
{
    int n;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    lengthcal();
    return 0;
}
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    head->data = data; 
    head->next = NULL;

    temp = head;
    for(i=2; i<=n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; 
        newNode->next = NULL; 

        temp->next = newNode; 
        temp = temp->next;   
}
}
void lengthcal(){
    struct node* temp;
    temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    printf("length of linkedlist is:%d\n",count);

}