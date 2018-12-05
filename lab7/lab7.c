#include <stdio.h>
#include <stdarg.h>

void min(size_t amount, ...){
    va_list ap;
    int a, min=9999;
    va_start( ap, amount );
    printf( "\nTotal numbers: %d.\n", amount);
    printf("Numbers: ");
    while(amount!=0){
        a = va_arg( ap, int );
        if(amount==1)
            printf("%d.\n", a);
        else
            printf("%d, ", a);
        if(a<min){
            min = a;
        }
        amount--;
    }
    printf("Minimum number is: %d\n", min);
}

int main(void){
    min(5,  1, 6, 3, 4, 10);
    min(10, 33, 34, 456, 95, 21, 56, 2234, 75, 66, 456);
    min(12, 45, 34, 222, 2324, 45, 51, 345, 34, 111, 54, 43, 123);
    
    printf("\n");
    return 0;
}