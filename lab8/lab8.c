#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
int amnt;
typedef struct{
char* name;
char* adress;
char* med;
char* polis;
} PATIENTS;
//PROTOTYPES OF FUNCTIONS/////////////////////////////////////////////////////
void WRITE(PATIENTS c, int amnt);
void READ(PATIENTS re[amnt]);
void DELETE(PATIENTS re[amnt],int key);
void FIND(PATIENTS re[amnt], char com[25]);
void ADD(PATIENTS re[amnt]);
void SAVE(PATIENTS re[amnt]);
//MAIN////////////////////////////////////////////////////////////////////////
int main(){
PATIENTS c;
printf("Amount of patients is ");
int amnt = GetInt();
PATIENTS re[amnt+1];
WRITE(c, amnt);
READ(re);
printf("The Medical ID to find is ");
char com[25];
scanf("%s", com);
FIND(re, com);
ADD(re);
SAVE(re);
}


void WRITE(PATIENTS c, int amnt){
FILE *f;
if ((f = fopen("f.bin", "wb")) == NULL)exit(1);
for (int i = 1; i <= amnt; i++){
printf("Name #%i is ", i); c.name=GetString();
printf("Adress #%i is ", i); c.adress=GetString();
printf("Medical ID #%i is ", i); c.med=GetString();
printf("Polis number #%i is ", i); c.polis=GetString();
fwrite(&c, sizeof(PATIENTS), 1, f);
}
fclose(f);
}


void READ(PATIENTS re[amnt]){
FILE *f;
if ((f = fopen("f.bin", "rb")) == NULL) exit(1);
int i = 0;
while (!feof(f) && (i < amnt)){
fread(&re[i], sizeof(PATIENTS), 1, f);
i++;
}
fclose(f);
}


void DELETE(PATIENTS re[amnt], int key){
    for(int i=key; i<amnt; i++){
        re[i]=re[i+1];
    }
    amnt--;
}


void FIND(PATIENTS re[amnt], char com[25]){
int cur;
bool equal;
for (cur = 0; cur < amnt; cur++){
equal = 1;
for (int j = 0; com[j] != '\0'; j++) if(com[j] != re[cur].med[j]) equal = 0;
if (equal) break;
}
if (equal) DELETE (re, cur);
printf("DELETED\n");
}


void ADD(PATIENTS re[amnt]){
for (int i = 3; i < amnt+1; i++) re[i+2] = re[i];
for (int j = 1; j <=2; j++){
printf("New name is "); scanf("%s", re[j].name);
printf("New adress is "); scanf("%s", re[j].adress);
printf("New Medical ID is "); scanf("%s", re[j].med);
printf("New polis is "); scanf("%s", re[j].polis);
amnt++;
}
}


void SAVE(PATIENTS re[amnt]){
FILE *f;
if ((f = fopen("f.bin", "w")) == NULL) exit(1);
for (int i = 0; i < amnt; i++) fwrite(&re[i], sizeof(PATIENTS), 1, f);
fclose(f);
printf("\n\x1b[32mChanges have been saved\x1b[0m\n\n");
}