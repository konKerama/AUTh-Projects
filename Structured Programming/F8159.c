#include <stdio.h>
#include <stdlib.h>
void penalty (int n,int *orio,int *num,float **speed,int **result);
void main()
{
    int *orio,*num,**number,**result;
    float **speed;
    int n,i,max,j;
    printf ("Dwse arithmo kamerwn: \n");
    scanf ("%d",&n);
    orio=(int *)malloc(n*sizeof(int*));
    num=(int *)malloc(n*sizeof(int*));
    for (i=0;i<n;i++)
    {
        printf ("Dwse orio taxititas kai arithmo paravatwn gia tin kamera %d: \n",i);
        scanf ("%d %d",&orio[i],&num[i]);
    }
    speed=(int *)malloc(n*sizeof(int*));
    number=(int *)malloc(n*sizeof(int*));
    result=(int *)malloc(n*sizeof(int*));
    for (i=0;i<n;i++)
    {
        speed[i]=(int*) malloc(num[i]*sizeof(int));
        number[i]=(int*) malloc(num[i]*sizeof(int));
        result[i]=(int*) malloc(num[i]*sizeof(int));
    }
    for (i=0;i<n;i++)
    {
        printf ("Kamera %d: \n",i);
        for (j=0;j<num[i];j++)
        {
            printf ("Dwse taxitita kai arithmo kykloforia tou autokinitou: %d \n",j);
            scanf ("%d %d",&speed[i][j],&number[i][j]);
        }
    }
    penalty(n,orio,num,speed,result);
    for (i=0;i<n;i++)
    {
        printf("Kamera %d: \n",i);
        for (j=0;j<num[i];j++)
        {
            printf ("Arithmos Autokinitou: %d \n",number[i][j]);
            printf ("Taxitia: %d \n",speed[i][j]);
            printf ("Katigoria paravasis: %d \n",result[i][j]);
        }
    }
}

void penalty (int n,int *orio,int *num,float **speed,int **result)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<num[i];j++)
        {
            if (speed[i][j]<=(1.1*orio[i]))
            {
                result[i][j]=1;
            }
            else if (speed[i][j]>(1.1*orio[i])&&(speed[i][j]<=(1.2*orio[i])))
            {
                result[i][j]=2;
            }
            else
            {
                result[i][j]=3;
            }
        }
    }
}
