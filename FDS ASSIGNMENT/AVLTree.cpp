#include <iostream>
using namespace std;

class node {
    public:
    node* root=NULL;
    int data;
    node* left;
    node* right;
    int height;

    node(){
        data=0;
        left=NULL;
        right=NULL;
        height=1;
    }

    node* returnroot(){
        node* temp=root;
        if(root==NULL){
            return NULL;
        }
        else{
            return temp;
        }
    }

    int max(int x,int y){
        return (x>y)?x:y;
    }

    int height1(node* n){
        if(n==NULL){
            return 0;
        }
        return n->height;

    }

    int getbalancefactor(node* root){
        if(root==NULL){
            return 0;
        }
        else{
            return height1(root->left)-height1(root->right);
        }
    }

    node* rightRotate(node* y) {
        node *x = y->left;
        node *T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height1(y->left),height1(y->right)) + 1;
        x->height = max(height1(x->left),height1(x->right)) + 1;
        return x;
    }


    node* leftRotate(node *x) {
        node *y = x->right;
        node *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height1(x->left), height1(x->right)) + 1;
        y->height = max(height1(y->left), height1(y->right)) + 1;
        return y;
    }



    node* insert(int data , node* root){
        int x,y;
        node* newnode=new node;
        newnode->data=data;
        if(root==NULL){
            root=newnode;
            return root;
        }
        else if(data > root->data){
            root->right=insert(data,root->right);
        }
        else if(data < root->data){
            root->left=insert(data,root->left);
        }
        else{
            return root;
        }
        root->height = 1 + max(height1(root->left) , height1(root->right));
        int balancefactor = getbalancefactor(root);

        if(balancefactor>1){
            if (data < root->left->data){  
                return rightRotate(root);
            } 
            else if (data > root->left->data){ 
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }

        if (balancefactor < -1) {
            if (data > root->right->data){
                return leftRotate(root);
            } 
            else if (data < root->right->data){ 
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }

    return root;
    }

    void inorder(node *root) {
        if (root != NULL) {
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }


};

int main(){
    int ch,data;
    node s;
    node* temp;
    do{
        cout<<"\n0:to exit\n1:to add data\n2:to display\n";
        cin>>ch;
        switch(ch){
            case 1:{
                cout<<"enter the data:\n";
                cin>>data;
                temp=s.insert(data,s.returnroot());
                break;
                }
            case 2:{
                s.inorder(s.returnroot());
                break;
            }       
        }
        
    }while(ch!=0);
}
