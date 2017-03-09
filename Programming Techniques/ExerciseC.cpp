/*
*  Author : Konstantinos Keramaris
*  Circuit S and Circuit P
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//---------------------circuitS------------------------
class circuitS
{
    int n;
    float *R,*I_max;
public:
    circuitS(int k);
    circuitS(int k,int ran);
    float get_tres();
    void check(float V);
    void out();
};

circuitS::circuitS(int k)
{
    int i;
    n=k;
    R=(float *)malloc(k*sizeof(float));
    I_max=(float *)malloc(k*sizeof(float));
    for (i=0;i<n;i++)
    {
        cout <<"Dwse timi antistasis: \n";
        cin >>R[i];
        cout <<"Dwse megisti entasi reumatos: \n";
        cin >>I_max[i];
    }
}

circuitS::circuitS(int k,int ran)
{
    int minim,maxim,differ;
    int i;
    n=k;
    R=(float *)malloc(k*sizeof(float));
    I_max=(float *)malloc(k*sizeof(float));
    for (i=0;i<n;i++)
    {
        cout <<"Dwse katwtero kai anwtero orio antistasis: \n";
        cin >>minim;
        cin >>maxim;
        differ=maxim-minim;
        ran=rand() %differ + minim;
        R[i]=ran;
        cout <<"Dwse katwteri kai anwteri megisti entasi: \n";
        cin >>minim;
        cin >>maxim;
        differ=maxim-minim;
        ran=rand() %differ + minim;
        I_max[i]=ran;
    }
}

float circuitS::get_tres()
{
    float a=0;
    int i;
    for (i=0;i<n;i++)
        a=a+R[i];
    return a;
}

void circuitS::check(float V)
{
    int i;
    float a=0,k;
    for (i=0;i<n;i++)
        a=a+R[i];
    for (i=0;i<n;i++)
    {
        k=V/a;
        if (k>I_max[i])
            cout <<"H "<<i<<" antistasi tha katastrafei. \n";
    }
}

void circuitS::out()
{
    int i;
    for (i=0;i<n;i++)
    {
        cout <<"Antistasi "<<i<<" = "<<R[i];
        cout <<"Megisti entasi "<<i<<" = "<<I_max[i];
    }
}

//---------------------circuitP------------------------
class circuitP
{
    int m;
    float *r,*i_max;
public:
    circuitP(int k);
    circuitP(int k,int ran);
    float get_tres();
    void check(float V);
    void out();
};

circuitP::circuitP(int k)
{
    int i;
    m=k;
    r=(float *)malloc(k*sizeof(float));
    i_max=(float *)malloc(k*sizeof(float));
    for (i=0;i<m;i++)
    {
        cout <<"Dwse timi antistasis: \n";
        cin >>r[i];
        cout <<"Dwse megisti entasi reumatos: \n";
        cin >>i_max[i];
    }
}

circuitP::circuitP(int k,int ran)
{
    int minim,maxim,differ;
    int i;
    m=k;
    r=(float *)malloc(k*sizeof(float));
    i_max=(float *)malloc(k*sizeof(float));
    for (i=0;i<m;i++)
    {
        cout <<"Dwse katwtero kai anwtero orio antistasis: \n";
        cin >>minim;
        cin >>maxim;
        differ=maxim-minim;
        ran=rand() %differ + minim;
        r[i]=ran;
        cout <<"Dwse katwteri kai anwteri megisti entasi: \n";
        cin >>minim;
        cin >>maxim;
        differ=maxim-minim;
        ran=rand() %differ + minim;
        i_max[i]=ran;
    }
}

float circuitP::get_tres()
{
    float a=0;
    int i;
    for (i=0;i<m;i++)
        a=a+(1/r[i]);
    return a;
}

void circuitP::check(float V)
{
    int i;
    float k;
    for (i=0;i<m;i++)
    {
        k=V/r[i];
        if (k>i_max[i])
            cout <<"H "<<i<<" antistasi tha katastrafei. \n";
    }
}

void circuitP::out()
{
    int i;
    for (i=0;i<m;i++)
    {
        cout <<"Antistasi "<<i<<" = "<<r[i];
        cout <<"Megisti entasi "<<i<<" = "<<i_max[i];
    }
}

//---------------------circuit-------------------------
class circuit :public circuitS,public circuitP
{
    float volt;
public:
    circuit(float V,int x,int y);
    circuit(float V,int x,int j,int y,float l);
    circuit(int x,int j,int y,float V);
    circuit(float V,int x,int y,float l);
    float set_tres(int k);
    void check(int k);
};

circuit::circuit(float V,int x,int y):circuitS(x),circuitP(y)
{
    volt=V;
}

circuit::circuit(float V,int x,int j,int y,float l):circuitS(x,j),circuitP(y,l)
{
    volt=V;
}

circuit::circuit(int x,int j,int y,float V):circuitS(x,j),circuitP(y)
{
    volt=V;
}

circuit::circuit(float V,int x,int y,float l):circuitS(x),circuitP(y,l)
{
    volt=V;
}

float circuit::set_tres(int k)
{
    float r1,r2,r;
    r1=circuitS::get_tres();
    r2=circuitP::get_tres();
    if (k=0)
    {
        r=1/(r1) + 1/(r2);
    }else
    {
        r=r1 + r2;
    }
    return r;
}

void circuit::check(int k)
{
    float r1,r2,v1,v2,i;
    r1=circuitS::get_tres();
    r2=circuitP::get_tres();
    if (k=0)
    {
        circuitS::check(volt);
        circuitP::check(volt);
    }else
    {
        i=volt/(r1+r2);
        v1=i*(r1);
        v2=i*(r2);
        circuitS::check(v1);
        circuitS::check(v2);
    }
}

int main()
{
    float v;
    int n,m,r1,r2;
    cout <<"Dwse tasi: \n";
    cin >>v;
    cout <<"Dwse arithmo anistasewn kyklwmatos S: \n";
    cin >>n;
    cout <<"Dwse arithmo anistasewn kyklwmatos P: \n";
    cin >>m;
    circuit c1(v,n,m);
    circuit c2(v,n,r1,m);
    circuit c3(n,m,r2,v);
    circuit c4(v,n,r1,m,r2);
    c1.circuitS::out();
    c1.circuitP::out();
    c2.circuitS::out();
    c2.circuitP::out();
    c3.circuitS::out();
    c3.circuitP::out();
    c4.circuitS::out();
    c4.circuitP::out();
    int k=0;
    c1.check(k);
    c2.check(k);
    c3.check(k);
    c4.check(k);
    k=1;
    c1.check(k);
    c2.check(k);
    c3.check(k);
    c4.check(k);
    return 0;
}
