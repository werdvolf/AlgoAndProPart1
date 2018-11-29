#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int sum( int arr[10][10])
{
 int k = 0;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < i; j++){
                k += arr [i] [j];
        }
    }
    return(k);
}

int main(void){

    srand(time(NULL));

    int arr[10][10];

    for(int i = 0; i < 10; i++){
        for( int j = 0; j < 10; j++){
            arr[i][j] = rand()%9;
            printf("%d ", arr[i][j]);
                if(j == 10 - 1)
            printf("\n");
        }
    }
    int r;

    r = sum(arr);


    printf("\nsumm of elements under diagonal %d\n", r);

}