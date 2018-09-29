#include<stdio.h>
#include<math.h>
long factorial(int);
int main(void)
{

float n=1,summ=0;
double a;
do
{
a=pow(10,n)/factorial(n);
if (a<0.0001)
{
break;
}
n++;
summ=summ+a;

}
while (a>=0.0001);
printf("%f\n",summ);

}

long factorial(int n)
{
int c;
long result=1;
for(c=1;c<=n;c++)
result= result*c;

return result;
}

