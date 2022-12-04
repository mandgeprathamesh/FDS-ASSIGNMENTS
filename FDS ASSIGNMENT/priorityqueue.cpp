#include<iostream>
using namespace std;
class queue{
    private:
    int q[3];
    int front;
    int rear;
    int size;
    public:
    queue(){
        rear=-1;
        front=-1;
        size=3;
    }
    void enqueue(){
        int x,i,j;
        cout<<"enter the value:\n";
        cin>>x;
        if(rear==-1){
            front++,rear++;
            q[rear]=x;
        }
        else if(rear==size-1){
            cout<<"overflow\n";
        }
        else{
            for(i=front;i<=rear;i++){
                if(x>q[i]){
                    j=i;
                    break;
            }
        }
        for(j;j<=rear;j++){
            q[i+1]=q[i];
        }
            q[j]=x;
        }
    }
    void dequeue(){
        if(front==-1){
            cout<<"underflow\n";
        }
        else if(rear==front){
             cout<<"deleted:"<<q[front]<<endl;
             rear=front=-1;
        }
        else{
            cout<<"deleted successfully:\n"<<q[front]<<endl;
            front++;
        }
    }
    void print(){
        if(front==-1){
            cout<<"queue is empty\n";
        }
        else{
        for(int i=front;i<=rear;i++){
            cout<<q[i]<<" ";
        }
        cout<<endl;
        }
    }

};
int main(){
    queue s;
    int ch;
    while(1){
        cout<<"\n0:to exit\n1:to enqueue\n2:to dequeue\n3:to display the queue\n";
        cin>>ch;
        switch(ch){
            case 1:{
                    s.enqueue();
                    break;
                    }
            case 2:{
                    s.dequeue();
                    break;
                    }
            case 3:{
                    s.print();
                    break;
                    }                
        }
    }
}