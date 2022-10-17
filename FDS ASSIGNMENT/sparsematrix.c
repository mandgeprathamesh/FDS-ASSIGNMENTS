#include<stdio.h>
void main(){
    int row,col,i,j,k=0,count=0;
    printf("enter no. of rows and columns:\n");
    scanf("%d%d\n",&row,&col);
    int a[row][col];
    for(  i=0;i<row;i++){
        for( j=0;j<col;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0){
                k++;
            }
        }
    }
    int s[k][3],p;
    printf("the matrix is:\n");
    for(  i=0;i<row;i++){
        for( j=0;j<col;j++){
            printf("%d \t",a[i][j]);
        }
        printf("\n");
    }
    for(  i=0;i<row;i++){
        for( j=0;j<col;j++){
            if(a[i][j]==0){
                count++;
            }
        }
    }
    if(count>((row+col)/2)){
        printf("|sparse matrix|\n");
    }
    else{
        printf("|Not a sparse matrix|");
    }
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(a[i][j]!=0){
                s[p][0]=i;
                s[p][1]=j;
                s[p][2]=a[i][j];
                p++;
            }
        }
    }
    for(i=0;i<k;i++){
        for(j=0;j<3;j++){
            printf("%d \t",s[i][j]);
        } printf("\n");
    }
}
