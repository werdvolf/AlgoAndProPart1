#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main()
{
    char* s;
    char w1[50] = "if";
    char w2[50] = "else";
    char w3[50] = "printf";

    printf("Your sentence: ");

    s=GetString();
    printf("identificators: ");
    if (strstr(s, w1) != NULL) {
        printf(" %s", w1);
    }
    else if (strstr(s, w2) != NULL) {
        printf(" %s\n", w2);
    }
    else if (strstr(s, w3) != NULL) {
        printf(" %s", w3);
    }


    int flag;
    int i=0, j=0, k=0;
    int l=strlen(s);
    printf("\nSentence without words that consist of digit: ");
    for(i=0; i<l; i++){
        flag=0;
        if(s[i] == ' ' || i == 0){
            k=i;
            while(s[i+1] != ' ' && i < l){
                i++;
                if(isalpha(s[i])){    
                    flag=1;
                }
            }
        }
        if(flag==1){
            for(j=k; j<i+2; j++){
                printf("%c", s[j]);
            }
        }
    }  
    printf("\n");   
}