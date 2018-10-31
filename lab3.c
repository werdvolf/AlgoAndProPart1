# #include <stdio.h>
#include <math.h>

float sum(int n, float x);

int main(void)
{
    float     a = 0.1;
    float     b = 0.8;
    float     e = 0.0001;
    int       n = 3;


    for(float x=a; x<=b; x+=(b-a)/10)
    {
        float y, sumn = 0, sume = 0;

        y = 0.25*logf((1+x)/(1-x))+0.5*atan(x);

        for(int j=1; j<=n; j++)
        {
            sumn += pow(x,(4*j+1))/(4*j+1);
        }

        int counter = 0;
        float inc = 0;

        do
        {
        	counter++;
            inc = pow(x,(4*counter+1))/(4*counter+1);
            sume += inc;
        }
        while( fabs(inc)>=e);

        printf("X=%.12f\tSumN=%.12f\tSumE=%.12f\tY=%.12f\n", x, sumn, sume, y);
    }

}

