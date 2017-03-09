/*
*  Author : Konstantinos Keramaris
*  Materials and Production
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//----------------material--------------------
class material
{
    float n,sp;
public:
    material();
    virtual float space();
    void setn(float v);
};

material::material()
{
    cout <<"Dwse posotita kai eidiko varos metallou \n";
    cin >>n;
    cin >>sp;
}

float material::space()
{
    float x;
    x=n/sp;
    return x;
}

void material::setn(float v)
{
    n=n-v*sp;
}
//----------------product1--------------------
class product1 : public material
{
    float r,h;
    int n;
public:
    product1();
    float space();
    int getn();
};

product1::product1()
{
    cout <<"Dwse aktina, ipsos kai arithmo kylindrou \n";
    cin >>r;
    cin >>h;
    cin >>n;
}

float product1::space()
{
    float x;
    x=3.14*r*r*h;
    return x;
}

int product1::getn()
{
    return n;
}
//----------------product2--------------------
class product2 : public material
{
    float a;
    int n;
public:
    product2();
    float space();
    int getn();
};

product2::product2()
{
    cout <<"Dwse pleura kai arithmo kivou \n";
    cin >>a;
    cin >>n;
}

float product2::space()
{
    float x;
    x=a*a*a;
    return x;
}

int product2::getn()
{
    return n;
}
//------------------------------------main---------------------------------
int production (material *p,product1 *p1,product2 *p2);
int main()
{
    material *p=new material;
    product1 *p1=new product1;
    product2 *p2=new product2;
    p=(material *)malloc(5*sizeof(material));
    p1=(product1 *)malloc(5*sizeof(product1));
    p2=(product2 *)malloc(4*sizeof(product2));
    production(p,p1,p2);
    return 0;
}

int production (material *p,product1 *p1,product2 *p2)
{
    int i,k;
    int n=0,j=0;
    int flag;
    float v1,v2;
    for (i=0;i<5;i++)
    {
        v1=p[i].space();
        while ((j>=0)&&(j<5))
        {
            if (n==0)
            {
                n=p1[j].getn();
            }
            v2=p1[j].space();
            for (k=0;k<n;k++)
            {
                if (v1>=v2)
                {
                    v1=v1-v2;
                    p[i].setn(v1);
                    cout <<"Kylindros, Antikeimeno: "<<j<<"Arithmos: "<<k<<"Yliko: "<<i;
                }
                if (v1<v2)
                {
                    flag=1;
                    break;
                }
            }
            if (flag==0)
            {
                j++;
            }
            if (flag==1)
            {
                n=k;
                break;
            }
        }
        while ((j>=5)&&(j<9))
        {
            if (n==0)
            {
                n=p2[j].getn();
                v2=p2[j-5].space();
            }
            for (k=0;k<n;k++)
            {
                if (v1>=v2)
                {
                    v1=v1-v2;
                    p[i].setn(v1);
                    cout <<"Kyvos ,Antikeimeno: "<<j-5<<"Arithmos: "<<k<<"Yliko: "<<i;
                }
                if (v1<v2)
                {
                    flag=1;
                    break;
                }
            }
            if (flag==0)
            {
                j++;
            }
            if (flag==1)
            {
                n=k;
                break;
            }
        }
        if (i==10)
            return 0;
    }
    return 0;
}
