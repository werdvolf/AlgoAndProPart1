#include<stdio.h>
#include<stdlib.h>

void print_arr();

int main()
{
    //r - стовпці //c - рядки
    int r = 4,c =4;
    int k;
    do {
    printf("In what position put a new column? -- ");
    scanf("%d",&k);
    }
    while((k>c) || (k<0));
    int arr; arr=(int)malloc(r*sizeof(int*)); for(int i=0; i<r; i++)
    {
        arr[i]=(int*)malloc(sizeof(int)*c); }
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            arr[i][j]=rand()%10; }
    }
    for(int i=0; i<r; i++) {
        for(int j=0; j < c; j++) {
            printf("%d",arr[i][j]);
            }
        printf("\n"); }printf("\n");
//    print_arr( **arr, r, c);
    
    for(int i=0; i<r; i++) {
        arr[i]=(int*)realloc(arr[i],sizeof(int)*(c+1)); }
    for(int i=c+1; i>=k; i--) {
        for(int j = 0; j<r; j++) {
            arr[j][i]=arr[j][i-1]; }
        
    }
    for(int j=0; j < c; j++)
    {
        arr[j][k-1]=rand() % 10;
    }
    for(int i=0; i<r;i++) {
        for(int j=0; j<c + 1; j++) {
            printf("%d", arr[i][j]);
            }
        printf("\n"); }
    for(int i=0; i<r+1;i++) {
        free(arr[i]); }
    free(arr);
    return 0;
}

//void print_arr(int **arr, int r, int c ) {
//    for (int i = 0; i < r; i++){
//        for (int j = 0; j < c; j++){
//            printf("%d", arr[i][j]);
//        }
//    }
//}
