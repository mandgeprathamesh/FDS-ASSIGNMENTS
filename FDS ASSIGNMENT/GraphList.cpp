#include<iostream>
using namespace std;

class node{
    public:
        int data;
        int vertex;
        node* next;
};


class adjlist{
    private:
        node* start;
        int vertex;
    public:

        adjlist(){
            start=NULL;
        }

        void setvertex(int v){
            vertex=v;
        }

        void addnode(int v,int data){
            node* n=new node;
            n->data=data;
            n->vertex=v;
            n->next=start;
            start=n;
        }

        void printList(){
            node *t;
            t=start;
            while(t)
            {
                cout<<" ("<<t->vertex<<","<<t->data<<") ";
                t=t->next;
            }
        }

};


class graph{
    private: 
        int v_count;
        adjlist* arr;
    public:

        graph(){
            v_count=0;
            arr=NULL;
        }

        void creategraph(){
            int n,v,data;
            cout<<"enter the no of vertex:\n";
            cin>>v_count;
            arr=new adjlist[v_count];
            for(int i=0;i<v_count;i++){
                arr[i].setvertex(i);
                cout<<"\nHow many adjacent nodes of V"<<i<<":";
                cin>>n;
                for(int j=0;j<n;j++){
                    cout<<"\nEnter vertex number: ";
                    cin>>v;
                    cout<<"\nEnter data to store: ";
                    cin>>data;
                    arr[i].addnode(v,data);
                }

            }
        }

        void printgraph(){
            for(int i=0;i<v_count;i++)
            {
                cout<<endl;
                arr[i].printList();
            }
        }

};

int main(){
    graph s;
    int ch;
    do{
        cout<<"\n0: to exit\n1:to create graph\n2:to display graph\n";
        cin>>ch;
        switch(ch){
            case 1:
                    s.creategraph();
                    break;

            case 2:
                    s.printgraph();
                    break;        
        }

    }while(ch!=0);
}