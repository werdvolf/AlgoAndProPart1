#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int mas[n];
    
    
    for(int i=0; i<n ; i++){
        mas[i]=rand()%9;
        printf("%d", mas[i]);
    }
    
    int m;
    printf("\n");
    printf("What element to delete: ");
    scanf("%d",&m);
    
    int l=0;
    int newSize = n;
    int newArray[newSize];
    int flag=0;
    for(int i=0; i<n; i++){
        if(mas[i]==m && flag==0){
            flag = 1;
            newSize--;
        }
        else{
            newArray[l] = mas[i];
            l++;
        }
    }
    
    for(int i=0; i<newSize; i++){
        printf("%d", newArray[i]);
    }
    int k, t;
    printf("\nhow many elements to move to the right? - ");
    scanf("%d", &k);
    
    for (int i = 0; i < k; ++i) 
    { 
        t = newArray[newSize-1]; 
        for (int j = newSize - 1; j > 0; j--) 
            newArray[j] = newArray[j-1]; 
        newArray[0] = t;
    }
 
     for (int i = 0; i < newSize; ++i) 
        printf("%d", newArray[i]);
}