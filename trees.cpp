#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* left,*right;
        
        node(){
            data=0;
            right=NULL;
            left=NULL;
        }
};
class trees{
    private: node* root=NULL;
    public:
    void insert(int data){
        node* temp=root;
        node* newnode=new node;
        newnode->data=data;
        if(root==NULL){
            root=newnode;
        }
        else{
            while(temp->data!=data){

                if(data< temp->data){
                    if(temp->left==NULL){
                        temp->left=newnode;
                        temp=newnode;
                    }
                    else{
                        temp=temp->left;
                    }
                }
                else{
                    if(temp->right==NULL){
                        temp->right=newnode;
                        temp=newnode;
                    }
                    else{
                        temp=temp->right;
                    }
                }
            }
        }
    }
    node* search(int data){
        node* temp=root;
        if(temp==NULL){
            return NULL;
        }
        else{
            if(temp->data==data){
                return temp;
            }
            else{
                while(temp!=NULL&&temp->data!=data){
                    if(temp->data > data){
                        temp=temp->left;
                    }
                    else{
                        temp=temp->right;
                    }
                }
                return temp;
            }
        }
    }

    void minelement(){
        node* temp=root;
            if(temp==NULL){
                cout<<"empty tree\n";
            }
            else{
                while(temp->left!=NULL){
                temp=temp->left;
                }
            }
        cout<<"the minimum element is:"<<temp->data<<endl;;
    }

    void maxelement(){
        node* temp=root;
            if(temp==NULL){
                cout<<"empty tree\n";
            }
            else{
                while(temp->right!=NULL){
                temp=temp->right;
                }
            }
        cout<<"the maximum element is:"<<temp->data<<endl;;
    }


    void display(){
        int ch;
        do{
            cout<<"\n1:to preorder\n2:to inorder\n3:to postorder\n";
            cin>>ch;
            switch(ch){
                case 1:
                        preorder(root);
                        break;
                case 2:
                        inorder(root);
                        break;
                case 3:
                        postorder(root);
                        break;                
            }
        }
        while(ch!=0);
    }
    void preorder(node* root){
        if(root!=NULL){
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void inorder(node * root){
        if(root!=NULL){
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }

    void postorder(node * root){
        if(root!=NULL){
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
    }

   
};
int main(){
    int x,ch,y;
    trees s;
    do{
        int data;
        cout<<"\n0:to exit\n1:to insert\n2:to search\n3:to display\n4: to find minimum element\n5:to find max element\n6:to delete data\n"; 
        cin>>ch;
        switch(ch){
            case 1:
                    cout<<"enter the data to enter:\n";
                    cin>>data;
                    s.insert(data);
                    break;
            case 2:
                    cout<<"enter the element to search:\n";
                    cin>>x;
                    if(s.search(x)!=NULL){
                        cout<<"element present\n";
                    }
                    else{
                        cout<<"element not present\n";
                    }

                    break;
            case 3:
                    s.display();
                    break;  
            case 4:
                    s.minelement();
                    break;
            case 5:
                    s.maxelement();
                    break;      
            case 6:
                    cout<<"enter the data to delete:\n";
                    cin>>y;
                    // s.delete(y);
                    break;

        }
    }
    while(ch!=0);
    
}