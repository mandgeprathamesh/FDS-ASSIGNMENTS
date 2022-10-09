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
    int a[3][3],b[3][3],c[3][3],d[3][3]={0},ch,i,j,k,sum=0,min,max,flag=0;
    int *p,*q;
    p=&a[0][0];
    q=&b[0][0];
    printf("enter A array elements:\n");
    for( i=0;i<3;i++){
        for( j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter B array elements:\n");
    for( i=0;i<3;i++){
        for( j=0;j<3;j++){
            scanf("%d",&b[i][j]);
        }
    }
    printf("1:for additon\n2:for multiplication:\n3:for saddle point:\n");
    scanf("%d\n",&ch);
    switch(ch){
        case 1:
        for( i=0;i<3;i++){
            for( j=0;j<3;j++){
                c[i][j]=*(p+i*3+j)+*(q+i*3+j);
            }
        }
        printf("additon of matrix A and B is :\n");
        for( i=0;i<3;i++){
            for( j=0;j<3;j++){
                printf("%d \t",c[i][j]);
            }printf("\n");
        
        }
        break;
        case 2:
        for( i=0;i<3;i++){
            for( j=0;j<3;j++){
                for(k=0;k<3;k++){
                    sum+=(*(p+i*3+k))*(*(q+k*3+j));
                }d[i][j]=sum;
                sum=0;
            }
        }
         printf("multiplication of matrix A and B is :\n");
        for( i=0;i<3;i++){
            for( j=0;j<3;j++){
                printf("%d \t",d[i][j]);
            }printf("\n");
        }
        break;
        case 3:
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
        break;
}
}

