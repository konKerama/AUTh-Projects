/*
*  Author : Konstantinos Keramaris
*  Ampere , Volt and Watt
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
class device
{
protected:
    static device **M;
public:
    device(int v){};
    virtual float getp();
    virtual int asfaleia ();
    virtual float diatomi();
    virtual float getm();
};
//---------------------device1---------------------
class device1:public device
{
    float p,i,m,mm;
    int A;
public:
    device1(float v);
    float getp();
    float getm();
    int asfaleia ();
    float diatomi();
};

device1::device1(float v)
{
    cout <<"Dwse onomastiki isxi kai mikos: \n";
    cin >>p;
    cin >>m;
    i=p/v;
}

float device1::getp()
{
    return p;
}

float device1::getm()
{
    return m;
}

int device1::asfaleia ()
{
    if (i<10)
    {
        A=10;
    }else if(i<16)
    {
        A=16;
    }else if(i<20)
    {
        A=20;
    }else
    {
        A=25;
    }
    return A;
}

float device1::diatomi()
{
    if (A==10)
    {
        mm=1.5;
    }else if (A==16)
    {
        mm=2.5;
    }else if (A==20)
    {
        mm=6;
    }else
    {
        mm=10;
    }
    return mm;
}

//---------------------device2---------------------
class device2
{
    float p,p1,i,m,mm;
    int A;
public:
    device2(float v);
    float getp();
    float getm();
    int asfaleia ();
    float diatomi();
};

device2::device2(float v)
{
    float c,p2;
    cout <<"Dwse apaitoumeni isxi, isxi kinitira kai sintelesti c: \n";
    cin >>p1;
    cin >>p2;
    cin >>c;
    p=p1+p2*c;
    i=p/v
}

float device2::getp()
{
    return p1;
}

float device2::getm()
{
    return m;
}

int device2::asfaleia()
{
    if (i<10)
    {
        A=10;
    }else if(i<16)
    {
        A=16;
    }else if(i<20)
    {
        A=20;
    }else
    {
        A=25;
    }
    return A;
}

float device1::diatomi()
{
    if (A==10)
    {
        mm=1.5;
    }else if (A==16)
    {
        mm=2.5;
    }else if (A==20)
    {
        mm=6;
    }else
    {
        mm=10;
    }
    return mm;
}

//---------------------main------------------------
float get_total_P(device1 *d1,device2 *d2,int n1,int n2,int *asf,float *kal);
int main()
{
    int v,n1,n2;
    cout <<"Dwse tasi kai arithmo siskeuwn 1ou kai 2ou typou: \n";
    cin >>v;
    cin >>n1;
    cin >>n2;
    device **d(V);
    d=(device1)malloc(n1*sizeof(device1));
    d=(device2)realloc(P,n2*sizeof(device2));
    float p,*kal;
    int *asf;
    asf=(int)malloc(4*sizeof(int));
    kal=(float)malloc(4*sizeof(float));
    p=get_total_P(d1,d2,n1,n2,asf,kal);
    cout <<p;
    for (i=0;i<4;i++)
    {
        cout <<asf[i]<<kal[i];
    }
    return 0;
}

float get_total_P(device d,int n1,int n2,int *asf,float *kal)
{
    float p_total=0,temp;
    int i;
    for (i=0;i<n1+n2;i++)
    {
        temp=d[i].getp();
        p_total=p_total+temp;
    }
    int A;
    float mm,m;
    for (i=0;i<4;i++)
    {
        asf[i]=0;
        kal[i]=0;
    }
    for (i=0;i<n1+n2;i++)
    {
        A=d[i].asfaleia();
        mm=d[i].diatomi();
        m=d[i].getm();
        if (A==10)
        {
            asf[0]++;
            kal[0]=kal[0]+m;
        }else if(A==16)
        {
            asf[1]++;
            kal[1]=kal[1]+m;
        }else if(A==20)
        {
            asf[2]++;
            kal[2]=kal[2]+m;
        }else
        {
            asf[3]++;
            kal[3]=kal[3]+m;
        }
    }
}
