#include<stdio.h>
int max_elementcolumn(int a[3][3],int );
int min_elementrow(int a[3][3],int );
int max_elementcolumn(int a[3][3],int j){
    int i,k;
    k=a[0][j];
        for(int i=0;i<3;i++){
            if(a[i][j]>k){
                k=a[i][j];
            }
    }
    return k;
}
int min_elementrow(int a[3][3],int i){
    int k,j;
    k=a[i][0];
        for(int j=0;j<3;j++){
            if(a[i][j]<k){
                k=a[i][j];
            }
    }
    return k;

}

void main(){
    int a[3][3],i,j,k,min,max,flag=0;
    printf("enter A array elements:\n");
    for( i=0;i<3;i++){
        for( j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for( i=0;i<3;i++){
        min=min_elementrow(a,i);
        for( j=0;j<3;j++){
            if(min==max_elementcolumn(a,j)){
                printf("saddle point is:\n");
                printf("%d",min);
                flag=1;
            }
            
       }
    }
    if(flag==0){
        printf("no saddle point\n");
    }
}