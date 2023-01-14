#include<iostream>
#include  <bits/stdc++.h>
using namespace std;

class node{
    private:
    node* head=NULL;
    int empid;
    char empname[20];
    char emppost[20];
    long long int num;
    node* next;
    node* prev;

    public:

    node(){
        next=NULL;
        prev=NULL;
    }

    void insertdataatend(){
        node* temp=head;
        node* newnode=new node;
        cout<<"enter the id :\n";
        cin>>newnode->empid;
        cout<<"enter the name of employee:\n";
        cin.ignore();
        cin.getline(empname,20);
        cout<<"enter the post:\n";
        cin.ignore();
        cin.getline(emppost,20);
        cout<<"enter you number:\n";
        cin.ignore();
        cin>>newnode->num;
        if(head==NULL){
            head=newnode;
        }
        else{
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }


    void deletenode(){
        int ch;
        cout<<"enter the id to delete\n";
        cin>>ch;
        node* temp=head;
        node* newnode;
        if(head==NULL){
            cout<<"No Data Available to Delete\n ";
        }
        else if(temp->empid==ch){
            newnode=temp;
            temp=temp->next;
            temp->prev=NULL;
            delete newnode;
            head=temp;
        }

        else{
            while(temp->next->empid!=ch){
                temp=temp->next;
            }
            if(temp->next->next==NULL){
                newnode=temp->next;
                temp->next=NULL;  
                delete newnode;
            }
            else{
                newnode=temp->next;
                node* temp1=newnode->next;
                temp->next=temp1;
                temp1->prev=temp;
                delete newnode;
            }
        }
    }

    void search(){
        int ch,flag=0;
        node* temp=head;
        cout<<"enter the id to search\n";
        cin>>ch;
        if(head==NULL){
            cout<<"no data available\n";
        }
        else{
            while(temp!=NULL){
                if(temp->empid==ch){
                    flag=1;
                }
                temp=temp->next;
            }

            if(flag==1){
                cout<<"element present\n";
            }
            else{
                cout<<"not present\n";
            }
        }
    }

    void display(){
        node* temp=head;
        if(temp==NULL){
            cout<<"no data there \n";
        }
        else{
            while(temp!=NULL){
                cout<<temp->empname<<" "<<temp->empid<<" "<<temp->emppost<<" "<<endl;
                temp=temp->next;
            }
        }
    }

    void reversedisplay(){
        node* temp=head;
        if(head==NULL){
            cout<<"no data available to show";
        }
        else{
            while(temp->next!=NULL){
                temp=temp->next;
            }
            while(temp!=NULL){
                cout<<temp->empname<<" "<<temp->empid<<" "<<temp->emppost<<" "<<endl;
                temp=temp->prev;
            }
        }
    }
};

int main(){
    node s;
    int ch;
    do{
        cout<<"------------------------------------------------------------------------------------------------------------------------------------";
        cout<<"    \n\t\t\t\t0:to exit\n\t\t\t\t1:to add data\n\t\t\t\t2:to delete data\n\t\t\t\t3:to search data\n\t\t\t\t4:to display data\n\t\t\t\t5:to display the data in reverse order\n";
        cout<<"------------------------------------------------------------------------------------------------------------------------------------\n";
        cout<<"enter your choice-->";
        cin>>ch;
        switch(ch){
            case 1:{
                s.insertdataatend();
                break;
            }

            case 2:{
                s.deletenode();
                break;
            }

            case 3:{
                s.search();
                break;
            }

            case 4:{
                s.display();
                break;
            }

            case 5:{
                s.reversedisplay();
                break;
            }
        }
    }
    while(ch!=0);
}