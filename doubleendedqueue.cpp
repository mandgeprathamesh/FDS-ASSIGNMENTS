#include<iostream>
using namespace std;
class queue{
    private:
    int q[100];
    int front;
    int rear;
    int size;
    public:
    queue(){
        rear=-1;
        front=-1;
        size=100;
    }

    void enqueuefront(){
        int x;
        cout<<"enter the value:\n";
        cin>>x;
        if(front>=1){
            --front;
            q[front]=x;
        }
        else{
            if(front==-1&&rear==-1){
                enqueuerear();
            }
            else{
                cout<<"not able to insert\n";
            }
        }

    }


    void enqueuerear(){
        int x;
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
            q[++rear]=x;
        }
    }


    void dequeuefront(){
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


    void dequeuerear(){
        if(rear==-1){
            cout<<"empty queue\n";
        }
        else if(rear==front){
            cout<<"deleted element is:"<<q[rear]<<endl;
            front=rear=-1;
        }
        else{
            cout<<"deleted element is:"<<q[rear]<<endl;
            rear--;
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
        cout<<"\n0:to exit\n1:to enqueue at rear\n2:to dequeue from front\n3:to display the queue\n4:to enqueue from front\n5:to dequeue from rear\n";
        cin>>ch;
        switch(ch){
            case 1:{
                    s.enqueuerear();
                    break;
                    }
            case 2:{
                    s.dequeuefront();
                    break;
                    }
            case 3:{
                    s.print();
                    break;
                    }  
            case 4:{
                    s.enqueuefront();
                    break;
                    }
            case 5:{
                    s.dequeuerear();
                    break;
                    }          
                             
        }
    }
}