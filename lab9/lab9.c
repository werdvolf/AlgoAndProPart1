#include<stdio.h>
#include<string.h>
#include <ctype.h>
#define LEN 255
void print_file(FILE *F){

    char output[LEN];
    while(fgets(output, LEN, F)){
        printf("%s",  output);
    }
    printf("\n");
}

int main()
{
    FILE *f1;
    FILE *f2;
    f1=fopen("f1.txt","w+r");
    f2=fopen("f2.txt","w+r");
    if((f1=fopen("f1.txt","w+"))==NULL || (f2=fopen("f2.txt","w+"))==NULL){
        printf("Error reading file!\n");
    }
    int counter = 0;
    char a[257];
    int n;
    int count = 0;
    printf("Put the amount of strings:\n");
    scanf("%d", &n);
    getchar();
    char max[50];
    for(int i=0; i<n;i++){
        printf("Put the string %d to file1:\n", i);
        fgets(a,255,stdin);
        for(int k = 0; k<strlen(a);k++){
            if(a[k] == ' '  && isalpha(a[k+1])){
                counter++;
            }
        }
        if(counter==0){
            fputs(a, f2);
        }

        if(count < strlen(a) && counter<1){
            for(int m = 0; m < strlen(a); m++){
                max [m] = a[m];
            }
        }
        counter=0;
        fputs(a,f1);
    }
    fclose(f1);
    fclose(f2);

    printf("F1:  ");
    print_file(f1);
    printf("F2:  ");
    print_file(f2);
    printf("Max word in f2:  ");
    for(int m = 0; m < strlen(max); m++){
        printf("%c", max[m]);
    }
    printf("\n\n");

    return 0;
}