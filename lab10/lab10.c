#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, m, k;
	printf("Size of array\n");
    printf("Put number  of columns:");
    scanf("%d", &n);
    printf("Put number of rows:");
    scanf("%d", &m);
    printf("Put k:");
    scanf("%d", &k);

    if((k>m)||(k<0))
    {
        printf("Incorrect input");
    }

    int **mas;
    mas = (int**)malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        mas[i] = (int*)malloc(sizeof(int)*m);
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            mas[i][j] = rand()%10;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d", mas[i][j]);
            printf("|");
        }
        printf("\n");
    }
    printf("\n");


    for(int i = 0; i < n; i++)
    {
        mas[i] = (int*)realloc(mas[i],sizeof(int)*(m+1));
    }

    for(int i = m+1; i >= k; i--)
    {
        for(int j = 0; j < n; j++)
    {
        mas[j][i] = mas[j][i-1];
    }
    }
        for(int j = 0; j < m; j++)
    {
    mas[j][k-1] = rand()%10;
}


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
    {
        printf("%d", mas[i][j]);
        printf("|");
    }
    printf("\n");
    }

    for(int i = 0; i<n+1; i++)
    {
        free(mas[i]);
    }
    free(mas);
    return 0;
}
