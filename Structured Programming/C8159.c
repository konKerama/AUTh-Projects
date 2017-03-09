#include <stdio.h>
#define N 5
void main()
{
    int i,j,k,pos,min,w,n,m;
    int dis[5][5],copy[5][5],sum[5];
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            if (i!=j)
            {
                printf("Dwse varos diadromis apo %d se %d \n ",i,j);
                scanf("%d",&dis[i][j]);
                copy[i][j]=dis[i][j];
            }
            else
            {
                copy[i][j]=dis[i][j]=0;
            }
        }
    }
    for (i=0;i<N;i++)
    {
        sum[i]=0;
    }
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            dis[j][i]=0;
        }
        k=i;
        for (w=0;w<N-1;w++)
        {
            min=999999999;
            for (j=0;j<N;j++)
            {
                if((dis[k][j]!=0)&&(dis[k][j]<min))
                {
                    pos=j;
                    min=dis[k][j];
                }
            }
            sum[i]=sum[i]+min;
            for (j=0;j<N;j++)
            {
                dis[j][pos]=0;
            }
            k=pos;
        }
        for (m=0;m<N;m++)
        {
            for (n=0;n<N;n++)
            {
                dis[m][n]=copy[m][n];
            }
        }
    }
    min=99999999999999;
    for (i=0;i<N;i++)
    {
        if(sum[i]<min)
        {
            pos=i;
            min=sum[i];
        }
    }
    printf("I mikroteri apostasi einai:%d",min);
}
