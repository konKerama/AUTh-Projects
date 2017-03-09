#include <stdio.h>
#include <math.h>
void alarm (int min,int x1,int y1,int z1,int x2,int y2,int z2,int *i,float *dis);
void main()
{
    int min,x1,y1,z1,x2,y2,z2,i;
    float dis;
    char id[11];
    printf("Dwse apostasi asfaleias: \n");
    scanf("%d",&min);
    printf("Dwse tis sintetagmenes tou aeroplanou pou ferei to sistima \n");
    scanf("%d",&x1);
    scanf("%d",&y1);
    scanf("%d",&z1);
    do
    {
        printf("Dwse tautotita aeroplanou \n");
        scanf("%s",id);
        printf("Dwse tis sintetagmenes tou allou aeroplanou \n");
        scanf("%d",&x2);
        scanf("%d",&y2);
        scanf("%d",&z2);
        alarm(min,x1,y1,z1,x2,y2,z2,&i,&dis);
        if (i==0)
        {
            printf("%s \n",&id);
            printf("%f \n",dis);
        }else if (i==1)
        {
            printf("Kitrinos Sinagermos \n");
            printf("%s \n",&id);
            printf("%f \n",dis);
        }else
        {
            printf("Kokkinos Sinagermos \n");
            printf("%s \n",&id);
            printf("%f \n",dis);
        }
        printf("Dwse tis sintetagmenes tou aeroplanou pou ferei to sistima \n");
        scanf("%d",&x1);
        scanf("%d",&y1);
        scanf("%d",&z1);
    }while (z1!=0);
}

void alarm (int min,int x1,int y1,int z1,int x2,int y2,int z2,int *i,float *dis)
{
    *dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
    if (dis>min)
    {
        *i=0;
    }else if ((dis<min)&&(dis>(3/4)*min))
    {
        *i=1;
    }else
    {
        *i=2;
    }
}


