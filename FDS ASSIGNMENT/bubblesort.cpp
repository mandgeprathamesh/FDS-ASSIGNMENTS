#include<iostream>
using namespace std;

void bubble_sort(int a[],int);
int main()
{
    int n,i;
    cout<<"enter no.of array elements:\n";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    bubble_sort(a,n);
    printf("after sorting array is:");
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

return 0;
}
void bubble_sort(int a[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        int count=0;
        for(j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                count=1;
            }
        }if(count==0)
        break;    
    }
}
