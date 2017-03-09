#include <stdio.h>
#include <math.h>

float f (float x)
{
    return 4*x*x+4*x+1;
}

float f_paragwgos (float x)
{
    return 8*x+4;
}

float nroot (float e,float x0,int max,int *n1);
float froot (float e,float x0,float x1,int max,int *n2);
int main ()
{
    float e,x0,x1,sol1,sol2;
    int max,n1,n2;
    n1=0;
    n2=0;
    printf ("Dwse ton arithmo e: \n");
    scanf ("%f",&e);
    printf ("Dwse tin timi x0: \n");
    scanf ("%f",&x0);
    printf ("Dwse tin timi x1: \n");
    scanf ("%f",&x1);
    printf ("Dwse arithmo megistwn epanalipsewn: \n");
    scanf ("%d",&max);
    sol1=nroot(e,x0,max,&n1);
    sol2=froot(e,x0,x1,max,&n2);
    printf("nroot: \n");
    if (n1<=max)
    {
        printf ("Lisi: %f \n Epanalipseis : %d",sol1,n1);
    }else
        printf ("Den vrethike lysh");

    printf("froot: \n");
    if (n2<=max)
        printf ("Lisi: %f \n Epanalipseis : %d",sol2,n2);
    else
        printf ("Den vrethike lysh");
    return 0;
}

float nroot (float e,float x0,int max,int *n1)
{
    int n;
    float x;
    x = x0 - (f(x0) / f_paragwgos(x0));
    n++;
    if (*n1>max)
    {
        *n1=n;
        return x;
    }
    else if (fabs(x-x0)<e)
    {
        *n1=n;
        return x;
    }else
    {
        x0=x;
        return nroot(e,x0,max,n);
    }
}

float froot (float e,float x0,float x1,int max,int *n2)
{
    int n;
    float x;
    x= x1 - ((x1-x0)*f(x1))/(f(x1)-f(x0));
    n++;
    if (*n2>max)
    {
        *n2=n;
        return x;
    }
    else if (fabs(x-x1)<e)
    {
        *n2=n;
        return x;
    }else
    {
        x0=x1;
        x1=x;
        return froot(e,x0,x1,max,n);
    }
}
