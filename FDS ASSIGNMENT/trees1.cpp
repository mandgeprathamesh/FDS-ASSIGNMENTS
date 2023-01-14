#include<iostream>
using namespace std;
class node{
    public:
        node* root=NULL;
        int data;
        node* left,*right;
        
        node(){
            data=0;
            right=NULL;
            left=NULL;
        }

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

    node* returnroot(){
        if(root==NULL){
            return NULL;
        }
        else{
            return root;
        }
    }
    void search(int data){
        node* temp=root;
        int count=0;
        while(temp!=NULL){
            if(temp->data==data){
                cout<<"element present\n";
                count++;
                break;
            }
        
            else if(data > temp->data){
                temp=temp->right; 
            }
            else{
                    temp=temp->left;
            }
        }
        if(count!=1){
            cout<<"element not present";
        }
    }

    node* deletenode(int data, node* root){
        if(root==NULL){
            return NULL;
        }
        if(data < root->data){
            root->left=deletenode(data,root->left);
        }
        else if(data > root->data){
            root->right=deletenode(data,root->right);
        }
        else{
                if ((root->left == NULL) && (root->right == NULL)){
                    delete root;
                    return NULL;
                }
                else if (root->left == NULL) {
                    node* temp = root->right;
                    delete root;
                    return temp;
                }
                else if (root->right == NULL) {
                    node* temp = root->left;
                    delete root;
                    return temp;
                }
                else{
                    node* temp = mintree(root->right);
                    root->data = temp->data;
                    root->right =deletenode(temp->data,root->right);
                    }
            }
            return root;
    }

    node* mintree(node* root){
        node* temp=root;
        if(temp==NULL){
            return NULL;
        }
        else{
            while(temp->left!=NULL){
                temp=temp->left;
            }
            return temp;
        }
    }

    node* maxtree(node* root){
        node* temp=root;
        if(temp==NULL){
            return NULL;
        }
        else{
            while(temp->right!=NULL){
                temp=temp->right;
            }
            return temp;
        }
    }

    int height(node* root){
        if(root==NULL){
            return 0;
        }
        else{
            int lheight=height(root->left);
            int rheight=height(root->right);
             if(lheight > rheight){
                return (lheight+1);
             }
             else{
                return (rheight+1);
             }
        }
        
    }

    void display(){
        int ch;
        do{
            cout<<"\n0:to exit\n1:to preorder\n2:to inorder\n3:to postorder\n";
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
    node s;
    do{
        int data;
        cout<<"\n0:to exit\n1:to insert\n2:to search\n3:to display\n4:to get the minimum element\n5:to get the maximum element\n6:to delete element\n7:to get the height of tree\n";
        cin>>ch;
        switch(ch){
            case 1:{
                    cout<<"enter the data to enter:\n";
                    cin>>data;
                    s.insert(data);
                    break;
                    }
            case 2:{
                    cout<<"enter the element to search:\n";
                    cin>>x;
                    s.search(x);
                    break;
                    }
            case 3:{
                    s.display();
                    break;
                    }     
            case 4:{
                    node* temp1=s.mintree(s.returnroot());
                    if(temp1!=NULL){
                        cout<<"minimum element is:"<<temp1->data;
                    }
                    else{
                        cout<<"no minimum element present";
                    }
                    break;
                    }
            case 5:{
                    node* next=s.maxtree(s.returnroot());
                    if(next!=NULL){
                        cout<<"maximum element is:"<<next->data;
                    }
                    else{
                        cout<<"no maximum element present";
                    }
                    break;
                    }   
            case 6:{
                    cout<<"enter the data to delete:\n";
                    cin>>y;
                    if(s.deletenode(y,s.returnroot())){
                        cout<<"deleted successfully\n";
                    }
                    else{
                        cout<<"data not found\n";
                    }
                    break; 
                    }                 
            case 7:{
                    cout<<"the height of subtree is:"<<s.height(s.returnroot())<<endl;
                    break;
                    }                                                           
        }
    }
    while(ch!=0);
} 